

#include "Config.h"
#include <MPULib.h>
#include <Wire.h>
#include <PIDCont.h>
#include <avr/pgmspace.h>


PIDCont PIDroll, PIDpitch, PIDyaw, PIDangleX, PIDangleY;
MPULib MPU;

unsigned long tp;
float angles[2] = {
	0.0, 0.0 };
float gx_aver = 0;
float gy_aver = 0;
float gz_aver = 0;


int setX = 0; //Rate Setpoint for PID
int setY = 0; //Rate Setpoint for PID
int setZ = 0; //Rate Setpoint for PID

volatile int rxVal[6] = { 1500, 1500, 1500, 0, 0, 1000 };

int throttle = MOTOR_ZERO_LEVEL;
byte rateAngleSwitch = 0;

void setup() {
#ifdef DEBUG  
	Serial.begin(115200);
	while (!Serial);
#endif
	MPU.init();
	motorInit();
	leds_init();
	rxInit();
	motorArm();
	PID_init();
	tp = millis(); //for updateSensorVal
}

void loop() {
	updateSensorVal();
	FlightControl();
#ifdef DEBUG
	debugProcess();
#endif
}