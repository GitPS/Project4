/*
 * <AUTHOR>
 * <DATE>
 *
 * CS 441/541 : Memory Management Performance Template
 */
#include "support.h"

int MAX_ITERS = 100;

/*
 * Executes a matrix multiplication using a the ijk pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_ijk(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);

/*
 * Executes a matrix multiplication using a the ikj pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_ikj(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);

/*
 * Executes a matrix multiplication using a the jki pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_jki(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);

/*
 * Executes a matrix multiplication using a the jik pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_jik(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);

/*
 * Executes a matrix multiplication using a the kij pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_kij(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);

/*
 * Executes a matrix multiplication using a the kji pattern for loop execution.
 *   matrix_a : Matrix A 
 *   matrix_b : Matrix B
 *   matrix_c : Matrix C
 *   N : Size of matrices
 */
double run_experiment_kji(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N);
