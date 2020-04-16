/*
  SerialPortEcho - replies with an echo to the text sent by the serial port. 
  It switches between lowercase to lowercase in the answer.
  It blinks with a led while there is no traffic on the port.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial && (Serial.available() > 0)) {
    String text = readText();
    Serial.print(text);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
    delay(1000);   // wait for a second
  }
}

String readText() {
  String text = "";
  while (Serial.available()) {
    char character = Serial.read(); //Read byte
    String part = String(character);
    if (isUpperCase(character)) {
      part.toLowerCase();
    } else if (isLowerCase(character)) {
      part.toUpperCase();
    }
    text += part; //Add char to string
  }
  return text;
}
