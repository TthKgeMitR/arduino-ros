#ifndef PRAMETERS_H
#define PRAMETERS_H

#include <math.h>

/*
 int8_t  =                 -128 ~ 127
uint8_t  =                    0 ~ 255
 int16_t =               -32768 ~ 32767
uint16_t =                    0 ~ 65535
 int32_t =          -2147483648 ~ 2147483647
uint32_t =                    0 ~ 4294967295
 int64_t = -9223372036854775808 ~ 9223372036854775807
uint64_t =                    0 ~ 18446744073709551615
*/

/* baudrate */
const uint32_t baudrate = 115200;

/* motor hard parameters */
const uint8_t motorPin = 2;
//const uint8_t motorPin = 3;

const uint8_t left_motor = 0;
const uint8_t right_motor = 1;

const uint8_t RX = 13; // any pin namber not used
const uint8_t TX = motorPin;

/* motor soft parameters */
/*
const double Rv = 0.3;   // m/s
const double Rw = M_PI;  // rad/s
const double td = 0.150; // distance wheels
const double r  = 0.029; // radius wheel
*/

/* magnet parameters */
const uint8_t magnetPin = 12;

#endif
