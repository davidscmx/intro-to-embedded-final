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
 * @file stats.c
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author David Sosa
 * @date 30.10.2019
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(test, SIZE);

}

void print_statistics(unsigned char *myArray, int size)
{
  printf("Unsorted array \n");
  print_array(myArray,size);
  sort_array(myArray,size);

  int median = find_median(myArray,size);
  int mean = find_mean(myArray, size);
  int min = find_minimum(myArray, size);
  int max = find_maximum(myArray);

  printf("Sorted array \n");
  print_array(myArray,size);
  printf("Array mean %d \n", mean);
  printf("Array median %d \n", median);
  printf("min %d \n", min);
  printf("max %d \n", max);
}

void print_array(unsigned char *myArray, int size)
{
  for (int i = 0; i < size; i++)
  {
     printf("%d ",myArray[i]);
  }
  printf("\n");
}

/**
 * @brief Sorts an array of unsigned integers with size size
 *
 * @param myArray
 * @param size
 */

void sort_array(unsigned char *myArray, int size)
{
  int i, j, temp;
  for (i = 0 ; i < size; i++)
  {
    for (j = 0 ; j < size -1; j++)
    {
      if (myArray[j] < myArray[j+1])
      {
        /* Swapping */
        temp = myArray[j];
        myArray[j] = myArray[j+1];
        myArray[j+1] = temp;
      }
    }
  }
}

int find_median(unsigned char *mySortedArray, int size)
{
  int median = 0;
  if (size % 2 == 0)
  {
    median = (mySortedArray[(size-1)/2] + mySortedArray[size/2])/2.0;
  }
  else
  {
    median = mySortedArray[size/2];
  }
  return median;
}

int find_mean(unsigned char *myArray, int size)
{
  int sum = 0;
  for (int i = 0; i < size;i++)
  {
    sum += myArray[i];
  }

  int division = (float)sum / (float)size;

  return division;
}

int find_maximum(unsigned char *myArray)
{
  return myArray[0];
}

int find_minimum(unsigned char *myArray, int size)
{
  return myArray[size-1];;
}
