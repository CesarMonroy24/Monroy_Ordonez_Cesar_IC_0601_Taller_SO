#ifndef __HILOS_H
#define __HILOS_H

#include <stdio.h>
#include <pthread.h>

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);


void *hilo_reproducir_musica(void *data);//funcion que recibe un paràmetro de entrada de tipo puntero a void (void *) y tiene que devolver tambièn un puntero a void.
void *hilo_abrir_youtube(void *data);
void *hilo_escribir_texto_word(void *data);
void *hilo_descargar_archivo(void *data);
void *hilo_subiendo_archivo(void *data);
void *hilo_compilando_programa(void *data);
void *hilo_ejecutando_programa(void *data);
void *hilo_usando_terminal(void *data);

void reproducir_musica(void){
	//Declaraciòn de la variable hilo1 de tipo pthread_t que almacenaran el identificador de cada uno de los hilos que vamos a crear 
	pthread_t hilo1;
	//Creaciòn del hilo con la funciòn pthread_create, posteriormente se almacena el identificador del hilo creado en la variable &hilo1, utilizamos NULL ya 	 que no necesita ningún argumento la función que ejecutara el proceso1
	pthread_create(&hilo1,NULL,hilo_reproducir_musica,NULL);
	//Hacemos uso de pthread_join para realizar un mecanismo de sincronización que nos permitirá esperar la terminación del hilo1.
	pthread_join(hilo1,NULL);
}

void abrir_youtube(void){
	pthread_t hilo2;
	pthread_create(&hilo2,NULL,hilo_abrir_youtube,NULL);
	pthread_join(hilo2,NULL);
}

void escribir_texto_word(void){
	pthread_t hilo3;
	pthread_create(&hilo3,NULL,hilo_escribir_texto_word,NULL);
	pthread_join(hilo3,NULL);
}

void descargar_archivo(void){
	pthread_t hilo4;
	pthread_create(&hilo4,NULL,hilo_descargar_archivo,NULL);
	pthread_join(hilo4,NULL);
}

void subiendo_archivo(void){
	pthread_t hilo5;
	pthread_create(&hilo5,NULL,hilo_subiendo_archivo,NULL);
	pthread_join(hilo5,NULL);
}

void compilando_programa(void){
	pthread_t hilo6;
	pthread_create(&hilo6,NULL,hilo_compilando_programa,NULL);
	pthread_join(hilo6,NULL);
}

void ejecutando_programa(void){
	pthread_t hilo7;
	pthread_create(&hilo7,NULL,hilo_ejecutando_programa,NULL);
	pthread_join(hilo7,NULL);
}

void usando_terminal(void){
	pthread_t hilo8;
	pthread_create(&hilo8,NULL,hilo_usando_terminal,NULL);
	pthread_join(hilo8,NULL);
}

void *hilo_reproducir_musica(void *data){//Acciòn que va a realizar el hilo creado, la funcion imprimen un mensaje cada una, pero lo hacen letra a letra, en el ciclo for, realiza un salto de linea y no retorna nungun valor
	char *letra= "Reproduciendo Música"; 
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_abrir_youtube(void *data){
	char *letra= "Usando Youtube";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_escribir_texto_word(void *data){
	char *letra= "Escribiendo Texto en Word";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_descargar_archivo(void *data){
	char *letra= "Descargando Archivo";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_subiendo_archivo(void *data){
	char *letra= "Subiendo Archivo";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_compilando_programa(void *data){
	char *letra= "Compilando programa";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_ejecutando_programa(void *data){
	char *letra= "Ejecutando programa";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}

void *hilo_usando_terminal(void *data){
	char *letra= "Usando la terminal";
	int i;
	for(i=0; i < strlen(letra);i++){
		printf("%c",letra[i]);
	}
	printf("\n");
	return NULL;
}
#endif
