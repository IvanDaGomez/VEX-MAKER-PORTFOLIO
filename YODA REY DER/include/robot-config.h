using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Motor3;
extern motor Motor6;
extern motor Motor15;
extern motor Motor12;
extern motor Motor20;
extern motor Motor14;
extern digital_out DigitalOutB;
extern motor Brazotrasero;
extern motor Brazodelantero;
extern controller Controller1;
extern digital_out DigitalOutC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );