#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <avr/io.h>

/*PIN DEFINITIONS*/
#define RST_PORT
#define RST_PIN
/*PIN DEFINITIONS*/

/*RESET PARAMETERS*/
#define DELAY_AFTER_RESET	100 /*Time after reset before considering input, in milliseconds*/
#define RESET_PULSE_WIDTH	1 /*Amount of time to hold the reset pin, in milliseconds*/
#define RESET_LOW	/*Defines the reset active state as low. If undefined, reset active state is high*/
/*RESET PARAMETERS*/

/*TIMED_EDGE*/
/*A rising or falling edge must be sent every so often*/
#ifdef TIMED_EDGE
#define RISING_EDGE	/*Rising edge is considered the edge for timing. If undefined, falling edge is used*/
#define PERIOD	100 /*The maximum time allowed between edges, in milliseconds*/

/*TIMED_EDGE error checking*/
#ifndef PERIOD
#error PERIOD must be defined for TIMED_EDGE
#endif
/*TIMED_EDGE error checking*/

/*TIMED_EDGE_LIMITED*/
/*A rising or falling edge must be sent at regular intervals, but not too frequently*/
#elif defined TIMED_EDGE_LIMITED
#define RISING_EDGE	/*Rising edge is considered the edge for timing. If undefined, falling edge is used*/
#define PERIOD	100 /*The maximum time allowed between edges, in milliseconds*/
#define LIMIT_PERIOD	90 /*The minimum time that has to be between edges, in milliseconds*/

/*TIMED_EDGE_LIMITED error checking*/
#ifndef PERIOD
#error PERIOD must be defined for TIMED_EDGE_LIMITED
#endif

#ifndef LIMIT_PERIOD
#error LIMIT_PERIOD must be defined for TIMED_EDGE_LIMITED
#endif

#if LIMIT_PERIOD >= PERIOD
#error LIMIT_PERIOD must be less than PERIOD
#endif
/*TIMED_EDGE_LIMITED error checking*/

/*TIMED_PULSE*/
/*A pulse of given width must be sent every so often*/
#elif defined TIMED_PULSE
#define RISING_EDGE /*Rising edge is considered the leading edge of the pulse. If undefined, falling edge is used*/
#define PERIOD	100 /*The maximum time allowed between pulses, in milliseconds*/
#define PULSE_WIDTH	10 /*The amount of time the pulse must be held for, in milliseconds*/
#define WIDTH_TOL	2 /*The allowed tolerance in the pulse width time, in milliseconds*/

/*TIMED_PULSE error checking*/
#ifndef PERIOD
#error PERIOD must be defined for TIMED_PULSE
#endif

#if LIMIT_PERIOD >= PERIOD
#error LIMIT_PERIOD must be less than PERIOD
#endif

#ifndef PULSE_WIDTH
#error PULSE_WIDTH must be defined for TIMED_PULSE
#endif

#ifndef WIDTH_TOL
#error WIDTH_TOL must be defined for TIMED_PULSE
#endif

#if WIDTH_TOL >= PULSE_WIDTH
#error WIDTH_TOL exceeds PULSE_WIDTH
#endif

#if (WIDTH_TOL + PULSE_WIDTH) >= PERIOD
#error PULSE_WIDTH exceeds PERIOD
#endif
/*TIMED_PULSE error checking*/

/*TIMED_PULSE_LIMITED*/
/*A pulse of given width must be sent every so often, but not too frequently*/
#elif defined TIMED_PULSE_LIMITED
#define RISING_EDGE /*Rising edge is considered the leading edge of the pulse. If undefined, falling edge is used*/
#define PERIOD	100 /*The maximum time allowed between pulses, in milliseconds*/
#define LIMIT_PERIOD	90 /*The minimum time that has to be between pulses, in milliseconds*/
#define PULSE_WIDTH	10 /*The amount of time the pulse must be held for, in milliseconds*/
#define WIDTH_TOL	2 /*The allowed tolerance in the pulse width time, in milliseconds*/

/*TIMED_PULSE_LIMIT error checking*/
#ifndef PERIOD
#error PERIOD must be defined for TIMED_PULSE
#endif

#ifndef LIMIT_PERIOD
#error LIMIT_PERIOD must be defined for TIMED_PULSE_LIMIT
#endif

#ifndef PULSE_WIDTH
#error PULSE_WIDTH must be defined for TIMED_PULSE_LIMIT
#endif

#ifndef WIDTH_TOL
#error WIDTH_TOL must be defined for TIMED_PULSE_LIMIT
#endif

#if WIDTH_TOL >= PULSE_WIDTH
#error WIDTH_TOL exceeds PERIOD
#endif

#if (WIDTH_TOL + PULSE_WIDTH) >= PERIOD
#error PULSE_WIDTH exceeds PERIOD
#endif
/*TIMED_PULSE error checking*/

#else
#error No operating mode defined
#endif

#endif /* CONFIGURATION_H_ */