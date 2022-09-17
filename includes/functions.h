/**
 * @file functions.h
 * @author Thomas Willson (thomas.willson@epitech.eu)
 * @brief All functions are here, they are all managing the creation
 * of the biggest square on map file.
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

// exec_bsq.c

/**
 * @brief This function execute all the function that find in \filename
 * the biggest square on a map.
 * 
 * @param filename filename path given in arguments.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t execute_biggest_square(const uint8_t *filename);

/**
 * @brief Change the map '.' to 1 and 'o' to 0 to make algo
 * perform easier.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 */
void change_char_in_map(uint8_t **dbl_ptr_buffer_map);

/**
 * @brief To allow the print of the biggest square we need to know where is the biggest
 * number to setup the range into index_biggest_square structure.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @param index_biggest_square Structure that contains the range of the biggest square.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t find_biggest_number_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s *index_biggest_square);

/**
 * @brief Print the biggest square into terminal.
 * 0 to 'o', in the range to 'x', rest to '.'.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @param index_biggest_square Structure that contains the range of the biggest square.
 */
void print_biggest_square_in_map(const uint8_t **dbl_ptr_buffer_map, struct index_biggest_square_s index_biggest_square);

// algorithm.c

/**
 * @brief Handle the algorithm `demineur inversé`.
 * (We start our 1d and 2d array at 1 to allow the function manage_algorithm to work).
 * Check out in google.
 * 
 * @param dbl_ptr_buffer_map Map in 2d array.
 */
void biggest_square_algorithm(uint8_t **dbl_ptr_buffer_map);

/**
 * @brief Change the char in according to the algorithm.
 * 
 * @param ptr_char_to_be_changed Char that will changed.
 * @param x North char in map.
 * @param y West char in map.
 * @param z North-West char in map.
 */
void manage_algorithm(uint8_t *ptr_char_to_be_changed, uint8_t x, uint8_t y, uint8_t z);

// error_handling.c

/**
 * @brief Handle errors in map.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t error_handling(uint8_t **dbl_ptr_buffer_map);

/**
 * @brief The first line in map must be a digit.
 * Here we check if it doesn't contain char, with \strtoul function.
 * (man strtoul)
 * 
 * @param lineptr ptr to the first line of map.
 * @param nb_lines if the first line is a digit, this variable will be initialized.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t check_first_line_file(const uint8_t *lineptr, uint64_t *nb_lines);

/**
 * @brief Check if the number of lines is correct according to the variable \nb_lines.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @param nb_lines Number of total lines in map.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t check_nb_lines(const uint8_t **dbl_ptr_buffer_map, uint64_t nb_lines);

/**
 * @brief Only '.', 'o' and '\n' are allowed in the file.
 * So we check that in this function.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t check_for_characters_in_lines(const uint8_t **dbl_ptr_buffer_map);

/**
 * @brief All lines must have the same length.
 * Here we take the first line and compare it to the other lines length.
 * 
 * @param dbl_ptr_buffer_map Map in a 2d array.
 * @return uint32_t EXIT_SUCCESS(0) in case of success / EXIT_FAILURE(1) in case of failure.
 */
uint32_t check_for_same_lines_length(const uint8_t **dbl_ptr_buffer_map);

// array.c

/**
 * @brief Return the length of a 2d array.
 * 
 * @param dbl_string_ptr 2d array. (MUST HAVE NULL AT THE END)
 * @return uint64_t Length of the 2d array.
 */
uint64_t length_dbl_string_ptr(const uint8_t **dbl_string_ptr);

/**
 * @brief Print a 2d array with index + string.
 * 
 * @param dbl_string_ptr 2d array. (MUST HAVE NULL AT THE END)
 */
void print_dbl_string_ptr(const uint8_t **dbl_string_ptr);

/**
 * @brief Free a 2d array.
 * 
 * @param dbl_string_ptr 2d array. (MUST HAVE NULL AT THE END)
 */
void free_dbl_string_ptr(uint8_t **dbl_string_ptr);

// io_init.c
#ifdef IO_STREAM_DEFINITION
# include "define.h"
/**
 * @brief Wrapper of io function fopen, popen / fclose, pclose.
 * Open the __ptr passed as parameter with the mode __modes.
 * This function is using getline to take line and fill __dbl_ptr_container
 * that will contains all the line by using realloc each iteration.
 * Set NULL at end of __dbl_ptr_container.
 * 
 * man fopen, man fclose, man popen or man pclose.
 * 
 * @param __dbl_ptr_container 2d array map that contains data (here is a ptr to 2d array).
 * @param __ptr filename or commandname.
 * @param __modes mode ("r" / "r+" / "w" / "w+" / "a" / "a+").
 * @param __io_stream_open fopen or popen function.
 * @param __io_stream_close fclose or pclose function.
 * @return int32_t Return 0 in case of success or -1 in case of failure.
 */
int32_t io_stream_init(char ***__restrict __dbl_ptr_container, const char *__restrict __ptr, const char *__restrict __modes,
    __io_stream_open_fn_t __io_stream_open, __io_stream_close_fn_t __io_stream_close) __nonnull((1, 2, 3, 4, 5));
#endif
