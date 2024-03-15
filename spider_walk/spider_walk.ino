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
int left_leg_angle_up = 130; // Up
int left_leg_angle_down = 10; // Down

// Back right motors (12 - 13 - 14 - 15)
int right_leg_angle_up = 50; // Up
int right_leg_angle_down = 170; // Down


int servoDelayTime = 30; // Delay between movements
int delayTime = 200; // Delay for initial setup

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
  // Leg group 1 - Legs 0 - 2 - 5 - 7
    // forward - backward: Servo 0 - 2 - 5 - 7 
    // up - down: Servo 8 - 10 - 13 - 15
  // Leg group 2 - Legs 1 - 3 - 4 - 6
    // forward - backward: Servo 1 - 3 - 4 - 6
    // up - down: Servo 9 - 11 - 12 - 14
  // The walking algorithm is divided in 8 steps
    // Leg group 1 up 
    // Leg group 2 backward
    // Leg group 1 forward
    // Leg group 1 down
    // Leg group 2 up
    // Leg group 1 backward
    // Leg group 2 forward
    // Leg group 2 down

  // Leg group 1 up - Legs 0 - 2 - 5 - 7
  // Servo up 8 - 10 - 13 - 15
  for (int i = 0; i < 120; i++) {
    pwm8 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm10 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm13 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm15 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8); 
    pca9685.setPWM(SER10, 0, pwm10);
    pca9685.setPWM(SER13, 0, pwm13); 
    pca9685.setPWM(SER15, 0, pwm15);

    delay(servoDelayTime);
  }

  // Leg group 2 backward - Legs 1 - 3 - 4 - 6
  // Servo backward 1 - 3 - 4 - 6
  for (int i = 0; i < 30; i++) {
    pwm1 = map(servo_1_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm3 = map(servo_3_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm4 = map(servo_4_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm6 = map(servo_6_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1); 
    pca9685.setPWM(SER3, 0, pwm3);
    pca9685.setPWM(SER4, 0, pwm4);
    pca9685.setPWM(SER6, 0, pwm6);
    delay(servoDelayTime);
  }

  // Leg group 1 forward - Legs 0 - 2 - 5 - 7
  // Servo forward 0 - 2 - 5 - 7
  for (int i = 0; i < 30; i++) {
    pwm0 = map(servo_0_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm2 = map(servo_2_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm5 = map(servo_5_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm7 = map(servo_7_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0); 
    pca9685.setPWM(SER2, 0, pwm2);
    pca9685.setPWM(SER5, 0, pwm5);
    pca9685.setPWM(SER7, 0, pwm7);
    delay(servoDelayTime);
  }

  // Leg group 1 down - Legs 0 - 2 - 5 - 7
  // Servo down 8 - 10 - 13 - 15
  for (int i = 0; i < 120; i++) {
    pwm8 = map(left_leg_angle_up - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm10 = map(left_leg_angle_up - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm13 = map(right_leg_angle_up + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm15 = map(right_leg_angle_up + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER8, 0, pwm8); 
    pca9685.setPWM(SER10, 0, pwm10);
    pca9685.setPWM(SER13, 0, pwm13); 
    pca9685.setPWM(SER15, 0, pwm15);
    delay(servoDelayTime);
  }

  // Leg group 2 up - Legs 1 - 3 - 4 - 6
  // Servo up 9 - 11 - 12 - 14
  for (int i = 0; i < 120; i++) {
    pwm9 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm11 = map(left_leg_angle_down + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm12 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm14 = map(right_leg_angle_down - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9); 
    pca9685.setPWM(SER11, 0, pwm11);
    pca9685.setPWM(SER12, 0, pwm12); 
    pca9685.setPWM(SER14, 0, pwm14);
    delay(servoDelayTime);
  }

  // Leg group 1 backward - Legs 0 - 2 - 5 - 7
  // Servo backward 0 - 2 - 5 - 7
  for (int i = 0; i < 30; i++) {
    pwm0 = map(servo_0_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm2 = map(servo_2_angle_forward - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm5 = map(servo_5_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX);  // Right leg
    pwm7 = map(servo_7_angle_forward + i, 0, 180, SERVOMIN, SERVOMAX);  // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER0, 0, pwm0); 
    pca9685.setPWM(SER2, 0, pwm2);
    pca9685.setPWM(SER5, 0, pwm5);
    pca9685.setPWM(SER7, 0, pwm7); 
    delay(servoDelayTime);
  }

  // Leg group 2 forward - Legs 1 - 3 - 4 - 6
  // Servo forward 1 - 3 - 4 - 6
  for (int i = 0; i < 30; i++) {
    pwm1 = map(servo_1_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm3 = map(servo_3_angle_backward + i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm4 = map(servo_4_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm6 = map(servo_6_angle_backward - i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER1, 0, pwm1); 
    pca9685.setPWM(SER3, 0, pwm3);
    pca9685.setPWM(SER4, 0, pwm4);
    pca9685.setPWM(SER6, 0, pwm6);
    delay(servoDelayTime);
  }

  // Leg group 2 down - Legs 1 - 3 - 4 - 6
  // Servo down 9 - 11 - 12 - 14
  for (int i = 0; i < 120; i++) {
    pwm9 = map(left_leg_angle_up - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm11 = map(left_leg_angle_up - i, 0, 180, SERVOMIN, SERVOMAX); // Left leg
    pwm12 = map(right_leg_angle_up + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    pwm14 = map(right_leg_angle_up + i, 0, 180, SERVOMIN, SERVOMAX); // Right leg
    // Write to PCA9685
    pca9685.setPWM(SER9, 0, pwm9); 
    pca9685.setPWM(SER11, 0, pwm11);
    pca9685.setPWM(SER12, 0, pwm12); 
    pca9685.setPWM(SER14, 0, pwm14);
    delay(servoDelayTime);
  }
  
}
