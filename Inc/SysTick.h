/*
 * SysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYSTICK_EN				1
#define SYSTICK_IT				(1 << 1)
#define SYSTICK_PROC_CLK_SRC	(1 << 2)
#define SYSTICK_CNTR_EXPIR		(1 << 16)

#include <stdint.h>
#define SYSTICK_BASEADDR	0xE000E010
#define SysTickTimer		((SysTickReg*)(SYSTICK_BASEADDR))
typedef struct SysTickReg SysTickReg;

struct SysTickReg {
volatile uint32_t CTRL;
volatile uint32_t LOAD;
volatile uint32_t VAL;
volatile uint32_t CALIB;
};

#define sysTickEnable()			(SysTickTimer->CTRL |= SYSTICK_EN)
#define sysTickItEnable()		(SysTickTimer->CTRL |= SYSTICK_IT)
#define sysTickItDisable()		(SysTickTimer->CTRL &= (~SYSTICK_IT))
#define sysTickDisable()		(SysTickTimer->CTRL &= ~SYSTICK_EN)
#define sysTickSetReload(x)		(SysTickTimer->LOAD = (x))
#define sysTickReadCounter()	(SysTickTimer->VAL)
#define sysTickClearCounter()	(SysTickTimer->VAL = 0xbadface)
//set systick to run @ processor speed
#define sysTickFullSpeed()		(SysTickTimer->CTRL |= SYSTICK_PROC_CLK_SRC)
//set systick to run @ 1/8 of processor speed
#define sysTickPrescaleSpeed()	(SysTickTimer->CTRL &= ~SYSTICK_PROC_CLK_SRC)
//determine if systick timer has overflow. Return 1 if expired
#define sysTickHasExpired()		(SysTickTimer->CTRL & SYSTICK_CNTR_EXPIR)



#endif /* SYSTICK_H_ */
