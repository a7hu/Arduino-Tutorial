int carGreen = 2;
int carRed = 3;
int carYellow = 4;
int pedRed = 6;
int pedGreen = 7;
int pedSwitch = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(carGreen, OUTPUT); 
  pinMode(carRed, OUTPUT); 
  pinMode(carYellow, OUTPUT); 
  pinMode(pedRed, OUTPUT); 
  pinMode(pedGreen, OUTPUT); 
  pinMode(pedSwitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int wait1 = 5000;
  int wait2 = 3000;
  int wait3 = 1000;

  // The car lights stay green (and the pedestrian lights red) unless a pedestrian is present
  int ped = digitalRead(pedSwitch);
  Serial.println(digitalRead(ped));
  while (ped == LOW) {
    digitalWrite(carGreen, HIGH);
    digitalWrite(pedRed, HIGH);
    ped = digitalRead(pedSwitch);
  }
  if (ped == HIGH) {
    // carGreen off, carYellow on, Wait 3 seconds
    digitalWrite(carGreen, LOW);
    digitalWrite(carYellow, HIGH);
    delay(wait2);
    // carYellow off, carRed on, Wait 1 second
    digitalWrite(carYellow, LOW);
    digitalWrite(carRed, HIGH);
    delay(wait3);
    // pedRed off, pedGreen on, Wait for 5 seconds or more
    digitalWrite(pedRed, LOW);
    digitalWrite(pedGreen, HIGH);
    delay(wait1);
    // Flash pedGreen 10 times, pedGreen off, pedRed on, Wait 1 second
    int flashCount = 0;
    while (flashCount < 10) {
        digitalWrite(pedGreen, LOW);
        delay(400);
        digitalWrite(pedGreen, HIGH); 
        delay(400);
        flashCount = flashCount + 1;
    }
    digitalWrite(pedGreen, LOW);
    digitalWrite(pedRed, HIGH);
    delay(wait3);
    // carYellow on, carRed off, Wait 1 second
    digitalWrite(carYellow, HIGH);
    digitalWrite(carRed, LOW);
    delay(wait3);
    // carGreen on, carYellow off
    digitalWrite(carGreen, HIGH);
    digitalWrite(carYellow, LOW);
  }
}
