/**
 ******************************************************************************
 * @file           : STM32F4xx_HAL_RCC.h
 * @author         : Mohamed Osama
 * @brief          : Contains The declarations to control the RCC Module
 ******************************************************************************/
#ifndef HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_

/* ------------------- Includes Start ----------------------------------------*/
#include "HAL_Drivers/Common/STM32F4xx_Peripheral_Defs.h"
#include "Common/Common_Macros.h"
#include "HAL_Drivers/Common/STM32F4xx_HAL_Def.h"
/* ------------------- Includes End ------------------------------------------*/


/* ------------------- Macro Declarations Start ------------------------------*/

/**
  * @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE           0x00000000U  /*!< No oscillator used */
#define RCC_OSCILLATORTYPE_HSE            0x00000001U  /*!< High-Speed External oscillator used */
#define RCC_OSCILLATORTYPE_HSI            0x00000002U  /*!< High-Speed Internal oscillator used */
#define RCC_OSCILLATORTYPE_LSE            0x00000004U  /*!< Low-Speed External oscillator used */
#define RCC_OSCILLATORTYPE_LSI            0x00000008U  /*!< Low-Speed Internal oscillator used */
#define RCC_OSCILLATORTYPE_PLLCLK         0x00000010U  /*!< PLL clock used */
/**
  * @}
  */

/**
  * @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF     ((uint8_t)0x00)  /*!< HSE oscillator off */
#define RCC_HSE_ON      ((uint8_t)0x01)  /*!< HSE oscillator on */
/**
  * @}
  */
/**
  * @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF     ((uint8_t)0x00)  /*!< HSI oscillator off */
#define RCC_HSI_ON      ((uint8_t)0x01)  /*!< HSI oscillator on */
/**
  * @}
  */

/**
  * @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF     ((uint8_t)0x00)  /*!< LSE oscillator off */
#define RCC_LSE_ON      ((uint8_t)0x01)  /*!< LSE oscillator on */
/**
  * @}
  */

/**
  * @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF     ((uint8_t)0x00)  /*!< LSI oscillator off */
#define RCC_LSI_ON      ((uint8_t)0x01)  /*!< LSI oscillator on */
/**
  * @}
  */

/**
  * @defgroup RCC_PLL_Config PLL Config
  * @{
  */
#define RCC_PLL_OFF     ((uint8_t)0x00)  /*!< PLL off */
#define RCC_PLL_ON      ((uint8_t)0x01)  /*!< PLL on */
/**
  * @}
  */

/**
  * @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @brief    Reset and Clock Control - AHB Clock Source Register
  * @{
  */

#define RCC_SYSCLK_AHB_DIV1     RCC_CFGR_HPRE_DIV1   /*!< AHB clock source: System clock not divided */
#define RCC_SYSCLK_AHB_DIV2     RCC_CFGR_HPRE_DIV2   /*!< AHB clock source: System clock divided by 2 */
#define RCC_SYSCLK_AHB_DIV4     RCC_CFGR_HPRE_DIV4   /*!< AHB clock source: System clock divided by 4 */
#define RCC_SYSCLK_AHB_DIV8     RCC_CFGR_HPRE_DIV8   /*!< AHB clock source: System clock divided by 8 */
#define RCC_SYSCLK_AHB_DIV16    RCC_CFGR_HPRE_DIV16  /*!< AHB clock source: System clock divided by 16 */
#define RCC_SYSCLK_AHB_DIV64    RCC_CFGR_HPRE_DIV64  /*!< AHB clock source: System clock divided by 64 */
#define RCC_SYSCLK_AHB_DIV128   RCC_CFGR_HPRE_DIV128 /*!< AHB clock source: System clock divided by 128 */
#define RCC_SYSCLK_AHB_DIV256   RCC_CFGR_HPRE_DIV256 /*!< AHB clock source: System clock divided by 256 */
#define RCC_SYSCLK_AHB_DIV512   RCC_CFGR_HPRE_DIV512 /*!< AHB clock source: System clock divided by 512 */

/**
  * @}
  */

/**
  * @defgroup RCC_HCLK_APB1 AHB to APB1 Clock Prescaler
  * @brief    Reset and Clock Control - AHB to APB1 Clock Prescaler Register
  * @{
  */

