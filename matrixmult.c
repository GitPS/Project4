/*
 * Phillip Sime
 * 11-21-2013
 *
 * CS 441 : Memory Management Performance Template
 */
#include "matrixmult.h"

int main(int argc, char * argv[]) {
    int N;
    long long_N; // Needed to prevent overflow 
    double time;
    mtype_t *matrix_a = NULL;
    mtype_t *matrix_b = NULL;
    mtype_t *matrix_c = NULL;
    
    // Initialize the support library
    support_init();
    
    /* run_experiment_ijk */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_ijk()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_ijk(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    /* run_experiment_ikj */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_ikj()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_ikj(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    /* run_experiment_kji */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_kji()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_kji(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    /* run_experiment_kij */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_kij()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_kij(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    /* run_experiment_jki */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_jki()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_jki(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    /* run_experiment_jik */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_jik()\n\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix_a, N);
        allocate_matrix(&matrix_b, N);
        allocate_matrix(&matrix_c, N);
        time = run_experiment_jik(matrix_a, matrix_b, matrix_c, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        long_N = N;
        printf("megaFLOPS = %f\n\n", (2 * long_N * long_N * long_N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix_a != NULL){
            free(matrix_a);
            matrix_a = NULL;
        }
        if(matrix_b != NULL){
            free(matrix_b);
            matrix_b = NULL;
        }
        if(matrix_c != NULL){
            free(matrix_c);
            matrix_c = NULL;
        }
    }
    
    // Finalize the support library
    support_finalize();

    return 0;
}

double run_experiment_ijk(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                for(k = 0; k < N; ++k){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;    
}

double run_experiment_ikj(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(i = 0; i < N; ++i){
            for(k = 0; k < N; ++k){
                for(j = 0; j < N; ++j){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;    
}

double run_experiment_kji(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(k = 0; k < N; ++k){
            for(j = 0; j < N; ++j){
                for(i = 0; i < N; ++i){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}

double run_experiment_kij(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(k = 0; k < N; ++k){
            for(i = 0; i < N; ++i){
                for(j = 0; j < N; ++j){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}

double run_experiment_jki(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(j = 0; j < N; ++j){
            for(k = 0; k < N; ++k){
                for(i = 0; i < N; ++i){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}

double run_experiment_jik(mtype_t *matrix_a, mtype_t *matrix_b, mtype_t *matrix_c, int N){
    int i, j, k, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(j = 0; j < N; ++j){
            for(i = 0; i < N; ++i){
                for(k = 0; k < N; ++k){
                    matrix_c[ GET_INDEX(i, j, N) ] += matrix_a[ GET_INDEX(i, k, N) ] * matrix_b[ GET_INDEX(k, j, N) ];
                }
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}
