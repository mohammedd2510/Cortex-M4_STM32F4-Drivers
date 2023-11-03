/*
 * Std_Types.h
 *
 *  Created on: Nov 2, 2023
 *      Author: mohop
 */

#ifndef COMMON_STD_TYPES_H_
#define COMMON_STD_TYPES_H_

/**
  * @brief  Represents the standard return value indicating successful operation.
  * @details This constant is used to indicate a successful operation or function execution.
  *          It has a value of 0x0U.
  */
#define E_OK 0x0U

/**
  * @brief  Represents the standard return value indicating unsuccessful operation.
  * @details This constant is used to indicate an unsuccessful operation or function execution.
  *          It has a value of 0x1U.
  */
#define E_NOT_OK 0x1U

/**
  * @brief  Represents the standard return type for functions.
  * @details This type definition is used to define the standard return type for functions.
  *          It is typically used to indicate the success or failure of an operation or function execution.
  *          The `Std_ReturnType` type is defined as `uint8`.
  */

#define ZERO_INIT 0

typedef uint8_t Std_ReturnType;

#endif /* COMMON_STD_TYPES_H_ */
