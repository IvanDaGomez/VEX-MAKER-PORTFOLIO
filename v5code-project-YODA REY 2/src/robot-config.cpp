#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Motor3 = motor(PORT3, ratio18_1, false);
motor Motor6 = motor(PORT6, ratio18_1, false);
motor Motor15 = motor(PORT15, ratio18_1, false);
motor Motor12 = motor(PORT12, ratio18_1, true);
motor Motor20 = motor(PORT20, ratio18_1, true);
motor Motor14 = motor(PORT14, ratio18_1, true);
digital_out DigitalOutB = digital_out(Brain.ThreeWirePort.B);
motor Brazotrasero = motor(PORT13, ratio36_1, false);
motor Brazodelantero = motor(PORT2, ratio36_1, false);
controller Controller1 = controller(primary);
digital_out DigitalOutC = digital_out(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}