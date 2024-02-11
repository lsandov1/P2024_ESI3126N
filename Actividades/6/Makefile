all: matrprimos matrprimos_pthreads

matrprimos: matrprimos.c
	gcc -o matrprimos matrprimos.c -lm

matrprimos_pthreads: matrprimos_pthreads.c
	gcc -o matrprimos_pthreads matrprimos_pthreads.c -lm -pthread
