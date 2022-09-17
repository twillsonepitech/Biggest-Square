/**
 * @file array.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Array definition (string to double string ptr, free, ...)
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdint.h>
#include "define.h"

uint64_t length_dbl_string_ptr(uint8_t **dbl_string_ptr)
{
    uint64_t __i;

    __i = INIT_INTEGER;
    while (dbl_string_ptr[__i] != NULL)
    {
        __i++;
    }
    return __i;
}

void print_map(const uint8_t **dbl_string_ptr)
{
    uint64_t __i;

    __i = INIT_INTEGER;
    while (dbl_string_ptr[__i] != NULL)
    {
        dprintf(1, "[%ld]: [%s]\n", __i, dbl_string_ptr[__i]);
        __i++;
    }
}

void free_dbl_string_ptr(uint8_t **dbl_string_ptr)
{
    uint64_t __i;

    __i = INIT_INTEGER;
    while (dbl_string_ptr[__i] != NULL)
    {
        free(dbl_string_ptr[__i]);
        __i++;
    }
    free(dbl_string_ptr);
}