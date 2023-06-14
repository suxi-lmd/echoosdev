#include "timer.h"

void delay(unsigned int n)
{
	while(n--)
		;
}



 
// static void calibrate(void)
// {
//     uint32_t time;
//     volatile uint32_t i;

//     iter_per_us = 1000000;

//     time = HAL_GetTick();
//     /* Wait for next tick */
//     while (HAL_GetTick() == time) {
//         /* wait */
//     }
//     for (i=0; i<iter_per_us; i++) {
//     }
//     iter_per_us /= ((HAL_GetTick()-time)*1000);
// }

// /**
//  * Software delay in µs
//  *  us: the number of µs to wait
//  **/
// void up_udelay(uint32_t us)
// {
//     volatile uint32_t i;

//     for (i=0; i<us*iter_per_us; i++) {
//     }
// }


// unsigned long HAL_GetTick(void) {
//     unsigned int hi = REGS_TIMER->counter_hi;
//     unsigned int lo = REGS_TIMER->counter_lo;
    
//     //double check hi value didn't change after setting it...
//     if (hi != REGS_TIMER->counter_hi) {
//         hi = REGS_TIMER->counter_hi;
//         lo = REGS_TIMER->counter_lo;
//     }

//     return ((unsigned long)hi << 32) | lo;
// }
    
// void HAL_Delay(unsigned int ms) {
//     unsigned long start = HAL_GetTick();

//     while(HAL_GetTick() < start + (ms * 1000));
// }

