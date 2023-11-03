/**
 ******************************************************************************
 * @file           : STM32F4xx_Peripheral_Defs
 * @author         : Mohamed Osama
 * @brief          : Contains The Data Structures & Address Mapping for All Peripherals
 ******************************************************************************/
#ifndef HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_
#define HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_

/* ------------------- Includes Start ----------------------------------------*/
#include "Common/Std_Types.h"

/* ------------------- Includes End ------------------------------------------*/


/* ------------------- Macro Declarations Start ------------------------------*/
#define PERIPH_BASE         (0x40000000UL) /**< Base address of the peripheral devices. */
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x0020000UL) /**< Base address of the Advanced High-Performance Bus 1 peripheral devices. */
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800UL) /**< Base address of the Reset and Clock Control peripheral. */
#define RCC                 ((RCC_TypeDef *)RCC_BASE) /**< Reset and Clock Control peripheral. */

/***********************Bit definition for RCC_AHB1ENR register ******************************/
#define RCC_AHB1ENR_GPIOAEN_Pos     (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos) /*!< 0x00000001 */

#define RCC_AHB1ENR_GPIOBEN_Pos     (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos) /*!< 0x00000002 */

#define RCC_AHB1ENR_GPIOCEN_Pos     (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos) /*!< 0x00000004 */

#define RCC_AHB1ENR_GPIODEN_Pos     (3U)
#define RCC_AHB1ENR_GPIODEN_Msk     (0x1UL << RCC_AHB1ENR_GPIODEN_Pos) /*!< 0x00000008 */

#define RCC_AHB1ENR_GPIOEEN_Pos     (4U)
#define RCC_AHB1ENR_GPIOEEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos) /*!< 0x00000010 */

#define RCC_AHB1ENR_GPIOFEN_Pos     (5U)
#define RCC_AHB1ENR_GPIOFEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos) /*!< 0x00000020 */

#define RCC_AHB1ENR_GPIOGEN_Pos     (6U)
#define RCC_AHB1ENR_GPIOGEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos) /*!< 0x00000040 */

#define RCC_AHB1ENR_GPIOHEN_Pos     (7U)
#define RCC_AHB1ENR_GPIOHEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos) /*!< 0x00000080 */

#define RCC_AHB1ENR_GPIOIEN_Pos     (8U)
#define RCC_AHB1ENR_GPIOIEN_Msk     (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos) /*!< 0x00000100 */

/*********************** Bit Definition for RCC_CFGR register ******************************************/

#define RCC_CFGR_SW0_Pos       0U
#define RCC_CFGR_SW0_Msk       (0x1UL << RCC_CFGR_SW0_Pos) 		/*!< 0x00000001 */
#define RCC_CFGR_SW1_Pos       1U
#define RCC_CFGR_SW1_Msk       (0x1UL << RCC_CFGR_SW1_Pos) 		/*!< 0x00000001 */

/*!< HPRE Configurations */
#define RCC_CFGR_HPRE_Pos       4U
#define RCC_CFGR_HPRE_Msk       (0xFUL << RCC_CFGR_HPRE_Pos) 		/*!< 0x000000F0 */

#define RCC_CFGR_HPRE_DIV1      0x00000000UL   /*!< AHB1 prescaler: SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2      0x00000080UL   /*!< AHB1 prescaler: SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4      0x00000090UL   /*!< AHB1 prescaler: SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8      0x000000A0UL   /*!< AHB1 prescaler: SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16     0x000000B0UL   /*!< AHB1 prescaler: SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64     0x000000C0UL   /*!< AHB1 prescaler: SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128    0x000000D0UL   /*!< AHB1 prescaler: SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256    0x000000E0UL   /*!< AHB1 prescaler: SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512    0x000000F0UL   /*!< AHB1 prescaler: SYSCLK divided by 512 */

/*!< PPRE1 Configurations */
#define RCC_CFGR_PPRE1_Pos      10U
#define RCC_CFGR_PPRE1_Msk      (0x7UL << RCC_CFGR_PPRE1_Pos)		/*!< 0X00001C00 */

#define RCC_CFGR_PPRE1_DIV1     0x00000000UL   /*!< APB1 prescaler: HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2     0x00001000UL   /*!< APB1 prescaler: HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4     0x00001400UL   /*!< APB1 prescaler: HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8     0x00001800UL   /*!< APB1 prescaler: HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16    0x00001C00UL   /*!< APB1 prescaler: HCLK divided by 16 */

/*!< PPRE2 Configurations */
#define RCC_CFGR_PPRE2_Pos      13U
#define RCC_CFGR_PPRE2_Msk      (0x7UL << RCC_CFGR_PPRE2_Pos) 		/*!< 0X0000E000 */

#define RCC_CFGR_PPRE2_DIV1     0x00000000UL   /*!< APB2 prescaler: HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2     0x00008000UL   /*!< APB2 prescaler: HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4     0x0000A000UL   /*!< APB2 prescaler: HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8     0x0000C000UL   /*!< APB2 prescaler: HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16    0x0000E000UL   /*!< APB2 prescaler: HCLK divided by 16 */

