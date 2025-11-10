const int sensorpin = A0; 
const int sensorpower = 8; 
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;

int sensor;
 
const int delayTime = 1000;

int wet = 800;
int dry = 500;

void setup(){
 
  pinMode(LED1,OUTPUT); pinMode(LED2,OUTPUT); pinMode(LED3,OUTPUT);
pinMode(sensorpower,OUTPUT);


  Serial.begin(9600);
}

void loop(){

  digitalWrite(sensorpower,HIGH); delay(10);

  sensor = analogRead(sensorpin);

  digitalWrite(sensorpower,LOW);
Serial.println(sensor);

  if(sensor>wet){ 
    digitalWrite(LED1,LOW); 
    digitalWrite(LED2,LOW); 
    digitalWrite(LED3,HIGH);
   
}
else if(sensor<dry){
 
  digitalWrite(LED1,HIGH);
 
digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
}
else{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
}

  delay(delayTime);

}
