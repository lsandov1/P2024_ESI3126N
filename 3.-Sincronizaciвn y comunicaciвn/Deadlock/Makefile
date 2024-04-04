all: filosofos mutual_exclusion circular_wait

mutual_exclusion: mutual_exclusion.c
	gcc mutual_exclusion.c -o mutual_exclusion -pthread

circular_wait: circular_wait.c
	gcc circular_wait.c -o circular_wait -pthread

filosofos: filosofos.c semaphoresarr.c semaphoresarr.h
	gcc filosofos.c -o filosofos semaphoresarr.c
