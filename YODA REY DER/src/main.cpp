/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Charlie3477                                               */
/*    Created:      8/04/2022                                                 */
/*    Description:  Esta mierda anda para que no gane petro     yes           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor3               motor         3               
// Motor6               motor         6               
// Motor15              motor         15              
// Motor12              motor         12              
// Motor20              motor         20              
// Motor14              motor         14              
// DigitalOutB          digital_out   B               
// Brazotrasero         motor         13              
// Brazodelantero       motor         2               
// Controller1          controller                    
// DigitalOutC          digital_out   C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

 int wheelTravel = 320;
 int trackWidth = 400;
 int wheelBase = 440;
motor_group driveL(Motor15, Motor6, Motor3);
motor_group driveR(Motor12, Motor20, Motor14);
motor_group alldrive(Motor15, Motor6, Motor3,Motor12, Motor20, Motor14);

// -->no util en 3x3 drivetrain myDrivetrain(driveL, driveR, wheelTravel, trackWidth, wheelBase, mm);
float pneumatico_pinza;
float pneumatico_trasero;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 alldrive.setMaxTorque(100,percent);
 alldrive.setVelocity(90,percent);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
 DigitalOutB.set(true);
 alldrive.spinFor(forward,3.675,turns);
 alldrive.setVelocity(30,percent);
 alldrive.spinFor(forward,0.2,turns);
 DigitalOutB.set(false);
 alldrive.setVelocity(100,percent);
 alldrive.spinFor(reverse,2,turns);
 Brazodelantero.spin(forward);
 wait(1,sec);
 Brazodelantero.stop();
 alldrive.setVelocity(50, percent);
 driveL.spinFor(forward,1, turns) && driveR.spinFor(reverse, 1, turns);
 alldrive.spinFor(forward,0.8, turns);
 Brazodelantero.spin(reverse);
 wait(0.8,sec);
 Brazodelantero.stop();
 alldrive.spinFor(reverse, 1, turns);
}

//int Async (){
//Stuff happens here at the same time

//return(0);
//}

//int main (){

//vex::task t( Async );

//other stuff happens

//return(0);
//} 


 
 

  // .........................................................................
  // Insert autonomous user code here.
  // ..........................................................................


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  bool pneumaticovalor=true;
  bool pneumatico2=true;
  Brazodelantero.setVelocity(100,percent);
  Brazodelantero.setMaxTorque(100,percent);
  Brazotrasero.setMaxTorque(100,percent);
  Brazotrasero.setVelocity(100,percent);
  // User control code here, inside the loop
  while (1) {
  
      int leftSpeed  = Controller1.Axis3.position()+Controller1.Axis4.position();
      int rightSpeed = Controller1.Axis3.position()-Controller1.Axis4.position();
       // deadband
      if( abs(leftSpeed)  < 30 ) leftSpeed  = 0;
      if( abs(rightSpeed) < 30 ) rightSpeed = 0;

      // send to motors
      driveL.spin( forward, leftSpeed, percent );
      driveR.spin( forward, rightSpeed, percent );
        // Base

       if (Controller1.ButtonUp.pressing())  {
       DigitalOutB.set(true);
       pneumaticovalor=true;
       }
        else if (Controller1.ButtonLeft.pressing() && pneumaticovalor==true){
        DigitalOutB.set(false);
        pneumaticovalor=false;
        wait(0.5,sec);
        }
        else if (Controller1.ButtonLeft.pressing()&& pneumaticovalor==false){
        DigitalOutB.set(true);
        pneumaticovalor=true;
        wait(0.5,sec);
        }
        //Neumatico 1

        if (Controller1.ButtonX.pressing())  {
        DigitalOutC.set(false);
        pneumatico2=false;
        }
        else if (Controller1.ButtonA.pressing() && pneumatico2==true){
        DigitalOutC.set(false);
        pneumatico2=false;
        wait(0.5,sec);
        }
        else if (Controller1.ButtonA.pressing() && pneumatico2==false){
        DigitalOutC.set(true);
        pneumatico2=true;
        wait(0.5,sec);
        
        //Neumatico 2

        }
         if (Controller1.ButtonR1.pressing()) {
        Brazodelantero.setMaxTorque(100,percent); 
         Brazodelantero.spin(forward);
         Brazodelantero.setStopping(hold);
        }
         else if (Controller1.ButtonR2.pressing()) {
          Brazodelantero.spin(reverse);

        } else { 
          Brazodelantero.stop();
          
        }
       //Brazo delantero
         if (Controller1.ButtonL2.pressing()) {
         Brazotrasero.spin(forward);
         Brazotrasero.setMaxTorque(100,percent);
       } else if (Controller1.ButtonL1.pressing()) {
         Brazotrasero.spin(reverse);
       }  else  {
         Brazotrasero.stop();
         Brazotrasero.setStopping(hold);
        //Brazo trasero 
      }
      wait(20,msec); 
      }  
}

int main()  {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
 

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
} 

