
#include "../include/data.h"
#include <stdio.h>
#include <stdint.h>

#define MAX_BUFFER (255)


void swap(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void reverse(char *str, int length) 
{ 
    int start = 0; 
    int end = length - 1; 
    while (start < end) 
    { 
        swap((str+start), (str+end)); 
        start++; 
        end--; 
    } 
} 

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int i = 0; 
    uint8_t isNegative = 0; 
    uint8_t counter = 0;
    
    if (data == 0) 
    { 
        ptr[i++] = '0'; 
        ptr[i] = '\0'; 
        return i+1; 
    } 
  
    if (data < 0 && base == 10) 
    { 
        isNegative = 1; 
        data = -data; 
    } 
  
    // Process individual digits 
    while (data != 0) 
    { 
        int rem = data % base; 
        ptr[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        data = data/base; 
    } 

    if (isNegative)
    {
        ptr[i++] = '-';
    }
    ptr[i] = '\0'; 
    // Reverse the string 
    reverse(ptr, i); 
    return i+1; 
} 

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    return 1;
}

int main(){
    
}