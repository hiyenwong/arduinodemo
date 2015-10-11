int a0;
float sensor_val;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
float calc(int analog_val) {
  return (1-((float)analog_val/1024))*100;
}

void alarm_high(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
}

void alarm_mid(){
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);
}
void alarm_low(){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
}

void alarm_error(){
  digitalWrite(13,HIGH);
}

void loop() {
  a0 = analogRead(A0);
  sensor_val = calc(a0);
  Serial.print("{\"""\"} :"); 
  Serial.print(sensor_val);
  Serial.print("\n");
  if(sensor_val <= 0.00){
    alarm_error();
  }else if(sensor_val <= 33.98){
    alarm_high();
  }else if(sensor_val <= 50){
    alarm_mid();
  }else if(sensor_val <= 80) {
    alarm_low();
  }
  
  delay(1000);
}
