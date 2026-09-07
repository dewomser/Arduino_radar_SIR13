const int ifPin = A0;          // IF-Ausgang an Analog-Pin A0
const int threshold = 30;      // Empfindlichkeit (anpassen: 15–50)
int baseline = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("SIR13 5.8 GHz Radar bereit...");
  
  // Baseline (Ruhewert) ermitteln
  long sum = 0;
  for (int i = 0; i < 50; i++) {
    sum += analogRead(ifPin);
    delay(10);
  }
  baseline = sum / 50;
  Serial.print("Baseline: ");
  Serial.println(baseline);
  delay(1000);
}

void loop() {
  int value = analogRead(ifPin);
  int diff = abs(value - baseline);

  if (diff > threshold) {
   // Serial.print("  Diff: ");
    Serial.println(diff);
   // Serial.print("  Rohwert: ");
   // Serial.println(value);
  }

  // Baseline langsam nachführen (gegen Drift)
  baseline = (baseline * 19 + value) / 20;

  delay(200);
}