#define RCC_HCLK_APB1_DIV1     RCC_CFGR_PPRE1_DIV1   /*!< APB1 clock source: AHB clock not divided */
#define RCC_HCLK_APB1_DIV2     RCC_CFGR_PPRE1_DIV2   /*!< APB1 clock source: AHB clock divided by 2 */
#define RCC_HCLK_APB1_DIV4     RCC_CFGR_PPRE1_DIV4   /*!< APB1 clock source: AHB clock divided by 4 */
#define RCC_HCLK_APB1_DIV8     RCC_CFGR_PPRE1_DIV8   /*!< APB1 clock source: AHB clock divided by 8 */
#define RCC_HCLK_APB1_DIV16    RCC_CFGR_PPRE1_DIV16  /*!< APB1 clock source: AHB clock divided by 16 */

/**
  * @}
  */

/**
  * @defgroup RCC_HCLK_APB2 AHB to APB2 Clock Prescaler
  * @brief    Reset and Clock Control - AHB to APB2 Clock Prescaler Register
  * @{
  */

#define RCC_HCLK_APB2_DIV1     RCC_CFGR_PPRE2_DIV1   /*!< APB2 clock source: AHB clock not divided */
#define RCC_HCLK_APB2_DIV2     RCC_CFGR_PPRE2_DIV2   /*!< APB2 clock source: AHB clock divided by 2 */
#define RCC_HCLK_APB2_DIV4     RCC_CFGR_PPRE2_DIV4   /*!< APB2 clock source: AHB clock divided by 4 */
#define RCC_HCLK_APB2_DIV8     RCC_CFGR_PPRE2_DIV8   /*!< APB2 clock source: AHB clock divided by 8 */
#define RCC_HCLK_APB2_DIV16    RCC_CFGR_PPRE2_DIV16  /*!< APB2 clock source: AHB clock divided by 16 */

/**
  * @}
  */
/* ------------------- Macro Declarations End --------------------------------*/

/* ------------------- Macro Function Declarations Start ---------------------*/
/**
  * @defgroup GPIO_Clock_Control GPIO Clock Control
  * @brief Macros for enabling and disabling GPIO clock.
  *
  * These macros provide a convenient way to enable and disable the clock for
  * different GPIO ports on the microcontroller.
  *
  * Usage: Call the respective `HAL_RCC_GPIOx_CLK_ENABLE()` macro to enable the
  * clock for GPIO Port x, or `HAL_RCC_GPIOx_CLK_DISABLE()` to disable it.
  * The macros manipulate the RCC_AHB1ENR register to control the clock.
  *
  * @{
  */

/**
  * @brief Enable the clock for GPIO Port A.
  */
#define HAL_RCC_GPIOA_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN_Msk)

/**
  * @brief Enable the clock for GPIO Port B.
  */
#define HAL_RCC_GPIOB_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN_Msk)

/**
  * @brief Enable the clock for GPIO Port C.
  */
#define HAL_RCC_GPIOC_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN_Msk)

/**
  * @brief Enable the clock for GPIO Port D.
  */
#define HAL_RCC_GPIOD_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN_Msk)

/**
  * @brief Enable the clock for GPIO Port E.
  */
#define HAL_RCC_GPIOE_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN_Msk)

/**
  * @brief Enable the clock for GPIO Port F.
  */
#define HAL_RCC_GPIOF_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN_Msk)

/**
  * @brief Enable the clock for GPIO Port G.
  */
#define HAL_RCC_GPIOG_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN_Msk)

/**
  * @brief Enable the clock for GPIO Port H.
  */
#define HAL_RCC_GPIOH_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN_Msk)

/**
  * @brief Enable the clock for GPIO Port I.
  */
#define HAL_RCC_GPIOI_CLK_ENABLE()    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN_Msk)

/**
  * @brief Disable the clock for GPIO Port A.
  */
#define HAL_RCC_GPIOA_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN_Msk)

/**
  * @brief Disable the clock for GPIO Port B.
  */
#define HAL_RCC_GPIOB_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN_Msk)

/**
  * @brief Disable the clock for GPIO Port C.
  */
#define HAL_RCC_GPIOC_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN_Msk)

/**
  * @brief Disable the clock for GPIO Port D.
  */
#define HAL_RCC_GPIOD_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN_Msk)

/**
  * @brief Disable the clock for GPIO Port E.
  */
