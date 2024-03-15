/*
  ESP32 PCA9685 Servo Control
  esp32-pca9685.ino
  Driving multiple servo motors with ESP32 and PCA9685 PWM module
  Use I2C Bus

  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// Include Wire Library for I2C
#include <Wire.h>

// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width

#define SERVOMIN  110  // Minimum value
#define SERVOMAX  500  // Maximum value

// Define servo motor connections (expand as required)

// Servos for Horizzontal movement of the leg
// Left Leg
#define SER0  0 
#define SER1  1 
#define SER2  2  
#define SER3  3  
// Right leg
#define SER4  4
#define SER5  5
#define SER6  6
#define SER7  7

// Servos for Vertical movement of the leg
// Left Leg
#define SER8  8
#define SER9  9
#define SER10 10
#define SER11 11
// Right leg
#define SER12 12
#define SER13 13
#define SER14 14
#define SER15 15


// Variables for Servo Motor positions (expand as required)
int pwm0;
int pwm1;
int pwm2;
int pwm3;

int pwm4;
int pwm5;
int pwm6;
int pwm7;

int pwm8;
int pwm9;
int pwm10;
int pwm11;

int pwm12;
int pwm13;
int pwm14;
int pwm15;

// motors denomination in order from front to back
// Front 1 - servo 0 and 4
// Front 2 - servo 1 and 5
// Back 1 - servo 2 and 6
// Back 2 - servo 3 and 7

// First row
// Front left motor 1
int angleFrontLeft1Max = 130; // Forward
int angleFrontLeft1Min = 100; // Back
// Front right motor 1
int angleFrontRight1Max = 80;    // Forward
int angleFrontRight1Min = 110;   // Back

// Second row
// Front left motor 2
int angleFrontLeft2Max = 120; // Forward
int angleFrontLeft2Min = 80; // Back
// Front right motor 2
int angleFrontRight2Max = 90;    // Forward
int angleFrontRight2Min = 130;   // Back

// Third Row
// Back left motor 1
int angleBackLeft1Max = 100; // Up - OK
int angleBackLeft1Min = 70; // Down
// Back right motor 1
int angleBackRight1Max = 90; // Up - OK
int angleBackRight1Min = 120; // Down

// Fourth Row
// Back left motor 2
int angleBackLeft2Max = 120; // Up
int angleBackLeft2Min = 90; // Down
// Back right motor 2
int angleBackRight2Max = 90; // Up
int angleBackRight2Min = 120; // Down

int delayTime = 500; // Delay between movements


void setup() {
  // Serial monitor setup
  Serial.begin(115200);
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
  // Initialize PCA9685
  pca9685.begin();
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);
}

void loop() {

    // All in Front 
    pwm0 = map(angleFrontLeft1Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER0, 0, pwm0);
    delay(delayTime);
    pwm4 = map(angleFrontRight1Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER4, 0, pwm4);
    delay(delayTime);

    pwm1 = map(angleFrontLeft2Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER1, 0, pwm1);
    delay(delayTime);
    pwm5 = map(angleFrontRight2Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER5, 0, pwm5);
    delay(delayTime);

    pwm2 = map(angleBackLeft1Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER2, 0, pwm2);
    delay(delayTime);
    pwm6 = map(angleBackRight1Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER6, 0, pwm6);
    delay(delayTime);

    pwm3 = map(angleBackLeft2Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER3, 0, pwm3);
    delay(delayTime);
    pwm7 = map(angleBackRight2Max, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER7, 0, pwm7);
    delay(delayTime);


    // All in the back
    pwm0 = map(angleFrontLeft1Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER0, 0, pwm0);
    delay(delayTime);
    pwm4 = map(angleFrontRight1Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER4, 0, pwm4);
    delay(delayTime);
    
    pwm1 = map(angleFrontLeft2Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER1, 0, pwm1);
    delay(delayTime);    
    pwm5 = map(angleFrontRight2Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER5, 0, pwm5);
    delay(delayTime);

    pwm2 = map(angleBackLeft1Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER2, 0, pwm2);
    delay(delayTime);    
    pwm6 = map(angleBackRight1Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER6, 0, pwm6);
    delay(delayTime);

    pwm3 = map(angleBackLeft2Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER3, 0, pwm3);
    delay(delayTime);    
    pwm7 = map(angleBackRight2Min, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER7, 0, pwm7);
    delay(delayTime);
    
    
}