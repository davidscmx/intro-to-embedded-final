/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 *
 * @brief Functions to report analytics for an array printing the maximum,
 * minimum, mean, and median
 *
 * In addition, this data set is reordered from large to small.
 * All statistics are rounded down to the nearest integer.
 *
 * @author David Sosa
 * @date 30.10.2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include "platform.h"

/**
 * @brief Prints relevant statistics of a given array.
 *
 * Prints the median, mean, maximum, minimun of a given array.
 *
 * @param[in] myArray myArray Array containing unsigned integers with size SIZE
 *
 */

void print_statistics(unsigned char *my_array, int size_of_array);

/**
 * @brief Prints the contests of the given array
 *
 * @param[in] myArray Array containing unsigned integers
 * @param[in] size    Size of the give array
 *
 */

void print_array(unsigned char *my_array, int size_of_array);

/**
 * @brief Finds the median of the given array
 *
 * @param[in] myArray Array containing unsigned integers
 * @param[in] size    Size of the give array
 *
 * @return median
 */

int find_median(unsigned char *my_array, int size_of_array);

/**
 * @brief Finds the median of the given array
 *
 * @param[in] myArray Array containing unsigned integers
 * @param[in] size    Size of the give array
 *
 * @return median
 */

int find_mean(unsigned char *my_array, int size);

/**
 * @brief Finds the maximum of the given array
 *
 * @param[in] myArray Array containing unsigned integers with size SIZE
 *
 * @return mean
 */
int find_maximum(unsigned char *my_array);

/**
 * @brief Finds the minumum of an array which has been already sorted in
 *        descending order
 *
 * @param[in] myArray Array containing unsigned integers with size SIZE
 * @param[in]  Size of the give array
 * @return maximum
 */
int find_minimum(unsigned char *my_array, int size);

/**
 * @brief Sort the given array
 *
 * Sorts the given array from in descending order.
 *
 * @param[in]  myArray Array containing unsigned integers
 * @param[in]  Size of the give array
 * @param[out] myArray Array containing unsigned integers with size SIZE sorted
 *             in descending order
 *
 */

void sort_array(unsigned char *my_array, int size);


#endif /* __STATS_H__ */
