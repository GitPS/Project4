/*
 * Phillip Sime
 * 11-18-2013
 *
 * CS 441 : Project 4
 */
#include "scalarmult.h"

int main(int argc, char * argv[]) {    
    int N;
    int max_N = 1024;
    double time;
    mtype_t *matrix = NULL;
    mtype_t scalar = 1;
    
    // Initialize the support library
    support_init();
    
    /* Command line argument handling */
    if(argc >= 2) {
        if(is_valid_int(argv[1]) == 0){
            max_N = (int)strtol(argv[1], NULL, 10);
        }
    }
    
    /* run_experiment_ij */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_ij()\n\n");
    for(N = 2; N <= max_N;){
        allocate_matrix(&matrix, N);
        time = run_experiment_ij(matrix, scalar, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        printf("megaFLOPS = %f\n\n", (1 * N * N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix != NULL){
            free(matrix);
            matrix = NULL;
        }
    }
    
    /* run_experiment_ji */
    printf("\n---------------------------\n\n");
    printf("Executing: run_experiment_ji()\n\n");
    for(N = 2; N <= max_N;){
        allocate_matrix(&matrix, N);
        time = run_experiment_ji(matrix, scalar, N);
        printf("Matrix Size in bytes: %lu\n", sizeof(mtype_t) * N);
        printf("megaFLOPS = %f\n\n", (1 * N * N) / time / 1000000);
        N = N*2;
        
        /* Cleanup */
        if(matrix != NULL){
            free(matrix);
            matrix = NULL;
        }
    }
    
    /* Cleanup */
    if(matrix != NULL){
        free(matrix);
        matrix = NULL;
    }

    // Finalize the support library
    support_finalize();
    
    return 0;
}

double run_experiment_ij(mtype_t *matrix, mtype_t scalar, int N){
    int i, j, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                matrix[ GET_INDEX(i, j, N) ] = scalar * matrix[ GET_INDEX(i, j, N) ];
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}

double run_experiment_ji(mtype_t *matrix, mtype_t scalar, int N){
    int i, j, iter;
    hptimer_t start, end;
    double final_time;
    
    start = get_time();
    for(iter = 0; iter < MAX_ITERS; ++iter){
        for(j = 0; j < N; ++j){
            for(i = 0; i < N; ++i){
                matrix[ GET_INDEX(i, j, N) ] = scalar * matrix[ GET_INDEX(i, j, N) ];
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}