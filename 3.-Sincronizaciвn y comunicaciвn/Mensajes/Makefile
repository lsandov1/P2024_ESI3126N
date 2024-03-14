BINS:= jugadores_domino mensajes1 mensajes2 mensajesints create_queue send_message receive_message
all: $(BINS)

jugadores_domino: jugadores_domino.c
	gcc -o jugadores_domino jugadores_domino.c

mensajes1: mensajes1.c
	gcc -o mensajes1 mensajes1.c

mensajes2: mensajes2.c
	gcc -o mensajes2 mensajes2.c

mensajesints: mensajesints.c
	gcc -o mensajesints mensajesints.c

create_queue: create_queue.c
	gcc create_queue.c -o create_queue

send_message: send_message.c
	gcc send_message.c -o send_message

receive_message: receive_message.c
	gcc receive_message.c -o receive_message

clean:
	rm -f $(BINS)
