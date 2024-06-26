#include <ArduinoBLE.h>

const int LED_PIN = LED_BUILTIN;

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // create service
BLEUnsignedCharCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite); // create switch characteristic

bool ledState = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // initialize LED digital pin as an output.
  pinMode(LED_PIN, OUTPUT);

  // start BLE
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");
    while (1);
  }

  // set the local name peripheral advertises
  BLE.setLocalName("LED Control");

  // add the service and characteristic
  BLE.addService(ledService);
  ledService.addCharacteristic(switchCharacteristic);

  // set the initial value for the characeristic
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("BLE LED Peripheral");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // while the central is still connected to peripheral
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      if (switchCharacteristic.written()) {
        if (switchCharacteristic.value()) {   // any value other than 0
          Serial.println("LED on");
          ledState = true;
        } else {                              // a 0 value
          Serial.println(F("LED off"));
          ledState = false;
        }
      }

      // update the LED pin
      digitalWrite(LED_PIN, ledState);

      delay(10); // delay to not spam the peripheral
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
