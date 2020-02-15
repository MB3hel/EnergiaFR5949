/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions standalone LFXT msp430fr5949
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Stefan Sch
  *
  ***********************************************************************
  Derived from:
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif


// Not3: pin numbers coorespond to package pin numbers (top left = 1 = PJ.4, Top right = 38 = AVSS, etc)


#if defined(__MSP430_HAS_EUSCI_B0__)
static const uint8_t SS      = 26;   /* P3.4 */
static const uint8_t SCK     = 25;   /* P2.2 */
static const uint8_t MOSI    = 30;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 31;  /* P1.7 aka SOMI */
static const uint8_t TWISCL1  = 27;   /* P3.5 SW I2C */
static const uint8_t TWISDA1  = 28;  /* P3.6 SW I2C */
static const uint8_t TWISDA0  = 30;  /* P1.6 UCB0 */
static const uint8_t TWISCL0  = 31;  /* P1.7 UCB0 */
#define TWISDA0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISDA1_SET_MODE  (INPUT_PULLUP)
#define TWISCL1_SET_MODE  (INPUT_PULLUP)
#define SPISCK_SET_MODE  (PORT_SELECTION1)
#define SPIMOSI_SET_MODE (PORT_SELECTION1)
#define SPIMISO_SET_MODE (PORT_SELECTION1)
/* Define the default I2C settings */
#define DEFAULT_I2C -1 /* indicates SW I2C on pseudo module 1 */
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE
#endif

