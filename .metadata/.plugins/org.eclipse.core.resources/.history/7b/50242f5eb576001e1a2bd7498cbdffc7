/**
 ******************************************************************************
 * @file           : CortexM4_Core_NVIC.c
 * @author         : Mohamed Osama
 * @brief          : Contains The Static Code To Control NVIC
 ******************************************************************************/
#include "CortexM4/CortexM4_Core_NVIC.h"

/**
 * @brief Enables a specific interrupt in the NVIC.
 * @details This function enables the interrupt specified by the IRQn parameter in the NVIC
 * @param IRQn The interrupt number to be enabled.
 * @note IRQn must not be Negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >=0){
		NVIC->ISER[((uint32_t)IRQn >> 5)] = (1UL << ((uint32_t)IRQn & 0x1F));
	}
}

/** @brief Disables a specific interrupt in the NVIC.
 *  @details This function disables the interrupt specified by the IRQn parameter in the NVIC
 *  @param IRQn The interrupt number to be disabled.
 *  @note IRQn must not be Negative
 */
void NVIC_DisableIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >=0){
			NVIC->ICER[((uint32_t)IRQn >> 5)] = (1UL << ((uint32_t)IRQn & 0x1F));
		}
}

/** @brief Sets a specific interrupt as pending in the NVIC.
 *  @details This function sets the specified interrupt as pending in the NVIC
 *  @param IRQn The interrupt number to be set as pending.
 *  @note IRQn must not be Negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if((uint32_t)IRQn >=0)
	{
		NVIC->ISPR[((uint32_t)IRQn >> 5)] = (1UL << ((uint32_t)IRQn & 0x1F));
	}
}

/** @brief Clears the pending status of a specific interrupt in the NVIC.
 *  @details This function clears the pending status of the specified interrupt in the NVIC
 *  @param IRQn The interrupt number for which the pending status should be cleared.
 *  @note IRQn must not be Negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if((uint32_t)IRQn >=0)
		{
			NVIC->ICPR[((uint32_t)IRQn >> 5)] = (1UL << ((uint32_t)IRQn & 0x1F));
		}
}

/** @brief Retrieves the active status of a specific interrupt in the NVIC.
 *  @details This function retrieves the active status of the specified interrupt in the NVIC (Nested Vectored Interrupt Controller).
 *  @param IRQn The interrupt number for which the active status should be retrieved.
 *  @return The active status of the specified interrupt. It returns a 1 value if the interrupt is active, and zero otherwise.
 *  @note IRQn must not be Negative
 */
uint32_t NVIC_GetActiveIRQ(IRQn_Type IRQn){

	if((uint32_t)IRQn >=0)
			{
			return	NVIC->IABR[((uint32_t)IRQn >> 5)] && (1UL << ((uint32_t)IRQn & 0x1F));
			}
	else return 0;
}
/**
 * @brief Set the priority of a specific interrupt.
 *
 * @details This function allows setting the priority of a specific interrupt identified by its IRQn_Type.
 *          The priority value determines the relative importance of the interrupt compared to other interrupts.
 *
 * @param IRQn     The interrupt number for which the priority is to be set.
 * @param Priority The priority value to be assigned to the interrupt.
 *                 - The valid range of priority values depends on the specific MicroController.
 *                 - A lower numerical value represents a higher priority.
 *
 * @return None.
 *
 * @note The priority value assigned to an interrupt determines its relative importance compared to other interrupts.
 *       The valid range of priority values may vary depending on the specific MicroController.
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t Priority)
{
	if((uint32_t)IRQn >=0)
	{
		NVIC->IP[(uint32_t)IRQn] = (uint8_t)(Priority << (8 - NVIC_PRIO_BITS));
	}
	else
	{
		/*Nothing*/
	}
}

/**
 * @brief Get the priority of a specific interrupt.
 *
 * @details This function retrieves the priority of a specific interrupt identified by its IRQn_Type.
 *          The priority value indicates the relative importance of the interrupt compared to other interrupts.
 *
 * @param IRQn The interrupt number for which the priority is to be retrieved.
 *
 * @return The priority value of the specified interrupt.
 *         - The priority value represents the relative importance of the interrupt.
 *         - The valid range of priority values depends on the specific MicroController.
 *         - A lower numerical value indicates a higher priority.
 *
 * @note The priority value of an interrupt indicates its relative importance compared to other interrupts.
 *       The valid range of priority values may vary depending on the specific MicroController.
 */
uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
	if((uint32_t)IRQn >=0)
		{
			return ( (NVIC->IP[(uint32_t)IRQn]) >> (8U - NVIC_PRIO_BITS) );
		}
		else
		{
			/*Nothing*/
		}
}
