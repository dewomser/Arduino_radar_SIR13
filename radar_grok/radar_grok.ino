int pirPin = 7; // deinen Pin eintragen
void setup() {
  pinMode(pirPin, INPUT);          // oder INPUT_PULLUP, je nach Verdrahtung
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(pirPin) == HIGH) {  // oder LOW – je nach PIR
    Serial.println("Bewegung erkannt");
  } else {
    Serial.println("Keine Bewegung");
  }
  delay(200);
}