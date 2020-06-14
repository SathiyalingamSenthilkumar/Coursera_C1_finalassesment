/**********************************************************
 * Sathiya Lingam Senthil Kumar
 * Header file corresponding to data.c
 *
 * ********************************************************/

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Integer-to-ASCII
 *
 * Coverts standard integer data type into an ASCII string.Support 
 * bases 2 to 16. The converted string is copied a location which 
 * is tracked by a pointer. The function returns the length of the
 * converterted data.
 * 
 * @param data The data to be converted
 * @param ptr Points to the location where the converted string is
 *            stored
 * @param base Base of the integer data given
 *
 * @return Returns the length of the data           
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer
 *
 * Coverts a string data to integer. supports bases from 2 to 16.
 * The converted 32 bit integer is returned.
 *
 * @param ptr Pointer to the character string to be converted
 * @param digits The number of digits in the character
 * @param base the base of the integer
 *
 * @return The converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

