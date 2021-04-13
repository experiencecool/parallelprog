//#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define A 240
#define e 2.718281
/// Map1 -

double extended_random(unsigned int *seedp, int min, int max) {
    return (rand_r(seedp) % (max + 1 - min)) + min;
}

double cube_root(double n) {
    double i, precision = 0.000001;
    for(i = 1; (i*i*i) <= n; ++i);         //Integer part
    for(--i; (i*i*i) < n; i += precision);  //Fractional part
    return i;
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
        perror("Error: Invalid arguments\n");
        exit(1);
    } else {
        N = atoi(argv[1]);
    }
    gettimeofday(&T1, NULL);
    unsigned int *p = malloc(sizeof(unsigned int));
    for (i = 0; i < 50; i++){
        *p = i;
        double *M1 = malloc(N * sizeof(double));
        double *M2 = malloc((N/2) * sizeof(double));
        double *M2_copy = malloc((N/2) * sizeof(double));

        for (size_t j = 0; j < N; j++){
            M1[j] = extended_random(p, 1, A);
            //printf("%f ", M1[j]);
        }
        printf("\n");
        for (size_t k = 0; k < N/2; k++){
            M2[k] = extended_random(p, A, 10*A);
        }
        ///MAP1
        for (size_t j = 0; j < N; j++){
            M1[j] = cbrt((M1[j]/e));
            //printf("%f ", M1[j]);
        }
        for (size_t k = 0; k < N/2; k++){
            M2_copy[k] = M2[k];
        }
        for (size_t k = 1; k < N/2; k++){
            M2[k] += M2_copy[k-1];
            M2[k] = pow(log10(M2[k]), e);
        }
        for (size_t k = 0; k < N/2; k++){
            M2[k] = fabs(M1[k] - M2[k]);
        }
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
        free(M1);
        free(M2);
    }
    gettimeofday(&T2, NULL);
    delta_ms = 1000*(T2.tv_sec - T1.tv_sec) + (T2.tv_usec - T1.tv_usec)/1000;
    printf("\nN=%d. Milliseconds passed: %ld\n", N, delta_ms);

    return 0;
}