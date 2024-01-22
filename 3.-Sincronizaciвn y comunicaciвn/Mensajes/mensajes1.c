/*
 * En esta versión el receive es bloquente 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[30];    /* message data */
};

int queue_id;	// Buzón de mensajes

void emisor();
void receptor();

int main()
{
	int pid;
	int status;

	// Crear buzón de mensajes 
	queue_id=msgget(0x5678,0666|IPC_CREAT);
	if(queue_id==-1)
	{
		fprintf(stderr,"No se pudo crear el buzón\n");
		exit(1);
	}
	
	// Crea un proceso donde va a ejecutarse el emisor
	pid=fork();
	if(pid==0)
		emisor();	// El hijo ejecuta el emisor
	
	// Crea un proceso donde va a ejecutarse el receptor
	pid=fork();
	if(pid==0)
		receptor();	// El hijo ejecuta el receptor
	
	// Esperar a que los dos procesos terminen
	wait(&status);
	wait(&status);
	
	msgctl(queue_id, IPC_RMID, NULL);
}

void emisor()
{
	int i;
	struct msgbuf mensaje;
	for(i=0;i<10;i++)
	{
		// Construye un mensaje
		mensaje.mtype=1;	// Prioridad o tipo del mensaje
		sprintf(mensaje.mtext,"Este es el mensaje %d",i);
		
		// Envíe el mensaje al buzón
		msgsnd(queue_id,&mensaje,sizeof(struct msgbuf),IPC_NOWAIT);	// No bloqueante
																	// No espera a que sea recibido
		sleep(1);
	}
	
	// Enviar el mensaje "FIN"
	sprintf(mensaje.mtext,"FIN");	
	msgsnd(queue_id,&mensaje,sizeof(struct msgbuf),IPC_NOWAIT);	// IPC_NOWAIT indica que 
																// no  bloqueante
	exit(0);	// Termina el emisor
}


void receptor()
{
	struct msgbuf mensaje;
	do 
	{
		// Recibe un mensaje del buzón
		msgrcv(queue_id,&mensaje,sizeof(struct msgbuf),1,0);	// Receive bloqueante
		printf("%s\n",mensaje.mtext);	// Imprimir el mensaje
	} while(strcmp(mensaje.mtext,"FIN")!=0); // Mientras no sea fin 
	exit(0);	// Termina el receptor
}
