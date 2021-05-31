#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#include <omp.h>   

#define A 240
#define e 2.718281
#define SHARED_PARAMS num_threads(4) default(none)

double extended_random(unsigned int *seedp, int min, int max) {
    return (rand_r(seedp) % (max + 1 - min)) + min;
}

void log_array(const char* msg, size_t start, size_t end, double *arr) {
    printf("%s", msg);
    for (size_t k = start; k < end; k++){
        printf("%f ", arr[k]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int i, N;
    struct timeval T1, T2;
    long delta_ms;

    if(argc <= 1){
        fprintf(stderr, "%s", "Error: Invalid arguments\n");
        exit(1);
    } else {
        N = atoi(argv[1]);
    }
    gettimeofday(&T1, NULL);
    unsigned int *p = (unsigned int *)malloc(sizeof(unsigned int));
    /*
        NUMBER OF REPETITIONS
    */
    for (i = 0; i < 50; i++){
        *p = i;
        double *M1 = (double *)malloc(N * sizeof(double));
        double *M2 = (double *)malloc((N/2) * sizeof(double));
        double *M2_copy = (double *)malloc((N/2) * sizeof(double));
        size_t j = 0;
        // START: filling up arrays. can't parallel
        for (j = 0; j < N; j++)
        {
            M1[j] = extended_random(p, 1, A);
        }

        for (size_t k = 0; k < N/2; k++){
            M2[k] = extended_random(p, A, 10*A);
        }
        // END: filling up arrays.

        #pragma omp parallel for SHARED_PARAMS private(j) shared(M1, N)
        for (j = 0; j < N; j++){
            M1[j] = cbrt((M1[j]/e));
        }
        #pragma omp parallel for SHARED_PARAMS private(j) shared(M2_copy, M2, N)
        for (j = 0; j < N/2; j++){
            M2_copy[j] = M2[j];
        }
        #pragma omp parallel for SHARED_PARAMS private(j) shared(M2_copy, M2, N)
        for (j = 1; j < N/2; j++){
            M2[j] += M2_copy[j-1];
            M2[j] = pow(log10(M2[j]), e);
        }
        #pragma omp parallel for SHARED_PARAMS private(j) shared(M1, M2, N)
        for (j = 0; j < N/2; j++){
            M2[j] = fabs(M1[j] - M2[j]);
        }
        double temp = 0;
        j = 0;
        size_t k=1;
        #pragma omp parallel for SHARED_PARAMS private(j, k, temp) shared(M1, M2, N)
        for(k=1;k<N/2;k++){
            temp=M2[k];
            j=k-1;
            while((temp<M2[j])&&(j>=0)){
                M2[j+1]=M2[j];
                j=j-1;
            }
            M2[j+1]=temp;
        }
        double min_num = 0;
        // START: looking for first positive number.
        for(size_t k=0;k<N/2;k++) {
            if(M2[k] > 0){
                min_num = M2[k];
                break;
            }
        }
        // END: looking for first positive number.

        #pragma omp parallel for SHARED_PARAMS private(k) shared(M2, min_num, N)
        for(k=1;k<N/2;k++) {
            if(M2[k] < min_num){
                min_num = M2[k];
            }
        }
        double sum = 0;
        #pragma omp parallel for SHARED_PARAMS private(k) shared(M2, min_num, N) reduction (+:sum)
        for (k = 0; k < N/2; k++){
            int check_num = (int)(M2[k] / min_num);
            if(check_num % 2 == 0) {
                sum += sin(M2[k]);
            }
        }

        free(M1);
        free(M2);
        free(M2_copy);
        //printf("%f\n", sum);
    }
    gettimeofday(&T2, NULL);
    delta_ms = 1000*(T2.tv_sec - T1.tv_sec) + (T2.tv_usec - T1.tv_usec)/1000;
    printf("N=%d. Milliseconds passed: %ld\n", N, delta_ms);

    return 0;
}
