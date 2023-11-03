/*
 * delay_us.c
 *
 *  Created on: Nov 3, 2023
 *      Author: mohop
 */

#include "delay_us.h"

void delay_us(uint32_t us) {
	// Enable TIM2 clock
	    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	    // Configure TIM2
	    TIM2->PSC = (SystemCoreClock / 1000000) - 1;  // Set prescaler to achieve 1us resolution
	    TIM2->ARR = us - 1;  // Set auto-reload value to achieve the desired delay

	    // Enable TIM2
	    TIM2->CR1 |= TIM_CR1_CEN;

	    // Wait until the delay has elapsed
	    while ((TIM2->SR & TIM_SR_UIF) == 0) {
	        // Wait
	    }

	    // Clear the update interrupt flag
	    TIM2->SR &= ~TIM_SR_UIF;

	    // Disable TIM2
	    TIM2->CR1 &= ~TIM_CR1_CEN;

	    // Disable TIM2 clock
	    RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
}
