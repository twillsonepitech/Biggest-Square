/**
 * @file algorithm.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Algorithm to find the biggest square on map.
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>
#include "define.h"
#include "functions.h"

void manage_algorithm(uint8_t *ptr_char_to_be_changed, uint8_t x, uint8_t y, uint8_t z)
{
    if (x < y)
    {
        y = x;
    }
    if (y < z)
    {
        z = y;
    }
    *ptr_char_to_be_changed = z + 1;
}

void biggest_square_algorithm(uint8_t **dbl_ptr_buffer_map)
{
    uint64_t __i;
    uint64_t __j;

    __i = INIT_INTEGER + ONE;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        __j = INIT_INTEGER + ONE;
        while (dbl_ptr_buffer_map[__i][__j] != '\0')
        {
            if (dbl_ptr_buffer_map[__i][__j] != (ZERO + '0'))
            {
                manage_algorithm(&dbl_ptr_buffer_map[__i][__j],
                    dbl_ptr_buffer_map[__i - ONE][__j],
                    dbl_ptr_buffer_map[__i][__j - ONE],
                    dbl_ptr_buffer_map[__i - ONE][__j - ONE]);
            }
            __j++;
        }
        __i++;
    }    
}