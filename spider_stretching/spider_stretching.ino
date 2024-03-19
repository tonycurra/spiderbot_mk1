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


// Servos coupling

// Left legs
// FRONT - BACK
//   0   -  8
//   1   -  9
//   2  -  10
//   3  -  11

// Right legs
// FRONT - BACK
//   4  -  12
//   5  -  13
//   6  -  14
//   7  -  15


// Front Servo angles - organized by legs' rows
// This are for the horizontal movement of the legs

// First row 
// Front left motor 1
int servo_0_angle_forward = 120; // move Forward
int servo_0_angle_backward = 90; // Move Backward
// Front right motor 1
int servo_4_angle_forward = 90;    // Move Forward
int servo_4_angle_backward = 120;   // Move Backward

// Second row
// Front left motor 2
int servo_1_angle_forward = 110; // Move Forward
int servo_1_angle_backward = 80; // Move Backward
// Front right motor 2
int servo_5_angle_forward = 90;    // Move Forward
int servo_5_angle_backward = 120;   // Move Backward

// Third Row
// Back left motor 1
int servo_2_angle_forward = 100; // Move Forward
int servo_2_angle_backward = 70; // Move Backward
// Back right motor 1
int servo_6_angle_forward = 90; // Move Forward
int servo_6_angle_backward = 120; // Move Backward

// Fourth Row
// Back left motor 2
int servo_3_angle_forward = 120; // Move Forward
int servo_3_angle_backward = 90; // Move Backward
// Back right motor 2
int servo_7_angle_forward = 90; // Move Forward
int servo_7_angle_backward = 120; // Move Backward


// Back Servo Angles
// For the vertical movement of the legs

// Back left motors (8 - 9 - 10 - 11)
int left_leg_angle_up = 150; // Up
int left_leg_angle_down = 50; // Down

// Back right motors (12 - 13 - 14 - 15)
int right_leg_angle_up = 50; // Up
int right_leg_angle_down = 150; // Down


int servoDelayTime = 15; // Delay between movements
int delayTime = 100; // Delay for initial setup

void setup() {
  // Serial monitor setup
  Serial.begin(115200);
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
  // Initialize PCA9685
  pca9685.begin();
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);


  // Set initial positions for the servo motors

  // Front servos
  // Servo 0 forward
  pwm0 = map(servo_0_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER0, 0, pwm0);
  delay(delayTime);
  // Servo 1 forward
  pwm1 = map(servo_1_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER1, 0, pwm1);
  delay(delayTime);
  // Servo 2 backward
  pwm2 = map(servo_2_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER2, 0, pwm2);
  delay(delayTime);
  // Servo 3 backward
  pwm3 = map(servo_3_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER3, 0, pwm3);
  delay(delayTime);
  // Servo 4 forward
  pwm4 = map(servo_4_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER4, 0, pwm4);
  delay(delayTime);
  // Servo 5 forward
  pwm5 = map(servo_5_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER5, 0, pwm5);
  delay(delayTime);
  // Servo 6 backward
  pwm6 = map(servo_6_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER6, 0, pwm6);
  delay(delayTime);
  // Servo 7 backward
  pwm7 = map(servo_7_angle_backward, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER7, 0, pwm7);
  delay(delayTime);

  // Back Servos
  // Servo 8 down
  pwm8 = map(left_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER8, 0, pwm8);
  delay(delayTime);
  // Servo 9 down
  pwm9 = map(left_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER9, 0, pwm9);
  delay(delayTime);
  // Servo 10 down
  pwm10 = map(left_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER10, 0, pwm10);
  delay(delayTime);
  // Servo 11 down
  pwm11 = map(left_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER11, 0, pwm11);
  delay(delayTime);
  // Servo 12 down
  pwm12 = map(right_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER12, 0, pwm12);
  delay(delayTime);
  // Servo 13 down
  pwm13 = map(right_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER13, 0, pwm13);
  delay(delayTime);
  // Servo 14 down
  pwm14 = map(right_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER14, 0, pwm14);
  delay(delayTime);
  // Servo 15 down
  pwm15 = map(right_leg_angle_down, 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(SER15, 0, pwm15);
  delay(delayTime);

}




