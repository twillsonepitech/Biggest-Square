/**
 * @file error_handling.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Handle error from maps.
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include "define.h"
#include "functions.h"

#define FIRST_LINE_FILE (0)

uint32_t check_first_line_file(const uint8_t *lineptr, uint64_t *nb_lines)
{
    uint8_t *endptr;

    errno = INIT_INTEGER;
    *nb_lines = strtoul((const char *)lineptr, (char **)&endptr, 10);
    if ((errno == ERANGE && *nb_lines == ULONG_MAX) || (errno != ZERO && *nb_lines == ZERO))
    {
        LOG_ERROR("strtoul() function: FAILURE.");
        return EXIT_FAILURE;
    }
    if (ZERO == *nb_lines)
    {
        LOG_ERROR("Number of lines must be >= 1.");
        return EXIT_FAILURE;
    }
    if (endptr == lineptr)
    {
        LOG_ERROR("strtoul() function: No digits were found.");
        return EXIT_FAILURE;
    }
    if (*endptr != '\0')
    {
        LOG_ERROR("strtoul() function: Characters were found.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint32_t check_nb_lines(const uint8_t **dbl_ptr_buffer_map, uint64_t nb_lines)
{
    uint64_t length_dbl_ptr_buffer_map;

    length_dbl_ptr_buffer_map = length_dbl_string_ptr(dbl_ptr_buffer_map);
    if (length_dbl_ptr_buffer_map != nb_lines)
    {
        LOG_ERROR("No enough lines compare to the number of lines in first line of file.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

uint32_t check_for_characters_in_lines(const uint8_t **dbl_ptr_buffer_map)
{
    uint64_t __i;
    uint64_t __j;

    __i = INIT_INTEGER;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        __j = INIT_INTEGER;
        while (dbl_ptr_buffer_map[__i][__j] != '\0')
        {
            if (dbl_ptr_buffer_map[__i][__j] != '.' && dbl_ptr_buffer_map[__i][__j] != 'o')
            {
                LOG_ERROR("Bad character founded in file (must be 'o' or '.' only).");
                return EXIT_FAILURE;
            }
            __j++;
        }
        __i++;
    }
    return EXIT_SUCCESS;
}

uint32_t check_for_same_lines_length(const uint8_t **dbl_ptr_buffer_map)
{
    uint64_t __i;
    uint64_t length_lineptr;
    uint64_t length_curr_lineptr;

    length_lineptr = strlen((const char *)dbl_ptr_buffer_map[ZERO]);
    __i = INIT_INTEGER + ONE;
    while (dbl_ptr_buffer_map[__i] != NULL)
    {
        length_curr_lineptr = strlen((const char *)dbl_ptr_buffer_map[__i]);
        if (length_lineptr != length_curr_lineptr)
        {
            LOG_ERROR("Lines are not same length.");
            return EXIT_FAILURE;
        }
        __i++;
    }
    return EXIT_SUCCESS;
}

uint32_t error_handling(uint8_t **dbl_ptr_buffer_map)
{
    int32_t return_from_function;
    uint64_t nb_lines;

    return_from_function = check_first_line_file(dbl_ptr_buffer_map[FIRST_LINE_FILE], &nb_lines);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE;
    }
    return_from_function = check_nb_lines((const uint8_t **)&dbl_ptr_buffer_map[ONE], nb_lines);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE;
    }
    return_from_function = check_for_characters_in_lines((const uint8_t **)&dbl_ptr_buffer_map[ONE]);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE;
    }
    return_from_function = check_for_same_lines_length((const uint8_t **)&dbl_ptr_buffer_map[ONE]);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
