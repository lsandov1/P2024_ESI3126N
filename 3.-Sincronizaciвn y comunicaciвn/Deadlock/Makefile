all: filosofos filosofos_sol1 filosofos_sol2 mutual_exclusion circular_wait

mutual_exclusion: mutual_exclusion.c
	gcc mutual_exclusion.c -o mutual_exclusion -pthread

circular_wait: circular_wait.c
	gcc circular_wait.c -o circular_wait -pthread

filosofos: filosofos.c semaphoresarr.c semaphoresarr.h
	gcc filosofos.c -o filosofos semaphoresarr.c

filosofos_sol1: filosofos_sol1.c semaphoresarr.c semaphoresarr.h
	gcc filosofos_sol1.c -o filosofos_sol1 semaphoresarr.c

filosofos_sol2: filosofos_sol2.c semaphoresarr.c semaphoresarr.h
	gcc filosofos_sol2.c -o filosofos_sol2 semaphoresarr.c
