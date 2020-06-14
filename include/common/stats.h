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
 * @brief File contains function declarations and documentations.
 *
 * Function declarations and the documenteations of the function that are used 
 * in stats.c are declared in this header file.
 *
 * @author Sathiya Lingam Senthil Kumar
 * @date 28 May 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Function Documentations and Declarations*/ 

/*****************************************************************************
 * Function: print_array
 * @brief <Prints the unsigned char array on the screen>
 *
 * The function prints the unsigned char array of a given size on the screen.
 *
 * @param ptr  Pointer to the array to be printed
 * @param n Size of the array
 * 
 *
 * @return No return(void)
 */
void print_array(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: print_statistics
 * @brief Prints the statistics of the given unsigned char array
 *
 * The function that prints the statistics of the given unsigned char array of
 * size of a given size. The statical analysis includes the maximum, minimum, 
 * mean, and median.
 *
 * @param ptr Pointer to the array of unsigned char
 * @param n size of the array
 *
 *
 * @return No return(void)
 */
void print_statistics(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: find_median
 * @brief Finds the median of the given array
 *
 * The function is used to find the median of a given set of unsigned 
 * char array of a given size. 
 *
 * @param ptr Pointer to the unsigned char array
 * @param n size of the array
 *
 * @return The median of the array
 */
unsigned char find_median(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: find_mean
 * @brief Finds the mean of the given array
 *
 * The function is used to find the mean of a given set of unsigned
 * char array of a given size.
 *
 * @param ptr Pointer to the array
 * @param n size of the array
 *
 *
 * @return The mean of the array
 */
unsigned char find_mean(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: find_maximum
 * @brief Finds the largest element of the given array.
 *
 * The function is used to find the largest element of an unsigned char array
 * of a given size.
 *
 * @param ptr Pointer to the array 
 * @param n size of the array
 *
 *
 * @return The largest element of the array
 */
unsigned char find_maximum(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: find_manimum
 * @brief Finds the smallest element of the given array.
 *
 * The function is used to find the smallest element of an unsigned char array
 * of a given size.
 *
 * @param ptr Pointer to the array
 * @param n size of the array
 *
 *
 * @return The smallest element of the array
 */
unsigned char find_minimum(unsigned char* ptr,unsigned int n);

/*****************************************************************************
 * Function: sort_array
 * @brief Sort in descending order
 *
 * The function is used to to sort a given array from largest to smallest.
 *
 * @param ptr Pointer to the array
 * @param n size of the array
 *
 *
 * @return No return
 */
void sort_array(unsigned char* ptr,unsigned int n);




#endif /* __STATS_H__ */
