all: pi_serial pi_pthread

pi_serial: pi_serial.c
	gcc -o pi_serial pi_serial.c -lm

pi_pthread: pi_pthread.c
	gcc -o pi_pthread pi_pthread.c -lm -pthread
