int LDR_VAL=0;
void setup(){
pinMode(A0, INPUT);
Serial.begin(9600);
pinMode(8, OUTPUT);
}
void loop(){
LDR_VAL = analogRead(A0); 
  Serial.println(LDR_VAL);
    if (LDR_VAL < 500)
digitalWrite(8, HIGH);
    
digitalWrite(8, LOW);
delay(10); 
}

