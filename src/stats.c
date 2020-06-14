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
 * @brief Performs statistical analysis on an unsigned char array.
 *
 * Functions are written to analyze an array of unsigned char data items, and
 * reports the maximum, minimum, mean, median of the data set. The array is
 * sorted in the descending order and all the data is printed to the screen.
 *
 * @author <Sathiya Lingam Senthil Kumar>
 * @date <28 May 2020>
 *
 */



#include <stdio.h>
#include "stats.h"

#include <stdint.h>
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  
  //Creating compile time switch for printing
  #ifdef VERBOSE 
  PRINTF("The Array Elements:\n");
  print_array(test, SIZE);//printing the array

  sort_array(test, SIZE); // Performing sorting
  PRINTF("The sorted Array(descending order):\n");
  print_array(test, SIZE);
  
  print_statistics(test, SIZE);//Printing the Statistics
  #endif
  return 0;  
}



/* Function Definitions */

void print_array(unsigned char* ptr,unsigned int n){  
  for(int i=0; i<n; i++){
    #ifdef VERBOSE	  
    PRINTF("%u\t",(unsigned int) *(ptr+i));//Prints on the element 	  
    #endif
    if((i+1)%8 == 0){
      #ifdef VERBOSE	    
      PRINTF("\n");//Creates a new line after printing 8 elements
      #endif
    }	     
  }	  
  PRINTF("\n");       	
}

void print_statistics(unsigned char* ptr,unsigned int n){
  unsigned char mean;
  unsigned char median;
  unsigned char maximum;
  unsigned char minimum;
  
  
  mean = find_mean(ptr, n);
  maximum = find_maximum(ptr, n);
  minimum = find_minimum(ptr, n);
  median = find_median(ptr, n);

  PRINTF("\nPrinting the statistics:\n");
  PRINTF("Mean = %u \n",(unsigned int) mean);
  PRINTF("Maximum=%u \n",(unsigned int) maximum);  
  PRINTF("Minimum=%u \n",(unsigned int) minimum); 
  PRINTF("Median=%u \n",(unsigned int) median); 
}	

unsigned char find_median(unsigned char* ptr,unsigned int n){
  unsigned char median;
  unsigned int median_int;  
  if ( ptr == 0){
    return 0;//Overcoming null pointer dereference
  }

  sort_array(ptr, n); //Sorting the array
  
  if (n % 2 == 0){ //Even number of elements
    median_int = ( *(ptr + n/2) + *(ptr + (n-1)/2) ) / 2;
    /* Performing the calculations in float and rounding nearest 
     * integer is more accurate. 
     *
     * median_int =round((*(ptr +(n/2))+(*(ptr+((n-1)/2))))/2.0);
     *
     * This is avoided as it will give error when compiled
     * To make it work comile as: gcc stats.c -lm
     * */
    median = (unsigned char) median_int;    
  }
  else{  //odd number of elements
    median = *(ptr + (n/2)); 
  }
  return median;	
}	

unsigned char find_mean(unsigned char* ptr,unsigned int n){
  unsigned int mean = 0;
  unsigned char mean_uc;
//float mean_f; 
  unsigned int sum = 0;
  if ( ptr == 0){
    return 0; //Overcoming null pointer dereference
  }

  if (n < 1){
    n = 1;    //preventing division by zero
  }
  for(int i=0; i < n; i++){
  sum += *(ptr+i);
  }
  /*The division is converted to float and then rounded to nearest 
   * integer. This will produce more accurate results.
 
  mean_f=(float)sum/n;
  mean = round(mean_f);
  
  However, this is avoided due to error appearing during compilation.
  To use this compile as: gcc stats.c -lm
  */
  
  mean=sum/n;
  mean_uc=(unsigned char)(mean);//Converting to unsigned char
  return mean_uc;
}

unsigned char find_maximum(unsigned char* ptr,unsigned int n){
  unsigned char max;  
  if ( ptr == 0){
    return 0;//Overcoming null pointer dereference
  }
  for(int i=0; i<n; i++){
    if(i == 0){
      max = *(ptr+i);
    }
    if(*(ptr+i) >= max){
      max=*(ptr+i);
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char* ptr,unsigned int n){
  
  unsigned char min;	
  if ( ptr == 0){
    return 0;//Overcoming null pointer dereference
  }
  for(int i=0; i<n; i++){
    if(i == 0){
      min = *(ptr+i);
    }
    if(*(ptr+i)<=min){
      min=*(ptr+i);
    }	    
  }
  return min;
}

void sort_array(unsigned char* ptr,unsigned int n){
  /*Using the Bubble sort algorithm*/
  unsigned char temp;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
      if(*(ptr+j)<*(ptr+j+1)){
        temp=*(ptr+j);
	*(ptr+j)=*(ptr+j+1);
	*(ptr+j+1)=temp;
      }    
        	      
    }	    
  }
}	

