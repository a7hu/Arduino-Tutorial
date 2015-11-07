void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT); //LED
  Serial.begin(9600);
  while(!Serial) {}
}

void loop() {
  // put your main code here, to run repeatedly:
  int photocell = analogRead(A0);
  //if(Serial.available() == true) {
    Serial.println(photocell);  
  //}
  digitalWrite(6, HIGH);
  delay(photocell);
  digitalWrite(6, LOW);
  delay(photocell);
}
