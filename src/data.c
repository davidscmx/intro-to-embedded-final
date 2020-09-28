
#include "../include/data.h"
#include <stdio.h>
#include <stdint.h>
#define MAX_BUFFER (256)


#define MAX_STR_SIZE (33)
#define ONE_ASCII (49)
#define ZERO_ASCII (48)

static uint8_t* to_binary_str(int32_t data)
{
    uint8_t char_array[MAX_STR_SIZE];
    // Add null terminator to end of string
    uint8_t *p = char_array;
     
    // Requirement to use pointer arithmetic
    *(p + MAX_STR_SIZE-1) = '\0';

    uint8_t mask = 1;
    uint8_t last_one_position = 0;
    
    for(uint8_t i=2; i < MAX_STR_SIZE+1; i++)
    { 
      uint8_t current_bit = mask & data;
      // scared of the right-bit shift because it is implementation-defined
      data = data >> 1; 
      if (current_bit == 1)
      {
        *(p + MAX_STR_SIZE-i) = ONE_ASCII;
        last_one_position = MAX_STR_SIZE-i;
      }
      else
      {
        *(p + MAX_STR_SIZE-i) = ZERO_ASCII;        
      }
    }
    uint8_t total_chars = MAX_STR_SIZE - last_one_position - 1; // -1 from the null terminator
    
    uint8_t final_array[MAX_STR_SIZE];
    for (uint8_t i=last_one_position; i < MAX_STR_SIZE-1; i++)
    {
      // start counting char when 
      printf("%c", char_array[i]);
    }
    
    return total_chars;
}

static uint8_t* to_decimal_str(int32_t data)
{

}

static uint8_t* to_hex_str(int32_t data)
{

}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    switch(base){
        case 2:
            uint8_t n_chars = to_binary_str(data);
            break;
        case 10:
            uint8_t* ptr = to_hex_str(data);
            break;
        case 16:
            uint8_t* ptr = to_hex_str(data);
            break;
        default:
            printf("Invalid base\n" );
            return 1;
    }
    
    return 0;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    return 1;
}

int main(){

    uint8_t my_str[MAX_BUFFER];
    my_str_ptr = to_binary_str(10);

}