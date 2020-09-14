/**
 * @file data.h
 *
 * @brief This file does some very basic data manipulation.
 *        Converts integer to ASCII and viceversa.
 * 
 * @author David Sosa
 * @date   14.09.2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include "platform.h"

#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 * 
 * Requirements:
 * - All operations need to be performed using pointer arithmetic, not array indexing
 * - The number you wish to convert is passed in as a signed 32-bit integer.
 * - You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
 * - Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * - The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 * - You must place a null terminator at the end of the converted c-string
 * - Function should return the length of the converted data (including a negative sign). Example 
     my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
 * - This function needs to handle signed data.
 * - You may not use any string functions or libraries
 *
 * @param[in] data 
 * @param[in] ptr  
 * @param[in] base 
 *
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer needs to convert data back from an ASCII represented string 
 *        into an integer type.
 *
 * - All operations need to be performed using pointer arithmetic, not array indexing
 * - The character string to convert is passed in as a uint8_t * pointer (ptr).
 * - The number of digits in your character set is passed in as a uint8_t integer (digits).
 * - You should be able to support bases 2 to 16.
 * - The converted 32-bit signed integer should be returned.
 * - This function needs to handle signed data.
 * - You may not use any string functions or libraries
 * 
 * @param[in] ptr 
 * @param[in] digits
 * @param[in] base 
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
