#include <stdio.h>

int main(){
//Ejercicio 1
printf("\n Ejercicio 1");
int x;
int *p;
int y;
int *puntero;

p= &x;
puntero =&y;

x=10;
y=20;

printf("\n El contenido del puntero p es: %d ",*p);


*p=x+1;
printf("\n El contenido del puntero p es: %d ",*p);

*p=x+2;
printf("\n El contenido del puntero p es: %d ",*p);

printf("\n El contemido del puntero puntero es: %d ",*puntero);


//Ejercicio 2
printf("\n Ejercicio 2");
int arrayInt[5];
int i;
int *punteroInt, *punteroIntDos;

for (i=0;i<5;i++){
arrayInt[i]=i;
}
punteroInt = arrayInt;
punteroIntDos= &arrayInt[0];

printf("\n El primer elemento del arrayInt es: %i",arrayInt[0]);
printf("\n El primer elemento del punteroInt es: %d",*punteroInt);
printf("\n El primer elemento del punteroIntDos es: %d",*punteroIntDos);
printf("\n El quinto elemento del arrayInt es: %i",arrayInt[4]);
printf("\n El quinto elemento del punteroInt es: %i",*punteroInt +4);
printf("\n El quinto elemento del punteroIntDos es: %i",*punteroIntDos +4);

for(i=0;i<5;i++){
punteroIntDos[i]=i;
printf("\n el contenido del punteroIntDos %i es: %i",i,punteroIntDos[i]);
}

for(i=0;i<5;i++){
punteroIntDos[i]=i;
printf("\n el contenido del punteroIntDos %i es: %i",i,punteroIntDos[i]);
}
return 0;
}
