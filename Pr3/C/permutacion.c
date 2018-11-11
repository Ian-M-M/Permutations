#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "etc.h"
#include "permutador.h"
#include <stdbool.h>
int nElements;
int nDigitos;
long BruteForce (int *elementos) {
	int *indices = malloc(nElements*sizeof(int));
	Permutador(nElements);
	long maximo = 0;
	long valor = 0;
	while(hasMore()) {
		printf("Antes %ld\n", valor);
		*indices = getNext();
		valor = (long)ToLong(elementos,*indices,nElements,nDigitos);
		printf("%ld\n", valor);
		if (valor > maximo) {
                	maximo = valor;
            	}
		printf("Despues %ld\n", valor);
	}
	//printf("%ld\n", maximo);
	return maximo;
}

int main (void) {
	int *elementos;
	size_t i;
	static const char nombreFichero[] = "../Permutaciones.txt";
  	FILE *fichero = fopen(nombreFichero, "r");
	
   	if (fichero != NULL) {
      		char linea[128]; 
      		while ( fgets(linea, sizeof linea, fichero ) != NULL) {
			elementos = split(linea);
			nElements = numElementos();
			nDigitos = numDigitos(elementos);
			//ComienzaTimer();
			long maximo = BruteForce(elementos);
			//FinTimer();
			//para comprobar que salió bien
			/*for ( i = 0; i < nElements; ++i ) {
      				printf("%d,", elementos[i]);
			}
			*/
			//printf("\n");
      		}
		
      		fclose(fichero);
   	} else {
      		perror(nombreFichero); 
		return (-1);
   	}
	return(0);
}
