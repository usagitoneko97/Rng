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

void enableGpioG(void){
	//unreset GPIOG
	Rcc->AHB1RSTR &= ~(1<<6);
	//start clock of GPIOG
	Rcc->AHB1ENR |= 1<<6;
}
void enableGpioA(void){
	Rcc->AHB1RSTR &= ~(1);
	Rcc->AHB1ENR |= 1;
}

void enableSysCfg(void){
	Rcc->APB2RSTR &= ~(1 << 14);
	Rcc->APB2ENR |= (1<<14);
}
