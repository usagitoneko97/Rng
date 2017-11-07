/*
 * SysCfg.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_

#define SYSCFG_BASE_ADDR	0x40013800
#define SysCfg				((SyscfgReg*)(SYSCFG_BASE_ADDR))

typedef struct SyscfgReg SyscfgReg;
struct SyscfgReg{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t Reserved[2];
	volatile uint32_t CMPCR;
};

#define PA0_EXTI_CFG	0
#define PB0_EXTI_CFG	1
#define PC0_EXTI_CFG	2
#define PD0_EXTI_CFG	3
#define PE0_EXTI_CFG	4

#define SET_EXTICR1(x)	(SysCfg->EXTICR1 = x)


#endif /* SYSCFG_H_ */