void loop() {
  // Walking algorithm 
  
  // Leg 0 and 5 up
  // servo 8 and 13 up
  for (int i = 0; i < 100; i++) {
    pwm8 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm13 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8); 
    pca9685.setPWM(SER13, 0, pwm13); 

    delay(servoDelayTime);
  }

  // leg 0 and 5 forward
  // servo 0 and 5 forward
  for (int i = 0; i < 30; i++) {
    pwm0 = map(servo_0_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm5 = map(servo_5_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX);  // Right leg

    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0); 
    pca9685.setPWM(SER5, 0, pwm5); 
    delay(servoDelayTime);
  }

  // leg 0 and 5 down
  // servo 8 and 13 down
  for (int i = 0; i < 100; i++) {
    pwm8 = map(left_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm13 = map(right_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8); 
    pca9685.setPWM(SER13, 0, pwm13); 

    delay(servoDelayTime);
  }
  

  // Leg 1 and 4 up
  // servo 9 and 12 up
  for (int i = 0; i < 100; i++) {
    pwm9 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm12 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9); 
    pca9685.setPWM(SER12, 0, pwm12); 

    delay(servoDelayTime);
  }
  // leg 1 and 4 forward
  // servo 1 and 4 forward
  for (int i = 0; i < 30; i++) {
    pwm1 = map(servo_1_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm4 = map(servo_4_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg

    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1); 
    pca9685.setPWM(SER4, 0, pwm4); 
    delay(servoDelayTime);
  }
  // leg 1 and 4 down
  // servo 9 and 12 down
  for (int i = 0; i < 100; i++) {
    pwm9 = map(left_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm12 = map(right_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9); 
    pca9685.setPWM(SER12, 0, pwm12); 

    delay(servoDelayTime);
  }

  // Leg 2 and 7 up
  // servo 10 and 15 up
  for (int i = 0; i < 100; i++) {
    pwm10 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm15 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm10); 
    pca9685.setPWM(SER15, 0, pwm15); 

    delay(servoDelayTime);
  }
  // leg 2 and 7 forward
  // servo 2 and 7 forward
  for (int i = 0; i < 30; i++) {
    pwm2 = map(servo_2_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm7 = map(servo_7_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg

    // Write to PCA9685
    pca9685.setPWM(SER2, 0, pwm2); 
    pca9685.setPWM(SER7, 0, pwm7); 
    delay(servoDelayTime);
  }
  // leg 2 and 7 down
  // servo 10 and 15 down
  for (int i = 0; i < 100; i++) {
    pwm10 = map(left_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm15 = map(right_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER10, 0, pwm10); 
    pca9685.setPWM(SER15, 0, pwm15); 

    delay(servoDelayTime);
  }

  // Leg 3 and 6 up
  // servo 11 and 14 up
  for (int i = 0; i < 100; i++) {
    pwm11 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm14 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER11, 0, pwm11); 
    pca9685.setPWM(SER14, 0, pwm14); 

    delay(servoDelayTime);
  }
  // leg 3 and 6 forward
  // servo 3 and 6 forward
  for (int i = 0; i < 30; i++) {
    pwm3 = map(servo_3_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm6 = map(servo_6_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg

    // Write to PCA9685
    pca9685.setPWM(SER3, 0, pwm3); 
    pca9685.setPWM(SER6, 0, pwm6); 
    delay(servoDelayTime);
  }
  // leg 3 and 6 down
  // servo 11 and 14 down
  for (int i = 0; i < 100; i++) {
    pwm11 = map(left_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm14 = map(right_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER11, 0, pwm11); 
    pca9685.setPWM(SER14, 0, pwm14); 

    delay(servoDelayTime);
  }




  // All legs backward
  for (int i = 0; i < 30; i++) {
    pwm0 = map(servo_0_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm2 = map(servo_2_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm5 = map(servo_5_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX);  // Right leg
    pwm7 = map(servo_7_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX);  // Right leg

    pwm1 = map(servo_1_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm3 = map(servo_3_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm4 = map(servo_4_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm6 = map(servo_6_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1); 
    pca9685.setPWM(SER3, 0, pwm3);
    pca9685.setPWM(SER4, 0, pwm4);
    pca9685.setPWM(SER6, 0, pwm6);

    pca9685.setPWM(SER0, 0, pwm0); 
    pca9685.setPWM(SER2, 0, pwm2);
    pca9685.setPWM(SER5, 0, pwm5);
    pca9685.setPWM(SER7, 0, pwm7); 
    delay(servoDelayTime);
  }
 
}
