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
    uint64_t i;
    uint64_t j;

    i = INIT_INTEGER;
    while (dbl_ptr_buffer_map[i] != NULL)
    {
        j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[i][j] != '\0')
        {
            if (dbl_ptr_buffer_map[i][j] == '.')
            {
                dbl_ptr_buffer_map[i][j] = ONE + '0';
            }
            else
            {
                dbl_ptr_buffer_map[i][j] = ZERO + '0';
            }
            j++;
        }
        i++;
    }
}

void find_biggest_number_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s *index_biggest_square)
{
    uint32_t i;
    uint32_t j;
    uint32_t limit;

    (void) memset(index_biggest_square, INIT_STRUCT, sizeof(struct index_biggest_square_s));
    i = INIT_INTEGER;
    limit = INIT_INTEGER;
    while (dbl_ptr_buffer_map[i] != NULL)
    {
        j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[i][j] != '\0')
        {
            if (dbl_ptr_buffer_map[i][j] > limit)
            {
                limit = dbl_ptr_buffer_map[i][j];
                index_biggest_square->limit = limit;
                index_biggest_square->i = i;
                index_biggest_square->j = j;
            }
            j++;
        }
        i++;
    }
}

void print_biggest_square_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s index_biggest_square)
{
    uint32_t i;
    uint32_t j;

    i = INIT_INTEGER;
    while (dbl_ptr_buffer_map[i] != NULL)
    {
        j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[i][j] != '\0')
        {
            if ((ZERO + '0') == dbl_ptr_buffer_map[i][j])
            {
                fprintf(stdout, "%c", 'o');
            }
            else if ((int32_t)(i) > (int32_t)(index_biggest_square.i - (index_biggest_square.limit - '0'))
                && (int32_t)(j) > (int32_t)(index_biggest_square.j - (index_biggest_square.limit - '0'))
                && i <= index_biggest_square.i && j <= index_biggest_square.j)
            {
                fprintf(stdout, "%c", 'x');
            }
            else
            {
                fprintf(stdout, "%c", '.');
            }
            j++;
        }
        fprintf(stdout, "%c", '\n');
        i++;
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
    find_biggest_number_in_map((const uint8_t **) &dbl_ptr_buffer_map[ONE], &index_biggest_square);
    print_biggest_square_in_map((const uint8_t **) &dbl_ptr_buffer_map[ONE], index_biggest_square);
    free_dbl_string_ptr(dbl_ptr_buffer_map);
    return EXIT_SUCCESS;
}
