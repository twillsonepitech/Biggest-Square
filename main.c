/**
 * @file main.c
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Main, handle errors and bsq.
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>
#include "define.h"
#include "functions.h"

int32_t main(int32_t argc, char const *argv[])
{
    int32_t return_from_function;
    const uint8_t *filename;

    if (TWO != argc)
    {
        LOG_ERROR("Bad number of arguments");
        return EXIT_FAILURE;
    }
    filename = (const uint8_t *)argv[FILE_INDEX];
    return_from_function = execute_biggest_square(filename);
    if (EXIT_FAILURE == return_from_function)
    {
        return EXIT_FAILURE_EPI;
    }
    return EXIT_SUCCESS;
}
