/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\zephy                                            */
/*    Created:      Wed Jan 01 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

int main() {

  while(1) {
    r.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
    l.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    if(Controller1.ButtonR2.pressing()){
      intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }else if (Controller1.ButtonL2.pressing()) {
      intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }else {
      intake.stop();
    }
    if (Controller1.ButtonUp.pressing()) {
      Lift.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }else if (Controller1.ButtonDown.pressing()) {
      Lift.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }else {
      Lift.stop();
    }
    if (Controller1.ButtonL1.pressing()) {
      Tilt.spin(directionType::rev, 100, percentUnits::pct);
    }else if (Controller1.ButtonR1.pressing()) {
      Tilt.spin(directionType::fwd, 100, percentUnits::pct);
    }else {
      Tilt.stop();
    }

    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
  }
}