/**
  * @}
  */
/**
  * @defgroup RCC_Oscillator_Bit_Def RCC Oscillator Bit Definitions
  * @brief Bit positions and masks for RCC oscillator configuration
  * @{
  */

#define RCC_CR_HSEON_Pos      (16U)
#define RCC_CR_HSEON_Msk      (0x1UL << RCC_CR_HSEON_Pos ) /*!< 0x00010000 */

#define RCC_CR_HSION_Pos      (0U)
#define RCC_CR_HSION_Msk      (0x1UL << RCC_CR_HSION_Pos ) /*!< 0x00000001 */

#define RCC_BDCR_LSEON_Pos    (0U)
#define RCC_BDCR_LSEON_Msk    (0x1UL << RCC_BDCR_LSEON_Pos ) /*!< 0x00000001 */

#define RCC_CSR_LSION_Pos     (0U)
#define RCC_CSR_LSION_Msk     (0x1UL << RCC_CSR_LSION_Pos ) /*!< 0x00000001 */

#define RCC_CR_PLLON_Pos      (24U)
#define RCC_CR_PLLON_Msk      (0x1UL << RCC_CR_PLLON_Pos ) /*!< 0x01000000 */

/**
  * @}
  */

/* ------------------- Macro Declarations End --------------------------------*/

/* ------------------- Macro Function Declarations Start ---------------------*/


/* ------------------- Macro Function Declarations End -----------------------*/

/* ------------------- Data Type Declarations Start --------------------------*/

/**
 * @brief RCC (Reset and Clock Control) peripheral registers.
 *
 * This struct represents the RCC peripheral registers, which control the system reset and clock configuration.
 * It provides access to various control and status registers related to the clock system.
 */
typedef struct {
    volatile uint32_t CR;        /*!< RCC clock control register,                                 Address offset: 0x00 */
    volatile uint32_t PLLCFGR;   /*!< RCC PLL configuration register,                             Address offset: 0x04 */
    volatile uint32_t CFGR;      /*!< RCC clock configuration register,                           Address offset: 0x08 */
    volatile uint32_t CIR;       /*!< RCC clock interrupt register,                               Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;  /*!< RCC AHB1 peripheral reset register,                         Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;  /*!< RCC AHB2 peripheral reset register,                         Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;  /*!< RCC AHB3 peripheral reset register,                         Address offset: 0x18 */
    volatile uint32_t RESERVED0; /*!< Reserved, 0x1C                                                                  */
    volatile uint32_t APB1RSTR;  /*!< RCC APB1 peripheral reset register,                         Address offset: 0x20 */
    volatile uint32_t APB2RSTR;  /*!< RCC APB2 peripheral reset register,                         Address offset: 0x24 */
    volatile uint32_t RESERVED1[2]; /*!< Reserved, 0x28-0x2C                                                            */
    volatile uint32_t AHB1ENR;   /*!< RCC AHB1 peripheral clock register,                         Address offset: 0x30 */
    volatile uint32_t AHB2ENR;   /*!< RCC AHB2 peripheral clock register,                         Address offset: 0x34 */
    volatile uint32_t AHB3ENR;   /*!< RCC AHB3 peripheral clock register,                         Address offset: 0x38 */
    volatile uint32_t RESERVED2; /*!< Reserved, 0x3C                                                                  */
    volatile uint32_t APB1ENR;   /*!< RCC APB1 peripheral clock enable register,                  Address offset: 0x40 */
    volatile uint32_t APB2ENR;   /*!< RCC APB2 peripheral clock enable register,                  Address offset: 0x44 */
    volatile uint32_t RESERVED3[2]; /*!< Reserved, 0x48-0x4C                                                            */
    volatile uint32_t AHB1LPENR; /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    volatile uint32_t AHB2LPENR; /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    volatile uint32_t AHB3LPENR; /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
    volatile uint32_t RESERVED4; /*!< Reserved, 0x5C                                                                  */
    volatile uint32_t APB1LPENR; /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    volatile uint32_t APB2LPENR; /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    volatile uint32_t RESERVED5[2]; /*!< Reserved, 0x68-0x6C                                                            */
    volatile uint32_t BDCR;      /*!< RCC Backup domain control register,                          Address offset: 0x70 */
    volatile uint32_t CSR;       /*!< RCC clock control & status register,                         Address offset: 0x74 */
    volatile uint32_t RESERVED6[2]; /*!< Reserved, 0x78-0x7C                                                            */
    volatile uint32_t SSCGR;     /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR; /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} RCC_TypeDef;

/* ------------------- Data Type Declarations End ----------------------------*/

/* ------------------- Software Interfaces Declarations Start ----------------*/


/* ------------------- Software Interfaces Declarations End ------------------*/


#endif /* HAL_DRIVERS_COMMON_STM32F4XX_PERIPHERAL_DEFS_H_ */
