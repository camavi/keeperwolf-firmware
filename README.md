# Keeper Wolf — Public DIY BLE firmware

Independent starter firmware for XIAO nRF52840 and XIAO nRF52840 Sense.
This device uses the generic BLE workflow in the Keeper Wolf Mac app.

## Start / Inizia

Open `DIY_BLE/DIY_BLE.ino` in Arduino IDE. See [English and Italian instructions](DIY_BLE/README.md).
Use Seeed nRF52 mbed-enabled Boards 2.9.3 and ArduinoBLE 2.1.0.
No private KeeperWolf sources, keys, certificates, signing protocol or USB pairing are included.

The package compiles for both board variants. Physical advertising and app behavior still
need validation on a real board. No upload is performed by the packaging script.

## Compile

```sh
arduino-cli compile --fqbn Seeeduino:mbed:xiaonRF52840 DIY_BLE
arduino-cli compile --fqbn Seeeduino:mbed:xiaonRF52840Sense DIY_BLE
```

## Website download

The website distributes a source archive, generated only from the explicit three-file
allowlist. Other repository files are never added to that archive.

```sh
python3 scripts/package.py --output dist/keeperwolf-diy-ble-1.0.0.zip
```

To update the local website, pass the destination ZIP path under its
`public/downloads/firmware/` directory. Commit the generated artifact in the website
repository and the source changes here. If the version changes, also update the website
filename, route, translations and tests.

Il sorgente pubblico viene mantenuto qui. Il sito conserva solo lo ZIP generato.
Il repository privato del firmware originale resta separato.
