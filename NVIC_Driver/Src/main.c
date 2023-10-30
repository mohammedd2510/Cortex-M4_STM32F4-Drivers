/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Osama
 * @brief          : Main program body
 ******************************************************************************/
#include "CortexM4/CortexM4_Core_NVIC.h"
#include "CortexM4/CortexM4_Core_SCB.h"

int main(void)
{
	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_GenerateSGI(USART2_IRQn);
    /* Loop forever */
	for(;;);
}
void USART2_IRQHandler (void){
	uint8_t i =0;
	i++;
}
