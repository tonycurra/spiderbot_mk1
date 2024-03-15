# spiderbot_mk1
Robotic spider prototype

## Videos
[Youtube Videos](https://www.youtube.com/playlist?list=PLxMGwsEIy4YXqzaWbVHlb3hlWHMuYztLT)


## List of materials
To actuate, use 
- [Arduino Nano 33 BLE sense REV 2](https://docs.arduino.cc/hardware/nano-33-ble-sense-rev2/) - or any other microcontroller
- 16x servo motors "MG90S micro servo" or similar servo of the same size
- 1x PCA9685 16-Channel PWM Module 
- Hemp rope or other natural fibers
- screws m2 x 1.9 or the so

## CAD 
Cad files are in the folder CAD/, ready to print with a FDM 3D printer

## Calibration programs
To calibrate the servos and decide max and min angles. There's a program for the servos in the front and one for the servos in the back

## Schematics
TODO - coming soon with a cool picture

## Servo motors Denominations
Servos are named from #0 to #15

### Front servos for the horizzontal movement of the legs
Front servos number (from front to back legs)
- Left: 0, 1, 2, 3
- Right: 4, 5, 6, 7

### Back servos for the vertical movement of the legs
Back servos number
- Left: 8, 9, 10, 11
- Right: 12, 13, 14, 15

### Pairing front and back servos
By pairing the 2 servos (front and back for each leg), the end effector of the leg can move on a surface. The position of end effector of the leg can be controlled with a combination of the position of the 2 servos. 

Left legs servo paring:
FRONT - BACK
  0   -  8
  1   -  9
  2  -  10
  3  -  11

Right legs servo paring:
FRONT - BACK
//   4  -  12
//   5  -  13
//   6  -  14
//   7  -  15


## Servo motors control
here's a guide on how to use the servo (works with arduino as well): 
https://dronebotworkshop.com/esp32-servo/ 

## Photos
![photo_6015086219442110319_y](https://github.com/tonycurra/spiderbot_mk1/assets/99278605/b65da875-a200-4fa4-8df9-bc28b93782ee)
![photo_6015086219442110318_y](https://github.com/tonycurra/spiderbot_mk1/assets/99278605/a719d3fe-3945-4cd7-a7ec-dcc37b5f8aa8)
