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
    uint64_t i;
    uint64_t j;

    i = INIT_INTEGER + ONE;
    while (dbl_ptr_buffer_map[i] != NULL)
    {
        j = INIT_INTEGER + ONE;
        while (dbl_ptr_buffer_map[i][j] != '\0')
        {
            if (dbl_ptr_buffer_map[i][j] != (ZERO + '0'))
            {
                manage_algorithm(&dbl_ptr_buffer_map[i][j],
                    dbl_ptr_buffer_map[i - ONE][j],
                    dbl_ptr_buffer_map[i][j - ONE],
                    dbl_ptr_buffer_map[i - ONE][j - ONE]);
            }
            j++;
        }
        i++;
    }    
}