all: pi_serial pi_serial_O1 pi_serial_O2 pi_pthread

pi_serial: pi_serial.c
	gcc -o pi_serial pi_serial.c -lm

pi_serial_O1: pi_serial.c
	gcc -O1 -o pi_serial_O1 pi_serial.c -lm

pi_serial_O2: pi_serial.c
	gcc -O2 -o pi_serial_O2 pi_serial.c -lm

pi_pthread: pi_pthread.c
	gcc -o pi_pthread pi_pthread.c -lm -pthread
