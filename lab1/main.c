//#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define A 240

int extended_random(unsigned int *seedp, int min, int max) {
    return (rand_r(seedp) % (max + 1 - min)) + min;
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
        printf("%d \n", extended_random(p, 0, 500));
    }
    // int i, N;
    // struct timeval T1, T2;
    // long delta_ms;
    // N = atoi(argv[1]);
    // gettimeofday(&T1, NULL);
    // for (i=0; i<50; i++) {
    //     //srand(i);
    // }
    // gettimeofday(&T2, NULL);
    // delta_ms = 1000*(T2.tv_sec - T1.tv_sec) + (T2.tv_usec - T1.tv_usec)/1000;
    // printf("\nN=%d. Milliseconds passed: %ld\n", N, delta_ms);
    return 0;
}