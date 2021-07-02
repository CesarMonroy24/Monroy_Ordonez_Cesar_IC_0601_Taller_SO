#ifndef __VARIABLESG_H
#define __VARIABLESG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAD_TAM 100

int Exisarchivo(char *archivoNom);
typedef struct listarel{
  	char cadena[CAD_TAM];
  	struct listarel *sig;
}elementos;
elementos *listcar(elementos *ELEM);
elementos *nuevoscar(elementos *ELEM, char *caracteres);
FILE *soloLectura(char *archivoNom);
FILE *archivoLE(char *archivoNom);
void cerrar_archivo(FILE *ptrArchivo, char *archivoNom);
void Burbu(elementos *ELEM);
int c =0;
typedef struct {
  char cadena[CAD_TAM];
}ordenT;

ordenT cadORD[100];

#endif
