#include <stdint.h>

#ifndef FLYWHEEL_LIB_H
#define FLYWHEEL_LIB_H

extern int flywheelAngle;
extern int flywheelSpeed;

void initFlywheel(void);

void handleEdgeValues(void);

uint8_t checkDirectionToggle(void);

void spinFlywheel(int speed);

#endif
