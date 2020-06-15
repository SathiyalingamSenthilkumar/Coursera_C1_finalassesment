/**********************************************************
 * File data.c
 * Author: Sathiya Lingam Senthil Kumar
 **********************************************************/

#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
  uint8_t len = 0; //The value of length
  int32_t abs_data;
  //Taking absolute value
  if(data < 0){
    abs_data = (-1) * data;
  }
  else{
    abs_data = data;  
  }

  uint8_t i=0;//for keeps track
  uint8_t rem;
  
  while(abs_data){ //true as long as abs_data is non-zero
    rem = abs_data % base ; //For conversion

    if(rem > 10){ //For Hexadecimal
      *(ptr+i) = 65 + (rem-10); //For A-F ('65'-A)  
    }
    else{
      *(ptr+i) = '0' + rem;
    }
    abs_data /= base; 
    i++;
  }
  
  if(i == 0){ //True when the while loop is never entered
    *(ptr+i) = '0';
    i++;
  }

  if(data < 0){ //If value is negative
    *(ptr+i) = '-'; 
    i++;
  }

  *(ptr+i)='\0'; //Placing the Null Pointer
  
  len = i+1; //Length of the string
  
  //The digits except '\0'has to be swapped

  uint8_t temp;
  for(uint8_t j=0; j < (len-1)/2; j++){
    temp = *(ptr+(len-1)-1-j);
    *(ptr+(len-1)-1-j) = *(ptr+j);
    *(ptr+j) = temp;
  }

  return len;  
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int32_t sign=1;
  uint8_t i=0;
  int32_t res=0;

  //Checking for negative-sign
  if(*(ptr+i) == '-'){
    sign = -1;
    i++;  
  }

  for( ;*(ptr + i) != '\0'; i++){
    
      if(*(ptr + i)>= 65){//For A-F
        res = res * base + *(ptr + i) - 'A'+10;
      }
      else{ 
        res = res * base + *(ptr + i) - '0';
      }        
  }
  return res*sign; //For sign
}
