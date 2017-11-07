/*
 * Exti.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef EXTI_H_
#define EXTI_H_

#define EXTI_BASE_ADDR		0x40013C00
#define Exti				((ExtiReg*)(EXTI_BASE_ADDR))

#define pushButtonPin		0

typedef struct ExtiReg ExtiReg;
struct ExtiReg{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
};

#define EXTI_CLEAR_IT_MASK(x)		(Exti->IMR |= (1 << x))
#define EXTI_SET_IT_MASK(x)			(Exti->IMR &= ~(1 << x))
#define EXTI_SET_EV_MASK(x)			(Exti->EMR |= (1 << x))
#define EXTI_CLEAR_EV_MASK(x)		(Exti->EMR &= ~(1 << x))
#define EXTI_SELECT_RISE_TRIG(x)	(Exti->RTSR |= (1 << x))
#define EXTI_CLEAR_FALL_TRIG(x)		(Exti->FTSR &= ~(1 << x))
#define EXTI_CLEAR_PENDING_R(x)		(Exti->PR |= (1 << x))


#endif /* EXTI_H_ */
