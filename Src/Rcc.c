/*
 * Rcc.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */
#include "Rcc.h"

void enableRcc(void){
	Rcc->AHB2RSTR &= ~(1<<6);
	Rcc->AHB2ENR |= 1<<6;
}
