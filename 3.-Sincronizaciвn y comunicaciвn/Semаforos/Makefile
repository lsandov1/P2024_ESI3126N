all: semsejemplo1 semsprodcons_threads semsprodcons_proc

semsejemplo1: semsejemplo1.c
	gcc -o semsejemplo1 semsejemplo1.c semaphoresarr.c

semsprodcons_threads: semsprodcons_threads.c
	gcc -o semsprodcons_threads semsprodcons_threads.c semaphoresarr.c -lpthread

semsprodcons_proc: semsprodcons_proc.c
	gcc -o semsprodcons_proc semsprodcons_proc.c semaphoresarr.c -lm

clean:
	rm semsejemplo1 semsprodcons_threads semsprodcons_proc
