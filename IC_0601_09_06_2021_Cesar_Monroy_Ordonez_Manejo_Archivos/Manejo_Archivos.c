#include "variablesg.h"
#include "abrirarch.h"
int main(int argc, char *argv[]){
 	FILE *archivoE = NULL, *archivoS=NULL;
	char *Nombre_Arch[CAD_TAM];
	int i = 0;
	char temp[100];
	int ExistenArch = 0;
	elementos *Carac = listcar(Carac);
	*Nombre_Arch =argv[1];
	ExistenArch=Exisarchivo(*Nombre_Arch);
	if (ExistenArch){
		 printf("\nEl archivo: %s ya existe", *Nombre_Arch);
	}else{
		printf("\nEl archivo: %s no existe", *Nombre_Arch);
	}
	
	archivoE=soloLectura(*Nombre_Arch);
	if(archivoE == NULL){
	printf("\n El archivo %s no pudo abrirse",*Nombre_Arch);
	}else{
	printf("\n Archivo %s abierto correctamente", *Nombre_Arch);
	while (!feof(archivoE)){
	fscanf(archivoE,"%s",temp);
	if(strcmp(temp,"")!=0){
	Carac=nuevoscar(Carac,temp);
	}
	memset(temp,0,50);
	}
 }
 
 
 Burbu(Carac);
	fclose(archivoE);
	archivoS = fopen(argv[2],"w");
  	printf("Nuevo archivo creado : %s\n",argv[2]);
  	for(int i=0; i<=c; i++){
    		strcpy(temp,cadORD[i].cadena);
   		if(strcmp(temp,"") != 0){
      			fprintf(archivoS,"%s\n",temp);
    		}
  	}
  	printf("Archivo \"%s\" escrito de manera correcta\n",argv[2]);
  	fclose(archivoS);						
}



elementos *listcar(elementos *ELEM){
  ELEM = NULL;
  return ELEM;
};

  elementos *nuevoscar(elementos *ELEM, char *caracteres){
  elementos *nuevo_Elemento, *aux; 
  nuevo_Elemento = (elementos*)malloc(sizeof(elementos));
  strcpy(nuevo_Elemento->cadena,caracteres);
  nuevo_Elemento->sig = NULL;
  //se apunta a nuevos elemntos para al momento de crear el archivo no e pirdan datos y se almacenen en dichas variable 
  if(ELEM == NULL){
    ELEM = nuevo_Elemento;
  }else{
    aux = ELEM;
    while(aux->sig != NULL){ 
      aux = aux->sig;
    }
    aux->sig = nuevo_Elemento; // nos movemos al ultimo elemento al que apunta aux de la lista enlazada  que anteriormente lo relizamos 
  }
  return ELEM;
};
void Burbu(elementos *ELEM){
  ordenT cadA[100];
  while(ELEM->sig != NULL){
    strcpy(cadA[c].cadena,ELEM->cadena); 
    ELEM = ELEM->sig;
    c++;
  }
  strcpy(cadA[c].cadena,ELEM->cadena);
  char temp[CAD_TAM]; //se inicia el ordenamiento por metodo de burbuja 
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
    int IndSigEl = j + 1;
      if(strcmp(cadA[j].cadena,cadA[IndSigEl].cadena) >= 0){
      // Movemos la cadena actual a la temporal
	strcpy(temp,cadA[j].cadena);
	// Movemos al actual el siguiente elemento
	strcpy(cadA[j].cadena,cadA[IndSigEl].cadena);
	 // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
	strcpy(cadA[IndSigEl].cadena,temp);
      }
    }
  } 
  for(int i=0; i<=c; i++){ 
      strcpy(cadORD[i].cadena,cadA[i].cadena);
      //Ordenamos los elemnentos del arreglo mediante el metodo de la burbuja 
  }
};

