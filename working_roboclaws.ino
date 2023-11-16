#include <RoboClaw.h>
// https://resources.basicmicro.com/using-the-roboclaw-arduino-library/

RoboClaw roboclaw(&Serial2, 10000);
#define address_fwd 0x80 // 128
#define address_rwd 0x82 // 130

int increment = 5;
int speed = 0;
bool right = true;

// fwd, m1 = top right
// fwd, m2 = bottom right
// rwd, m1 = bottom left
// rwd, m2 = top left

void setup() {
  roboclaw.begin(38400);
}

void loop() {

  if(right){
    roboclaw.ForwardM1(address_fwd, speed); //start Motor1 forward at half speed
    roboclaw.BackwardM2(address_fwd,speed); //start Motor2 forward at half speed
    roboclaw.BackwardM1(address_rwd, speed); //start Motor1 forward at half speed
    roboclaw.ForwardM2(address_rwd,speed); //start Motor2 forward at half speed
    
  }
  else{
    roboclaw.BackwardM1(address_fwd, speed); //start Motor1 forward at half speed
    roboclaw.ForwardM2(address_fwd,speed); //start Motor2 forward at half speed
    roboclaw.ForwardM1(address_rwd, speed); //start Motor1 forward at half speed
    roboclaw.BackwardM2(address_rwd,speed); //start Motor2 forward at half speed
  }
  // roboclaw.BackwardM2(address,64); //start Motor2 backward at half speed
  delay(1000);

  speed = speed + increment;
  if(speed > 125){
    speed = 0;
    right = !right;
  }
}