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


// Back left motors
int angleBackLeftMax = 15; // Up
int angleBackLeftMin = 90; // Down

// Back right motors
int angleBackRightMax = 165; // Up
int angleBackRightMin = 90; // Down

int delayTime = 200; // Delay between movements


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

    
    // Back left motors - move down
    pwm8 = map(angleBackLeftMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER8, 0, pwm8);
    delay(delayTime);
    pwm9 = map(angleBackLeftMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER9, 0, pwm9);
    delay(delayTime);
    pwm10 = map(angleBackLeftMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER10, 0, pwm10);
    delay(delayTime);
    pwm11 = map(angleBackLeftMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER11, 0, pwm11);
    delay(delayTime);

    // Back right motors - move down
    pwm15 = map(angleBackRightMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER15, 0, pwm15);
    delay(delayTime);
    pwm14 = map(angleBackRightMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER14, 0, pwm14);
    delay(delayTime);
    pwm13 = map(angleBackRightMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER13, 0, pwm13);
    delay(delayTime);
    pwm12 = map(angleBackRightMin, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER12, 0, pwm12);
    delay(delayTime);

    delay(2000);

    // Back left motors - Move Up
    pwm8 = map(angleBackLeftMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER8, 0, pwm8);
    delay(delayTime);
    pwm9 = map(angleBackLeftMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER9, 0, pwm9);
    delay(delayTime);
    pwm10 = map(angleBackLeftMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER10, 0, pwm10);
    delay(delayTime);
    pwm11 = map(angleBackLeftMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER11, 0, pwm11);
    delay(delayTime);

    // Back right motors - Move Up
    pwm15 = map(angleBackRightMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER15, 0, pwm15);
    delay(delayTime);
    pwm14 = map(angleBackRightMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER14, 0, pwm14);
    delay(delayTime);
    pwm13 = map(angleBackRightMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER13, 0, pwm13);
    delay(delayTime);
    pwm12 = map(angleBackRightMax, 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(SER12, 0, pwm12);
    delay(delayTime);

}