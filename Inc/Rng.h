/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef RNG_H_
#define RNG_H_

#include <stdint.h>

#define RNG_BASE_ADDR 	 	0x50060800

#define Rng		((RngReg*)(RNG_BASE_ADDR))

typedef struct RngReg RngReg;
struct RngReg {
	volatile uint32_t CR;
	volatile uint32_t SR;
	volatile uint32_t DR;
};


int getRandomNumber();
int isFaultyRandomSeq(void);
int isAnyError(void);
int isRndNumberAvail();
void generateRandomNumber();




#define RNG_FAULTY_SEQUENCE 	(1<<2)
#define RNG_FAULTY_CLK			(1<<1)
#define RNG_DRDY				(1)

#define RNG_RNGEN				(1<<2)

#endif /* RNG_H_ */
