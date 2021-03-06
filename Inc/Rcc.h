/*
 * Rcc.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#include <stdint.h>
#ifndef RCC_H_
#define RCC_H_

#define RCC_BASE_ADDR	0x40023800
#define Rcc				((RccReg*)(RCC_BASE_ADDR))

typedef struct RccReg RccReg;
struct RccReg{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED15;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED1;
	volatile uint32_t RESERVED2;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED3;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED4;
	volatile uint32_t RESERVED5;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t Reserved6;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVED7;
	volatile uint32_t RESERVED8;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVED9;
	volatile uint32_t RESERVED10;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
};
#define MC0_HSI_SRC		0
#define MC0_LSE_SRC		1
#define MC0_HSE_SRC		2
#define MC0_PLL_SRC		3

#define MC0_NO_DIV		0
#define MC0_DIV_2		4
#define MC0_DIV_3		5
#define MC0_DIV_4		6
#define MC0_DIV_5		7

#define MCO_CLK_SELECT(x)	(Rcc->CFGR &= ~(3 << 21));	\
							(Rcc->CFGR |= (x << 22))

#define MCO_PRESCALE(x)		(Rcc->CFGR &= ~(7 << 24));	\
							(Rcc->CFGR |= (x << 24))	\

void enableRcc(void);
void enableGpioA(void);
void enableGpioG(void);
void enableSysCfg(void);
#endif /* RCC_H_ */
