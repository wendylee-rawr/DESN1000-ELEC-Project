// Sample code to allow DC motor to switch direction per duty cycle

int directionPin = 9;
int pwmPin = 10;
//boolean to switch direction
bool directionState;
void setup() {
//define pins
pinMode(directionPin, OUTPUT);
pinMode(pwmPin, OUTPUT);
}
void loop() {
//change direction every loop()
directionState = !directionState;
//write a low state to the direction pin (9)
if(directionState == false){
  digitalWrite(directionPin, LOW);
}
//write a high state to the direction pin (9)
else{
  digitalWrite(directionPin, HIGH);
}
//set work duty for the motor
analogWrite(pwmPin, 80);
delay(1000);
//activate brakes!
//set work duty for the motor to 0 (off)
analogWrite(pwmPin, 0);
delay(2000);
}



