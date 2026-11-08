/* Keeper Wolf DIY BLE starter 1.0.0
 * XIAO nRF52840 / Sense; Seeed mbed-enabled core 2.9.3; ArduinoBLE 2.1.0.
 * Generic BLE advertising only. No KeeperWolf identity, certificates, pairing,
 * cryptographic protocol, protected commands or production firmware sources.
 */
#include <ArduinoBLE.h>

// Use a distinct name for each DIY device. Do not use the KeeperWolf name prefix.
constexpr char DEVICE_NAME[] = "DIY-BLE-001";
constexpr uint16_t ADVERTISING_MS = 500;
constexpr bool PULSE_LED = true;
static_assert(ADVERTISING_MS >= 100 && ADVERTISING_MS <= 10000, "Advertising interval: 100..10000 ms");

// Independent public demo UUIDs, deliberately separate from the KeeperWolf service.
BLEService diyService("6f0c7000-64a6-4a23-9435-b01110d10001");
BLEStringCharacteristic versionValue("6f0c7001-64a6-4a23-9435-b01110d10001", BLERead, 16);
bool ready = false, wasConnected = false, advertising = false;
uint32_t lastAttempt = 0;

void setup() {
  // XIAO RGB LEDs are active-low. No external wiring is needed for this starter.
  pinMode(LED_RED, OUTPUT); pinMode(LED_GREEN, OUTPUT); pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_RED, HIGH); digitalWrite(LED_GREEN, HIGH); digitalWrite(LED_BLUE, HIGH);
  Serial.begin(115200); // Never wait for USB: the sketch also starts without a serial monitor.
  if (!BLE.begin()) {
    digitalWrite(LED_RED, LOW);
    if (Serial) Serial.println("BLE init failed. Check board/core selection and reset.");
    return;
  }
  BLE.setLocalName(DEVICE_NAME);
  BLE.setDeviceName(DEVICE_NAME);
  BLE.setAdvertisedService(diyService);
  diyService.addCharacteristic(versionValue);
  BLE.addService(diyService);
  versionValue.writeValue("DIY-1.0.0");
  // ArduinoBLE uses units of 0.625 ms; connection interval is a different setting.
  BLE.setAdvertisingInterval(uint16_t(uint32_t(ADVERTISING_MS) * 8 / 5));
  advertising = BLE.advertise();
  lastAttempt = millis(); ready = true;
  if (Serial) Serial.println(advertising ? "DIY BLE advertising accepted" : "Advertising pending; retrying");
}

void loop() {
  if (!ready) { delay(10); return; }
  BLE.poll();
  const uint32_t now = millis();
  const bool connected = BLE.connected();
  if (wasConnected && !connected) advertising = false;
  if (!connected && !advertising && uint32_t(now - lastAttempt) >= 2000) {
    advertising = BLE.advertise(); lastAttempt = now;
  }
  wasConnected = connected;
  digitalWrite(LED_GREEN, connected ? LOW : HIGH);
  // LED is a visual heartbeat, not a measurement of radio transmissions.
  digitalWrite(LED_BLUE, !connected && PULSE_LED && (now % 1000 < 40) ? LOW : HIGH);
  delay(5);
}
