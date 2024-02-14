PARALLELCOUNT= parallelcount parallelcount_mutex
TAYLOR=taylor taylor_pthreads

all: $(PARALLELCOUNT) $(TAYLOR)

parallelcount: parallelcount.c
	gcc -o parallelcount parallelcount.c -pthread

parallelcount_mutex: parallelcount_mutex.c
	gcc -o parallelcount_mutex parallelcount_mutex.c -pthread

taylor: taylor.c
	gcc -o taylor taylor.c -lm

taylor_pthreads: taylor_pthreads.c
	gcc -o taylor_pthreads taylor_pthreads.c -lm -pthread
