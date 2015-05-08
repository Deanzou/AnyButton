#include <Parse.h>
#include <Bridge.h>

void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);

  // Initialize Bridge (with linux)
  Bridge.begin();

  // Initialize Serial
  Serial.begin(115200);

  // uncomment to wait for a console connection
  // while (!Serial);

  // initialize Parse SDK
  Parse.begin("PARSE_APPLICATION_KEY", "PARSE_CLIENT_ID");

  Serial.println("setup done!");
}

int oldState = LOW;

void loop() {
  // get state of pin 6 (attached to the button)
  int newState = digitalRead(6);

   // check the state to avoid repeat calls
  if (oldState != newState) {

    // if changed to high, we send the request
    if (newState == HIGH) {
      Serial.println("button down");
      digitalWrite(13, HIGH);

      // Send request to parse
      ParseCloudFunction cloudFunction;
      cloudFunction.setFunctionName("orderToiletPaper");
      ParseResponse response = cloudFunction.send();
      response.close();
    }

    // if changed to low we just print some info for debug
    if (newState == LOW) {
      Serial.println("button up");
      digitalWrite(13, LOW);
    }

    // update state
    oldState = newState;
  }
}

