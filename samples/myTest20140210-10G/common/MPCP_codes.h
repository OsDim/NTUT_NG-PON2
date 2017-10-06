/*
 * MPCP_codes.h
 *
 *  Created on: 2014/3/19
 *      Author: AJay
 */


#ifndef MPCP_CODES
#define MPCP_CODES

#include <inttypes.h>

// Maximum transition unit
//const uint32_t MTU = 78125 * 0.95 = 74218 ;
const uint32_t MTU = 190000 - 64; //byte. MTW here, don't ask why is MTU 32ONU is 750000 , 128ONU is 190000(2ms) 47500(0.5ms)
const uint32_t MTU_low = 6000-64;
const uint32_t MTU_high = 80000-64;
const uint32_t MTU_all = 20000-64 ;
//const uint32_t MTU = 50000 - 64;
//const uint32_t MTU = 65000-64;//15500;  // 2ms for 16 ONUs.. 15000 (not include Control message)
const uint32_t MAX_FRAME_LEN=1518, MIN_FRAME_LEN=64;
// MPCP TYPE AND CODES

#define MPCP_TYPE 10

#define TIMEOUT_TYPE 168    // make you rich

#define MPCP_GATE       2
#define MPCP_REPORT     3
#define MPCP_REGREQ     4
#define MPCP_REGISTER   5
#define MPCP_DISCOVER   7
#define MPCP_REGACK     6       // NOT USE

// POWER SAVING MODE
#define ACTIVE     20
#define DOZE       21
#define SLEEP      22

#define SLEEPTIME  20
#define DOZETIME   30

// timer change
//#define SLEEPTIME  2
//#define DOZETIME   3

//const uint8_t TX_SLEEP    =    0x01;
//const uint8_t TRX_SLEEP   =    0x02;

#endif
