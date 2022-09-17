/**
 * @file define.h
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief Define, constant that are used for return value or check function return.
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#define ZERO    (0)
#define ONE     (1)
#define TWO     (2)
#define THREE   (3)

#if !defined(EXIT_SUCCESS)
# define EXIT_SUCCESS    (0)
#endif // EXIT_SUCCESS

#if !defined(EXIT_FAILURE)
# define EXIT_FAILURE    (1)
#endif // EXIT_FAILURE

#define EXIT_FUNCTION_ERR   (-1)
#define EXIT_FAILURE_EPI    (84)

#define INIT_INTEGER    (0)
#define INIT_POINTER    (NULL)
#define INIT_STRUCT     (0)
#define FILE_INDEX      (1)

#include <stdio.h>
#define LOG_ERROR(message)      fprintf(stderr, "[\033[0;31mERROR\033[0m]\t[MESSAGE: %s].\n", message)

#if !defined(IO_STREAM_DEFINITION)
# define IO_STREAM_DEFINITION    (1)
typedef FILE *(*__io_stream_open_fn_t)(const char *, const char *);
typedef int (*__io_stream_close_fn_t)(FILE *);
struct buffer_s { int64_t readline; FILE *__stream; uint64_t __n; uint8_t *__lineptr; };
#endif // IO_STREAM_DEFINITION

struct index_biggest_square_s { uint32_t __i; uint32_t __j; uint32_t __limit; };
