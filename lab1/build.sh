#!/bin/bash

gcc -O3 -Wall -Werror -o lab1-par-1  main.c -lm -floop-parallelize-all -ftree-parallelize-loops=1
gcc -O3 -Wall -Werror -o lab1-par-2  main.c -lm -floop-parallelize-all -ftree-parallelize-loops=2
gcc -O3 -Wall -Werror -o lab1-par-3  main.c -lm -floop-parallelize-all -ftree-parallelize-loops=3
gcc -O3 -Wall -Werror -o lab1-par-4  main.c -lm -floop-parallelize-all -ftree-parallelize-loops=4
gcc -O3 -Wall -Werror -o lab1-seq  main.c -lm

clang -O3 -Wall -Werror -o lab1-seq-clang  main.c -lm
clang -O3 -Wall -Werror -o lab1-par-clang  main.c -lm -ftree-slp-vectorize