#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
static const uint8_t DEBUG_UARTRXD = 24;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t DEBUG_UARTTXD = 23;  /* Transmit Data (TXD) at P2.0 */
static const uint8_t AUX_UARTRXD = 20;     /* Receive  Data (RXD) at P2.6 */
static const uint8_t AUX_UARTTXD = 19;     /* Transmit Data (TXD) at P2.5 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define AUX_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define AUX_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x00
#define AUX_UART_MODULE_OFFSET 0x20
#define SERIAL1_AVAILABLE 1
#endif

static const uint8_t TEMPSENSOR = 128 + 30; // depends on chip

//
// Pin names based on the analog numbers defined in TI's pinout (ex. P3.0/A12/C12 is A12 and digital pin # 8 b/c it is the 8th pin of the package)
//

static const uint8_t A0  = 5;
static const uint8_t A1  = 6;
static const uint8_t A2  = 7;
static const uint8_t A3  = 12;
static const uint8_t A4  = 13;
static const uint8_t A5  = 14;
static const uint8_t A6  = 36;
static const uint8_t A7  = 37;
// static const uint8_t A8  = ;
// static const uint8_t A9  = 24; 
// static const uint8_t A10 = 128 + 10;
// static const uint8_t A11  = 5;
static const uint8_t A12  = 8; 
static const uint8_t A13  = 9;
static const uint8_t A14  = 10;
static const uint8_t A15  = 11;

//
// Pin names based on the package pin numbers
//

static const uint8_t P1_0 = 5;
static const uint8_t P1_1 = 6;
static const uint8_t P1_2 = 7;
static const uint8_t P1_3 = 12;
static const uint8_t P1_4 = 13;
static const uint8_t P1_5 = 14;
static const uint8_t P1_6 = 30;
static const uint8_t P1_7 = 31;

static const uint8_t P2_0 = 23;
static const uint8_t P2_1 = 24;
static const uint8_t P2_2 = 25;
static const uint8_t P2_3 = 36;
static const uint8_t P2_4 = 37;
static const uint8_t P2_5 = 19;
static const uint8_t P2_6 = 20;
static const uint8_t P2_7 = 35;

static const uint8_t P3_0 = 8;
static const uint8_t P3_1 = 9;
static const uint8_t P3_2 = 10;
static const uint8_t P3_3 = 11;
static const uint8_t P3_4 = 26;
static const uint8_t P3_5 = 27;
static const uint8_t P3_6 = 28;
static const uint8_t P3_7 = 29;

// static const uint8_t P4_0 = ;
// static const uint8_t P4_1 = ;
// static const uint8_t P4_2 = ;
// static const uint8_t P4_3 = ;
static const uint8_t P4_4 = 32;
// static const uint8_t P4_5 = ;
// static const uint8_t P4_6 = ;
// static const uint8_t P4_7 = ;

static const uint8_t PJ_0 = 15;
static const uint8_t PJ_1 = 16;
static const uint8_t PJ_2 = 17;
static const uint8_t PJ_3 = 18;
static const uint8_t PJ_4 = 1;
static const uint8_t PJ_5 = 2;
//static const uint8_t PJ_6 = ;
//static const uint8_t PJ_7 = ;

#ifdef ARDUINO_MAIN

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4IN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJIN,
#endif
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4OUT,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJOUT,
#endif
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4DIR,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJDIR,
#endif
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4REN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJREN,
#endif
};

const uint16_t port_to_sel0[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL0,
	(uint16_t) &P2SEL0,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL0,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL0,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL0,
#endif
};

const uint16_t port_to_sel1[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL1,
	(uint16_t) &P2SEL1,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL1,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL1,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL1,
#endif
};

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,  /*  0 - pin count starts at 1 */
	NOT_ON_TIMER,  /*  1 - PJ.4 */
	NOT_ON_TIMER,  /*  2 - PJ.5 */
	NOT_ON_TIMER,  /*  3 - AVSS */
	NOT_ON_TIMER,  /*  4 - AVCC */
	T0A1,          /*  5 - P1.0 */
	T0A2,          /*  6 - P1.1 */
	T1A1,          /*  7 - P1.2 */
	NOT_ON_TIMER,  /*  8 - P3.0 */
	NOT_ON_TIMER,  /*  9 - P3.1 */
	NOT_ON_TIMER,  /* 10 - P3.2 */
	NOT_ON_TIMER,  /* 11 - P3.3 */
	T1A2,          /* 12 - P1.3 */
	T0B1,          /* 13 - P1.4 */
	T0B2,          /* 14 - P1.5 */
	NOT_ON_TIMER,  /* 15 - PJ.0 */
	NOT_ON_TIMER,  /* 16 - PJ.1 */
	NOT_ON_TIMER,  /* 17 - PJ.2 */
	NOT_ON_TIMER,  /* 18 - PJ.3 */
	T0B0,          /* 19 - P2.5 */
	T0B1,          /* 20 - P2.6 */
	
	NOT_ON_TIMER,  /* 21 - TEST */
	NOT_ON_TIMER,  /* 22 - RST  */
	T0B6,          /* 23 - P2.0 */
	T0B0,          /* 24 - P2.1 */
	T0B2,          /* 25 - P2.2 */
	T0B3,          /* 26 - P3.4 */
	T0B4,          /* 27 - P3.5 */
	T0B5,          /* 28 - P3.6 */
	T0B6,          /* 29 - P3.7 */
	T0B3,          /* 30 - P1.6 */
	T0B4,          /* 31 - P1.7 */
	T0B5,          /* 32 - P4.4 */
	NOT_ON_TIMER,  /* 33 - DVSS */
	NOT_ON_TIMER,  /* 34 - DVCC */
	NOT_ON_TIMER,  /* 35 - P2.7 */
	T0A0,          /* 36 - P2.3 */
	T1A0,          /* 37 - P2.4 */
	NOT_ON_TIMER,  /* 38 - AVSS */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,     /*  0 - pin count starts at 1 */
	PJ,            /*  1 - PJ.4 */
	PJ,            /*  2 - PJ.5 */
	NOT_A_PIN,     /*  3 - AVSS */
	NOT_A_PIN,     /*  4 - AVCC */
	P1,            /*  5 - P1.0 */
	P1,            /*  6 - P1.1 */
	P1,            /*  7 - P1.2 */
	P3,            /*  8 - P3.0 */
	P3,            /*  9 - P3.1 */
	P3,            /* 10 - P3.2 */
	P3,            /* 11 - P3.3 */
	P1,            /* 12 - P1.3 */
	P1,            /* 13 - P1.4 */
	P1,            /* 14 - P1.5 */
	PJ,            /* 15 - PJ.0 */
	PJ,            /* 16 - PJ.1 */
	PJ,            /* 17 - PJ.2 */
	PJ,            /* 18 - PJ.3 */
	P2,            /* 19 - P2.5 */
	P2,            /* 20 - P2.6 */
	
	NOT_A_PIN,     /* 21 - TEST */
	NOT_A_PIN,     /* 22 - RST  */
	P2,            /* 23 - P2.0 */
	P2,            /* 24 - P2.1 */
	P2,            /* 25 - P2.2 */
	P3,            /* 26 - P3.4 */
	P3,            /* 27 - P3.5 */
	P3,            /* 28 - P3.6 */
	P3,            /* 29 - P3.7 */
	P1,            /* 30 - P1.6 */
	P1,            /* 31 - P1.7 */
	P4,            /* 32 - P4.4 */
	NOT_A_PIN,     /* 33 - DVSS */
	NOT_A_PIN,     /* 34 - DVCC */
	P2,            /* 35 - P2.7 */
	P2,            /* 36 - P2.3 */
	P2,            /* 37 - P2.4 */
	NOT_A_PIN,     /* 38 - AVSS */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,     /*  0 - pin count starts at 1 */
	BV(4),         /*  1 - PJ.4 */
	BV(5),         /*  2 - PJ.5 */
	NOT_A_PIN,     /*  3 - AVSS */
	NOT_A_PIN,     /*  4 - AVCC */
	BV(0),         /*  5 - P1.0 */
	BV(1),         /*  6 - P1.1 */
	BV(2),         /*  7 - P1.2 */
	BV(0),         /*  8 - P3.0 */
	BV(1),         /*  9 - P3.1 */
	BV(2),         /* 10 - P3.2 */
	BV(3),         /* 11 - P3.3 */
	BV(3),         /* 12 - P1.3 */
	BV(4),         /* 13 - P1.4 */
	BV(5),         /* 14 - P1.5 */
	BV(0),         /* 15 - PJ.0 */
	BV(1),         /* 16 - PJ.1 */
	BV(2),         /* 17 - PJ.2 */
	BV(3),         /* 18 - PJ.3 */
	BV(5),         /* 19 - P2.5 */
	BV(6),         /* 20 - P2.6 */
	
	NOT_A_PIN,     /* 21 - TEST */
	NOT_A_PIN,     /* 22 - RST  */
	BV(0),         /* 23 - P2.0 */
	BV(1),         /* 24 - P2.1 */
	BV(2),         /* 25 - P2.2 */
	BV(4),         /* 26 - P3.4 */
	BV(5),         /* 27 - P3.5 */
	BV(6),         /* 28 - P3.6 */
	BV(7),         /* 29 - P3.7 */
	BV(6),         /* 30 - P1.6 */
	BV(7),         /* 31 - P1.7 */
	BV(4),         /* 32 - P4.4 */
	NOT_A_PIN,     /* 33 - DVSS */
	NOT_A_PIN,     /* 34 - DVCC */
	BV(7),         /* 35 - P2.7 */
	BV(3),         /* 36 - P2.3 */
	BV(4),         /* 37 - P2.4 */
	NOT_A_PIN,     /* 38 - AVSS */
};

