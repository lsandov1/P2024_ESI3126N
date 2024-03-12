all: mercator_proc mercator_proc_sem_lib mercator_proc_sem

mercator_proc: mercator_proc.c
	gcc -o mercator_proc mercator_proc.c -lm

mercator_proc_sem_lib: mercator_proc_sem_lib.c semaphoresarr.c
	gcc -o mercator_proc_sem_lib mercator_proc_sem_lib.c semaphoresarr.c -lm

mercator_proc_sem: mercator_proc_sem.c
	gcc -o mercator_proc_sem mercator_proc_sem.c -lm
