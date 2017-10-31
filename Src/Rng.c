/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */
#include "Rng.h"



void generateRandomNumber(){
	Rng->CR |= RNG_RNGEN;
}

int isRndNumberAvail(){
	return Rng->SR & RNG_DRDY;
}

/**
 * Find out if RNG has encountered any error
 * return:
 * 		0: if no error
 * 		1: error
 */
int isAnyError(void){
	return Rng->SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLK);
}

int isFaultyRandomSeq(void){
	return Rng->SR & (RNG_FAULTY_SEQUENCE);
}

int getRandomNumber(){
	generateRandomNumber();
	do{


	}while(!isRndNumberAvail());

	return Rng->DR;
}
