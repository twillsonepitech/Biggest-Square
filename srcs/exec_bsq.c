/**
 * @file exec_bsq.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Execute biggest square on filename.
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "define.h"
#include "functions.h"
#include "../Lib-IO/includes/io_stream.h"

void change_char_in_map(uint8_t **dbl_ptr_buffer_map)
{
    uint64_t __i;
    uint64_t __j;

    __i = INIT_INTEGER;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        __j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[__i][__j] != '\0')
        {
            if (dbl_ptr_buffer_map[__i][__j] == '.')
            {
                dbl_ptr_buffer_map[__i][__j] = ONE + '0';
            }
            else
            {
                dbl_ptr_buffer_map[__i][__j] = ZERO + '0';
            }
            __j++;
        }
        __i++;
    }
}

uint8_t find_biggest_number_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s *index_biggest_square)
{
    uint32_t __i;
    uint32_t __j;
    uint32_t __limit;
    void *ptr_return_from_function;

    ptr_return_from_function = memset(index_biggest_square, INIT_STRUCT, sizeof(struct index_biggest_square_s));
    if (NULL == ptr_return_from_function)
    {
        LOG_ERROR("memset() function: FAILURE.");
        return EXIT_FAILURE;
    }
    __i = INIT_INTEGER;
    __limit = INIT_INTEGER;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        __j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[__i][__j] != '\0')
        {
            if (dbl_ptr_buffer_map[__i][__j] > __limit)
            {
                __limit = dbl_ptr_buffer_map[__i][__j];
                index_biggest_square->__limit = __limit;
                index_biggest_square->__i = __i;
                index_biggest_square->__j = __j;
            }
            __j++;
        }
        __i++;
    }
    return EXIT_SUCCESS;
}

void print_biggest_square_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s index_biggest_square)
{
    uint32_t __i;
    uint32_t __j;

    __i = INIT_INTEGER;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        __j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[__i][__j] != '\0')
        {
            if ((ZERO + '0') == dbl_ptr_buffer_map[__i][__j])
            {
                fprintf(stdout, "%c", 'o');
            }
            else if ((int32_t)(__i) > (int32_t)(index_biggest_square.__i - (index_biggest_square.__limit - '0'))
                && (int32_t)(__j) > (int32_t)(index_biggest_square.__j - (index_biggest_square.__limit - '0'))
                && __i <= index_biggest_square.__i && __j <= index_biggest_square.__j)
            {
                fprintf(stdout, "%c", 'x');
            }
            else
            {
                fprintf(stdout, "%c", '.');
            }
            __j++;
        }
        fprintf(stdout, "%c", '\n');
        __i++;
    }
}

uint8_t execute_biggest_square(const uint8_t *filename)
{
    int32_t return_from_function;
    uint8_t **dbl_ptr_buffer_map;
    struct index_biggest_square_s index_biggest_square;

    return_from_function = io_stream_init((char ***) &dbl_ptr_buffer_map, (const char *) filename, "r", &fopen, &fclose);
    if (EXIT_FUNCTION_ERR == return_from_function)
    {
        return EXIT_FAILURE;
    }
    return_from_function = error_handling(dbl_ptr_buffer_map);
    if (EXIT_FAILURE == return_from_function)
    {
        free_dbl_string_ptr(dbl_ptr_buffer_map);
        return EXIT_FAILURE;
    }
    change_char_in_map(&dbl_ptr_buffer_map[ONE]);
    biggest_square_algorithm(&dbl_ptr_buffer_map[ONE]);
    return_from_function = find_biggest_number_in_map((const uint8_t **) &dbl_ptr_buffer_map[ONE], &index_biggest_square);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE;
    }
    print_biggest_square_in_map((const uint8_t **) &dbl_ptr_buffer_map[ONE], index_biggest_square);
    free_dbl_string_ptr(dbl_ptr_buffer_map);
    return EXIT_SUCCESS;
}
