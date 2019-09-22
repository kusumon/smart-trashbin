#include <Servo.h>

int obstacle = 2; // This is our input pin
int obstacle_stts = HIGH; // HIGH MEANS CLEAR
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(obstacle,INPUT);
  Serial.begin(9600);
  myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  obstacle_stts = digitalRead(obstacle);
  int x = map (obstacle_stts, 0, 1, 100, 0); //for comparing the obstacle_stts with angle degree of servo
  if (obstacle_stts == 0)
  {
    Serial.println("object detected !");
    myservo.write(x);
    delay(500);
    }
    else{
      Serial.println("clear");
      myservo.write(x);
      }
}
