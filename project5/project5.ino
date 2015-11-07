void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT); //green
  pinMode(3, OUTPUT); //red
  pinMode(4, OUTPUT); //yellow
}

void loop() {
  // put your main code here, to run repeatedly:
  int green = 2;
  int red = 3;
  int yellow = 4;
  int wait1 = 5000;
  int wait2 = 3000;
  // Turn on red light, Wait 5 seconds
  digitalWrite(red, HIGH);
  delay(wait1);
  // Turn on yellow light, Wait 3 seconds
  digitalWrite(yellow, HIGH);
  delay(wait2);
  // Turn on green light, turn off red and yellow light, Wait 5 seconds
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(wait1);
  // Turn on yellow light, and turn off green light, Wait 3 seconds
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(wait2);
  // Turn off yellow light
  digitalWrite(yellow, LOW);
}
