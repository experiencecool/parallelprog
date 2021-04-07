CC=gcc
C_STD=c11
C_FLAGS=  #-Wall -Werror -Wpedantic -std=$(C_STD) -D_GNU_SOURCE
LIBS=-pthread -lpthread

all: main

main: main.o
	$(CC) $(C_FLAGS) $(LIBS) main.o -o main

main.o:
	$(CC) $(C_FLAGS) -c main.c

clean:
	rm -f main main.o