const uint32_t digital_pin_to_analog_in[] = {
    NOT_ON_ADC,    /*  0 - pin count starts at 1 */
	NOT_ON_ADC,    /*  1 - PJ.4 */
	NOT_ON_ADC,    /*  2 - PJ.5 */
	NOT_ON_ADC,    /*  3 - AVSS */
	NOT_ON_ADC,    /*  4 - AVCC */
	0,             /*  5 - P1.0 = A0 */
	1,             /*  6 - P1.1 = A1 */
	2,             /*  7 - P1.2 = A2 */
	12,            /*  8 - P3.0 = A12 */
	13,            /*  9 - P3.1 = A13 */
	14,            /* 10 - P3.2 = A14 */
	15,            /* 11 - P3.3 = A15 */
	3,             /* 12 - P1.3 = A3 */
	4,             /* 13 - P1.4 = A4 */
	5,             /* 14 - P1.5 = A5 */
	NOT_ON_ADC,    /* 15 - PJ.0 */
	NOT_ON_ADC,    /* 16 - PJ.1 */
	NOT_ON_ADC,    /* 17 - PJ.2 */
	NOT_ON_ADC,    /* 18 - PJ.3 */
	NOT_ON_ADC,    /* 19 - P2.5 */
	NOT_ON_ADC,    /* 20 - P2.6 */
	
	NOT_ON_ADC,    /* 21 - TEST */
	NOT_ON_ADC,    /* 22 - RST  */
	NOT_ON_ADC,    /* 23 - P2.0 */
	NOT_ON_ADC,    /* 24 - P2.1 */
	NOT_ON_ADC,    /* 25 - P2.2 */
	NOT_ON_ADC,    /* 26 - P3.4 */
	NOT_ON_ADC,    /* 27 - P3.5 */
	NOT_ON_ADC,    /* 28 - P3.6 */
	NOT_ON_ADC,    /* 29 - P3.7 */
	NOT_ON_ADC,    /* 30 - P1.6 */
	NOT_ON_ADC,    /* 31 - P1.7 */
	NOT_ON_ADC,    /* 32 - P4.4 */
	NOT_ON_ADC,    /* 33 - DVSS */
	NOT_ON_ADC,    /* 34 - DVCC */
	NOT_ON_ADC,    /* 35 - P2.7 */
	6,             /* 36 - P2.3 = A6 */
	7,             /* 37 - P2.4 = A7 */
	NOT_ON_ADC,    /* 38 - AVSS */
        
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Energia_h

