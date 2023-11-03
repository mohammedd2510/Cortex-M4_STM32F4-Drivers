/**
 ******************************************************************************
 * @file           : CortexM4_Core_SysTick.h
 * @author         : Mohamed Osama
 * @brief          : Contains The Static Code To Control System Timer
 ******************************************************************************/

#include "CortexM4/CortexM4_Core_SysTick.h"

static volatile ptrFunction SysTick_CallBack = NULL;
static volatile uint8_t SysTick_Mode = SysTick_SingleInterval_Mode;

/**
  * @brief  Initializes the SysTick timer with the specified number of ticks.
  * @details This function initializes the SysTick timer with the provided number of ticks.
  *          The SysTick timer is a 24-bit down counter that generates an interrupt when it reaches zero.
  * @param  SysTick_Ticks: The number of ticks to be loaded into the SysTick timer.
  * @return 0 if the initialization is successful, 1 if it fails.
  */
uint8_t SysTick_Init(uint32_t SysTick_Ticks)
{
	uint8_t RetVal = 0;
	if(SysTick_Ticks > SysTick_LOAD_RELOAD_Msk)
	{
		RetVal = 1;
	}
	else
	{
		/* Disable SysTick Counter */
		CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
		/* Set Reload Register to SysTick Ticks */
		SysTick->LOAD = SysTick_Ticks;
		/* Reset The SysTick Counter Value*/
		SysTick->VAL = 0;
		/* Select The Processor Clock */
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_1)
		SET_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Msk);
#elif (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_8)
		CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Msk);
#else
#error "Invalid Clock Source"
#endif
		/*Disable SysTick IRQ */
		CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Msk);
	}

return RetVal;
}

/**
  * @brief  Deinitializes the SysTick timer.
  * @details This function deinitializes the SysTick timer by disabling it and clearing any pending interrupts.
  * @param  None
  * @return None
  */
void SysTick_DeInit(void)
{
	/* Disable SysTick Counter */
	CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
	/* Reset The SysTick Reload Register */
	SysTick->LOAD = 0;
	/* Reset The SysTick Counter Value*/
	SysTick->VAL = 0;
	/*Disable SysTick IRQ */
	CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  Blocks the execution for the specified number of ticks using the SysTick timer.
  * @details This function blocks the execution for the provided number of ticks using the SysTick timer.
  *          It waits until the SysTick timer reaches zero.
  * @param  SysTick_Ticks: The number of ticks to wait.
  * @return None
  */
void SysTick_WaitBlocking(uint32_t SysTick_Ticks)
{
	/* Set Reload Register to SysTick Ticks */
	SysTick->LOAD = SysTick_Ticks;
	/* Enable SysTick Counter */
	SET_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
	/* Wait The COUNTFLAG Returns 1 */
	while( READ_BIT(SysTick->CTRL,SysTick_CTRL_COUNTFLAG_Msk) == 0);
	/* Disable SysTick Counter */
	CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
	/* Reset The SysTick Reload Register */
	SysTick->LOAD = 0;
	/* Reset The SysTick Counter Value*/
	SysTick->VAL = 0;
}

/**
  * @brief  Sets up a single interval using the SysTick timer and registers a callback function.
  * @details This function sets up a single interval using the SysTick timer with the provided number of ticks.
  *          It also registers a callback function to be called when the SysTick timer reaches zero.
  * @param  SysTick_Ticks: The number of ticks for the interval.
  * @param  CallBack: Pointer to the callback function.
  * @return None
  */
void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction CallBack)
{
	if (CallBack != NULL)
	{
		/* Set Reload Register to SysTick Ticks */
		SysTick->LOAD = SysTick_Ticks;
		/* Copy The User CallBack to Local ptrFunction */
		SysTick_CallBack = CallBack;
		/* Set The SysTick Timer to Single Interval Mode */
		SysTick_Mode = SysTick_SingleInterval_Mode;
		/*Enable SysTick IRQ */
		SET_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Msk);
		/* Enable SysTick Counter */
		SET_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
	}
	else { /* Nothing */}
}

/**
  * @brief  Sets up a periodic interval using the SysTick timer and registers a callback function.
  * @details This function sets up a periodic interval using the SysTick timer with the provided number of ticks.
  *          It also registers a callback function to be called when the SysTick timer reaches zero.
  * @param  SysTick_Ticks: The number of ticks for the interval.
  * @param  CallBack: Pointer to the callback function.
  * @return None
  */
void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction CallBack)
{
	if (CallBack != NULL)
	{
		/* Set Reload Register to SysTick Ticks */
		SysTick->LOAD = SysTick_Ticks;
		/* Copy The User CallBack to Local ptrFunction */
		SysTick_CallBack = CallBack;
		/* Set The SysTick Timer to Periodic Interval Mode */
		SysTick_Mode = SysTick_PeriodicInterval_Mode;
		/*Enable SysTick IRQ */
		SET_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Msk);
		/* Enable SysTick Counter */
		SET_BIT(SysTick->CTRL,SysTick_CTRL_ENABLE_Msk);
	}
	else { /* Nothing */}
}

/**
  * @brief  Retrieves the remaining number of ticks in the SysTick timer.
  * @details This function retrieves the remaining number of ticks in the SysTick timer.
  * @param  None
  * @return The remaining number of ticks in the SysTick timer.
  */
uint32_t SysTick_GetRemainingTicks(void)
{
	uint32_t RemainingTicks = 0;
	/* Copy The SysTick Counter Register to a Local Variable */
	RemainingTicks =  SysTick->VAL;
	/* Return The Local Variable */
	return RemainingTicks;
}

/**
  * @brief  Retrieves the number of elapsed ticks since the SysTick timer was last reset.
  * @details This function retrieves the number of elapsed ticks since the SysTick timer was last reset.
  *          The SysTick timer is a 24-bit down counter that generates an interrupt when it reaches zero.
  * @param  None
  * @return The number of elapsed ticks since the SysTick timer was last reset.
  */
uint32_t SysTick_GetElapsedTicks(void)
{
	uint32_t ElapsedTicks = 0;
	/* Copy The SysTick Elapsed Ticks to a Local Variable */
	ElapsedTicks =  (SysTick->LOAD - SysTick->VAL);
	/* Return The Local Variable */
	return ElapsedTicks;
}


void SysTick_Handler(void)
{
	if (SysTick_Mode == SysTick_SingleInterval_Mode)
	{
		SysTick_DeInit();
	}
	if(SysTick_CallBack)
	{
		SysTick_CallBack();
	}
}
