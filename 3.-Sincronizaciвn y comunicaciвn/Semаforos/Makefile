all: semsejemplo1 semsprodcons_threads semsprodcons_proc jugadores_domino

semsejemplo1: semsejemplo1.c semaphoresarr.c semaphoresarr.h
	gcc -o semsejemplo1 semsejemplo1.c semaphoresarr.c

semsprodcons_threads: semsprodcons_threads.c
	gcc -o semsprodcons_threads semsprodcons_threads.c semaphoresarr.c -lpthread

semsprodcons_proc: semsprodcons_proc.c
	gcc -o semsprodcons_proc semsprodcons_proc.c semaphoresarr.c -lm

jugadores_domino: jugadores_domino.c
	gcc -o jugadores_domino jugadores_domino.c semaphoresarr.c -lm

clean:
	rm semsejemplo1 semsprodcons_threads semsprodcons_proc jugadores_domino
