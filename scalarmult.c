/*
 * Phillip Sime
 * 11-18-2013
 *
 * CS 441 : Project 4
 */
#include "scalarmult.h"

int main(int argc, char * argv[]) {    
    int N;
    double time;
    mtype_t *matrix = NULL;
    mtype_t scalar = 2;
    
    // Initialize the support library
    support_init();
    
    /* run_experiment_ij */
    printf("Running run_experiment_ij()\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix, N);
        time = run_experiment_ij(matrix, scalar, N);
        printf("FLOPS = %f\n", (1 * N * N) / time);
        N = N*2;
    }
    
    /* run_experiment_ji */
    printf("Running run_experiment_ji()\n");
    for(N = 2; N <= 1024;){
        allocate_matrix(&matrix, N);
        time = run_experiment_ji(matrix, scalar, N);
        printf("FLOPS = %f\n", (1 * N * N) / time);
        N = N*2;
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
                matrix[ GET_INDEX(j, i, N) ] = scalar * matrix[ GET_INDEX(j, i, N) ];
            }
        }
    }
    end = get_time();
    final_time = diff_timers(start, end) / MAX_ITERS;
    
    return final_time;
}