/*
* Add NetID and names of all project partners
 NetID: yc1284
 Name: Yen-Lin Chien
 Course Number: CS 518
 iLab Hostname: cp.cs.rutgers.edu
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_TOP_BITS 4 // top bits to extract
#define BITMAP_SIZE 4 // size of the bitmap array
#define SET_BIT_INDEX 17 // bit index to set
#define GET_BIT_INDEX 17 // bit index to read

static unsigned int myaddress = 4026544704;   // Binary would be 11110000000000000011001001000000

/* 
 * Function 1: EXTRACTING OUTER (TOP-ORDER) BITS
 */
static unsigned int get_top_bits(unsigned int value, int num_bits) {
	// Implement your code here
    // get total bits of myaddress
    int total_num_bits = sizeof(unsigned int) << 3;
    // clear several last bits to get several top bits by moving the bits of myaddress to the right
    int right_shift_offset = total_num_bits - num_bits;
    return (value >> right_shift_offset);
}


/* 
 * Function 2: SETTING A BIT AT AN INDEX 
 * Function to set a bit at "index" bitmap
 */
static void set_bit_at_index(char *bitmap, int index) {
    // Implement your code here
    // find out which byte of bitmap the specified index resides in
    unsigned int byte_index = index >> 3;
    // count number of bits from right side of the byte to reach the specified index
    unsigned int left_shift_offset = 7 - (index & 0x7);
    // use one hot bit mask to set only the index position's bit as 1
    bitmap[byte_index] |= (1 << left_shift_offset);
}


/* 
 * Function 3: GETTING A BIT AT AN INDEX 
 * Function to get a bit at "index"
 */
static int get_bit_at_index(char *bitmap, int index) {
    // Get to the location in the character bitmap array
    // Implement your code here
    // find out which byte of bitmap the specified index resides in
    unsigned int byte_index = index >> 3;
    // count number of bits from right side of the byte to reach the specified index
    unsigned int left_shift_offset = 7 - (index & 0x7);
    // use one hot bit mask and then right shift to get only the index's bit value
    return ((bitmap[byte_index] & (1 << left_shift_offset)) >> left_shift_offset);
    
}


int main() {

    /* 
     * Function 1: Finding value of top order (outer) bits Now let’s say we
     * need to extract just the top (outer) 4 bits (1111), which is decimal 15  
    */
    unsigned int outer_bits_value = get_top_bits (myaddress , NUM_TOP_BITS);
    printf("Function 1: Outer bits value %u \n", outer_bits_value); 
    printf("\n");

    /* 
     * Function 2 and 3: Checking if a bit is set or not
     */
    char *bitmap = (char *)malloc(BITMAP_SIZE);  // We can store 32 bits (4*8-bit per character)
    memset(bitmap,0, BITMAP_SIZE); // clear everything
    
    /* 
     * Let's try to set the bit 
     */
    set_bit_at_index(bitmap, SET_BIT_INDEX);
    
    /* 
     * Let's try to read bit)
     */
    printf("Function 3: The value at %dth location %d\n", 
            GET_BIT_INDEX, get_bit_at_index(bitmap, GET_BIT_INDEX));
            
    return 0;
}