#define HAL_RCC_GPIOE_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN_Msk)

/**
  * @brief Disable the clock for GPIO Port F.
  */
#define HAL_RCC_GPIOF_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN_Msk)

/**
  * @brief Disable the clock for GPIO Port G.
  */
#define HAL_RCC_GPIOG_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN_Msk)

/**
  * @brief Disable the clock for GPIO Port H.
  */
#define HAL_RCC_GPIOH_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN_Msk)

/**
  * @brief Disable the clock for GPIO Port I.
  */
#define HAL_RCC_GPIOI_CLK_DISABLE()    CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN_Msk)

/**
  * @}
  */
/* ------------------- Macro Function Declarations End -----------------------*/

/* ------------------- Data Type Declarations Start --------------------------*/

/**
  * @brief RCC Clock Configuration Structure
  *
  * This structure defines the RCC clock configuration.
  */
typedef struct
{
    uint32_t OscillatorType;  /*!< Specifies the oscillator type.
                                   This parameter can be a value of @ref RCC_Oscillator_Type */

    uint32_t HSEState;        /*!< Specifies the HSE oscillator state.
                                   This parameter can be a value of @ref RCC_HSE_Config */

    uint32_t HSIState;        /*!< Specifies the HSI oscillator state.
                                   This parameter can be a value of @ref RCC_HSI_Config */

    uint32_t LSEState;        /*!< Specifies the LSE oscillator state.
                                   This parameter can be a value of @ref RCC_LSE_Config */

    uint32_t LSIState;        /*!< Specifies the LSI oscillator state.
                                   This parameter can be a value of @ref RCC_LSI_Config */

    uint32_t PLLState;        /*!< Specifies the PLL state.
                                   This parameter can be a value of @ref RCC_PLL_Config */
} RCC_OscInitTypeDef;

/**
  * @brief  RCC Clock Initialization Structure
  */
typedef struct
{
  uint32_t AHBCLKDivider;   /*!< AHB Clock Divider.
                                 This parameter can be a value of @ref RCC_AHB_Clock_Source */

  uint32_t APB1CLKDivider;  /*!< APB1 Clock Divider.
                                 This parameter can be a value of @ref RCC_HCLK_APB1 */

  uint32_t APB2CLKDivider;  /*!< APB2 Clock Divider.
                                 This parameter can be a value of @ref RCC_HCLK_APB2 */
} RCC_ClkInitTypeDef;

/* ------------------- Data Type Declarations End ----------------------------*/

/* ------------------- Software Interfaces Declarations Start ----------------*/

/**
  * @brief  Configures the RCC oscillators based on the specified parameters in the RCC_OscInitTypeDef structure.
  *
  * @details This function configures the RCC oscillators based on the parameters specified in the RCC_OscInitTypeDef structure.
  *          It enables or disables the HSE (High-Speed External) oscillator, HSI (High-Speed Internal) oscillator,
  *          LSE (Low-Speed External) oscillator, LSI (Low-Speed Internal) oscillator, and PLL (Phase-Locked Loop).
  *
  * @param  RCC_OscInitStruct: pointer to an RCC_OscInitTypeDef structure that contains the configuration information for the RCC oscillators.
  *
  * @retval HAL_StatusTypeDef: HAL status.
  *          - HAL_OK: Operation completed successfully.
  *          - HAL_ERROR: Operation completed with an error.
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);


/**
  * @brief  RCC Clock Initialization
  *
  * @details The RCC_ClkInitTypeDef structure must be filled with the appropriate values before
  * 		   calling this function. The AHBCLKDivider, APB1CLKDivider, and APB2CLKDivider members
  * 		   of the structure specify the desired clock dividers for the AHB, APB1, and APB2 buses
  * 		   respectively.
  *
  * @param[in]  ClkInitStruct  Pointer to an RCC_ClkInitTypeDef structure that contains
  *                            the configuration information for RCC clock initialization.
  *
  * @retval HAL status
  *           - HAL_OK:      Clock initialization successful.
  *           - HAL_ERROR:   Clock initialization failed.
  *
  * @note   After calling this function, the updated clock frequencies will be applied.
  *
  */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef* RCC_ClkInitStruct);

/* ------------------- Software Interfaces Declarations End ------------------*/



#endif /* HAL_DRIVERS_RCC_STM32F4XX_HAL_RCC_H_ */




















