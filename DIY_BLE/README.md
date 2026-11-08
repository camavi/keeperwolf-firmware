# Keeper Wolf DIY BLE starter 1.0.0

## English

An independent generic BLE example for personal prototyping with Keeper Wolf.
This is NOT a stripped copy of the production firmware. It contains no proprietary
sources, authentication protocol, secret, certificate, factory signing, USB pairing,
protected control endpoint, motion sensing or battery estimation.

Required: Seeed Studio XIAO nRF52840 or XIAO nRF52840 Sense, USB-C DATA cable,
Arduino IDE, Seeed nRF52 mbed-enabled Boards 2.9.3, ArduinoBLE by Arduino 2.1.0.
The non-mbed core is a different package and is not this example's target.

1. Install the board package using Seeed's guide below and ArduinoBLE 2.1.0 via Library Manager.
2. Open DIY_BLE/DIY_BLE.ino. Keep the folder and sketch names identical.
3. Select XIAO nRF52840 (No Updates), or the matching Sense variant, under the mbed-enabled package.
4. Connect via USB, select the board's port, then compile and upload manually.
5. If desired, change DEVICE_NAME to a unique DIY-BLE-xxx and ADVERTISING_MS (100..10000).
6. In Keeper Wolf on Mac, open Detected, locate your DIY-BLE-001, save it and calibrate
   proximity in your environment. Configure supported generic BLE actions in the app.
7. Disconnect any BLE scanner before using proximity. A GATT connection can interrupt
   advertising. If no device appears, check board/port, power, Bluetooth permission on
   the Mac and any ignored devices. Reset after a red initialization-error LED.

USB power is sufficient; no soldering or battery is required. For battery operation,
follow Seeed's board-specific power documentation. This starter does not measure battery
charge, manage a separate charger, implement deep sleep, or promise battery life.
The Sense IMU is unused; a non-Sense XIAO is sufficient. The enclosure shown on the site
is a visual concept, not a supplied PCB design, printable CAD file or validated dimension drawing.

This generic device has no authenticated KeeperWolf identity. Name, RSSI and UUID are
not proof of identity. Official device status/settings, signed presence and USB pairing
are unavailable. Do not rename it KeeperWolf or substitute the private service UUIDs.
Proximity depends on radio conditions and app configuration; it is not a precise distance measurement.

Blue pulses indicate the sketch is running, not individual radio packets. Green indicates
a BLE connection. Red means BLE initialization failed. Firmware version is readable over
the independent DIY service. No writable GATT commands are exposed.

## Italiano

Esempio autonomo di BLE generico per il fai-da-te. Non è il firmware originale privato:
non contiene codice di autenticazione, chiavi, certificati o funzioni di associazione USB.

Servono XIAO nRF52840 o Sense, cavo USB-C dati, Arduino IDE, core Seeed nRF52
mbed-enabled Boards 2.9.3 e ArduinoBLE 2.1.0. Apri DIY_BLE.ino nella cartella omonima,
seleziona la variante corretta (No Updates), compila e carica manualmente.
Il core Seeed non-mbed è un pacchetto diverso e non è il target di questo esempio.

Alimenta via USB per la prima prova: non servono batteria né saldature. Nell'app Mac apri
Rilevati, salva DIY-BLE-001 e calibra la prossimità nel tuo ambiente. Puoi modificare
DEVICE_NAME e ADVERTISING_MS nel sorgente; per più schede usa nomi DIY distinti.
Le azioni disponibili sono quelle dei BLE generici: niente identità KeeperWolf firmata,
comandi protetti o pairing USB. Non cambiare il nome nel prefisso KeeperWolf.
Chiudi/disconnetti gli scanner BLE prima della prova; la connessione GATT può interrompere
l'advertising. Verifica alimentazione, scheda/porta, permessi Bluetooth e lista Ignorati.

L'IMU Sense non è utilizzata. Nessuna stima batteria, autonomia promessa o deep sleep.
Per la batteria consulta la documentazione di alimentazione della tua scheda. La scocca
sul sito è un concept: non include file CAD/STL, schema PCB o quote costruttive validate.

## Official references / Riferimenti ufficiali

- https://wiki.seeedstudio.com/XIAO_BLE/
- https://wiki.seeedstudio.com/XIAO-BLE-Sense-Bluetooth-Usage/
- https://github.com/arduino-libraries/ArduinoBLE

## Compile (no upload)

arduino-cli compile --fqbn Seeeduino:mbed:xiaonRF52840 DIY_BLE
arduino-cli compile --fqbn Seeeduino:mbed:xiaonRF52840Sense DIY_BLE

Compilation is checked separately from physical radio and app testing. A successful build
is not a claim that the physical board, enclosure, range or battery life has been validated.
