/*
 * <AUTHOR>
 * <DATE>
 *
 * CS 441/541 : Memory Management Performance Template
 */
#include "support.h"

/*****************************
 * Global Variables
 *****************************/
int MAX_ITERS = 10000;

/*
 * Executes a scalar multiplication using a the ij pattern for loop execution.
 *   matrix : Matrix to be used for calculations  
 *   scalar : Scalar to use for calculations 
 *   N : Size of matrix 
 */
double run_experiment_ij(mtype_t *matrix, mtype_t scalar, int N);

/*
 * Executes a scalar multiplication using a the ji pattern for loop execution.
 *   matrix : Matrix to be used for calculations  
 *   scalar : Scalar to use for calculations 
 *   N : Size of matrix 
 */
double run_experiment_ji(mtype_t *matrix, mtype_t scalar, int N);

/* Check if the provided char array can be converted to an integer 
 *   str : Char array to be checked
 * Returns 0 if can be converted to an integer, -1 otherwise. 
 * 
 */
int is_valid_int(char *str);
