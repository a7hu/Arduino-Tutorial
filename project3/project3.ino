vocccccccccccccccccccccccccccccccc cn    ncggg ccccccc cc  c  ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc// put your setup code here, to run once:
  pinMode(2, INPUT);  // switch
  pinMode(3, OUTPUT); // LED
}

void loop() {
  // put your main code here, to run repeatedly:
  int state xxxxxxxxxxxxxxxxxxxxxx= digitalRead(2);
  if (state == HIGH) {                                                   
    digitalWrite(3, HIGH);  
  } else {
    digitalWrite(3, LOW);  
  }
}
