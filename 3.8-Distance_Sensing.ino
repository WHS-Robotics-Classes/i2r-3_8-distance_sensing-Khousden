/*
 */
 
int trigPin = 9;    // Trigger
int echoPin = 8;    // Echo
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(10,OUTPUT);//red
  pinMode(11,OUTPUT);//green
  pinMode(12,OUTPUT);//blue
}
 
void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1;     
 
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 
  delay(250);
  if(cm>= 30){
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }
  else if(cm<30 && cm>=10){
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
    else if(cm<10){
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
    }
  }
  

