#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <algorithm>
#include "ipp.h"
#include "ippcore.h"
#include "ippvm.h"

#include "ippwrap.h"

#define A 240
#define e 2.718281

double extended_random(unsigned int *seedp, int min, int max) {
    return (rand_r(seedp) % (max + 1 - min)) + min;
}

int main(int argc, char* argv[])
{
    ippInit();

    int i, N;
    struct timeval T1, T2;
    long delta_ms;

    if(argc <= 1){
        perror("Error: Invalid arguments\n");
        exit(1);
    } else {
        N = atoi(argv[1]);
    }
    gettimeofday(&T1, NULL);
    unsigned int *p = (unsigned int*) malloc(sizeof(unsigned int));
    for (i = 0; i < 50; i++){
        *p = i;
        double *M1 = (double*)malloc(N * sizeof(double));
        double *M1_BUFFER = (double*)malloc(N * sizeof(double));
        double *e_arr = (double*)malloc(N * sizeof(double));
        double *M2 = (double*)malloc((N/2) * sizeof(double));
        double *M2_BUFFER = (double*)malloc((N/2) * sizeof(double));
        double *M2_copy = (double*)malloc((N/2) * sizeof(double));
        double *SUM = (double*)malloc((N/2) * sizeof(double));


        for (size_t j = 0; j < N; j++){
            M1[j] = extended_random(p, 1, A);
        }
        for (size_t k = 0; k < N/2; k++){
            M2[k] = extended_random(p, A, 10*A);
        }
        divC(M1, e, N);
        cbrt(M1, M1_BUFFER, N);
        for (size_t k = 0; k < N/2; k++){
            M2_copy[k] = M2[k];
        }
        std::fill_n(e_arr, N, e);
        for (size_t k = 1; k < N/2; k++){
            M2[k] += M2_copy[k-1];
        }
        log10(M2, M2_BUFFER, N/2);
        pow(M2_BUFFER, e_arr, M2, N/2);
        for (size_t k = 0; k < N/2; k++){
            M2[k] = M1_BUFFER[k] - M2[k];
        }
        absI(M2, N/2);
        double temp = 0;
        size_t j = 0;
        for(size_t k=1;k<N/2;k++){
            temp=M2[k];
            j=k-1;
            while((temp<M2[j])&&(j>=0)){
                M2[j+1]=M2[j];
                j=j-1;
            }
            M2[j+1]=temp;
        }
        double min_num = 0;
        for(size_t k=0;k<N/2;k++) {
            if(M2[k] > 0){
                min_num = M2[k];
                break;
            }
        }
        for(size_t k=1;k<N/2;k++) {
            if(M2[k] < min_num){
                min_num = M2[k];
            }
        }
        int sumLength = 0;
        for (size_t k = 0; k < N/2; k++){
            int check_num = (int)(M2[k] / min_num);
            if(check_num % 2 == 0) {
                SUM[sumLength] = M2[k];
                sumLength++;
            } else {
            }
        }
        double *RES = (double*)malloc(sumLength * sizeof(double));
        double res;
        sin(SUM, RES, sumLength);
        sum(RES, &res, sumLength);
        free(M1);
        free(M2);
        free(M1_BUFFER);
        free(e_arr);
        free(M2_BUFFER);
        free(M2_copy);
        free(SUM);
        free(RES);
    }
    gettimeofday(&T2, NULL);
    delta_ms = 1000*(T2.tv_sec - T1.tv_sec) + (T2.tv_usec - T1.tv_usec)/1000;
    printf("N=%d. Milliseconds passed: %ld\n", N, delta_ms);

    return 0;
}
