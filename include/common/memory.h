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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/* Functions that are added   */
/**
 * @brief move from source to destination
 *
 * Takes two byte pointers one source, one destination and length. Move 
 * from source to destination
 *
 * @param src pointer to the source
 * @param dst pointer to the destination
 * @param length length of bytes
 *
 * @return pointer to the destination
 * */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy from source to destination
 * 
 * Takes two byte pointers one source, one destination and length. Copies 
 * from source to destination
 *
 * @param src pointer to the source
 * @param dst pointer to the destination
 * @param length length of bytes
 *
 * @return pointer to the destination 
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * brief set all locations with given value
 *
 * Takes a pointer to the source memory location, length in bytes, 
 * and set all the locations of that memory to a given value.
 *
 * @param src pointer to the source
 * @param length length in bytes
 * @param value Value to be stored
 *
 * @return a poiter to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief zero out the specified memory
 *
 * Takes a pointer to a momory and length in bytes and zero out
 * all the memory.
 *
 * @param src source pointer
 * @param length size in bytes
 *
 * @return a pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @Brief reverse the order of bytes
 *
 * Takes a pointer to a memory location and a length in bytes
 * to reverse the order of all the bytes
 *
 * @param src pointer to the source location
 * @param length length in bytes
 *
 * @return a pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief allocate dynamic memory
 *
 * Takes the number of words as input and allocate dynamic
 * memory
 *
 * @param length number of words to allocate memory
 *
 * @return a pointer if successful or returns null pointer
 *
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free the dynamic memory
 *
 * Frees the dynamic memory allocated by proving the pointer
 * to the src function
 *
 * @param src pointer to memory that needs to be freed
 *
 * @retun void 
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
