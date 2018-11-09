#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "etc.h"
#include "permutador.h"
//int array[128];
size_t nElements;
int main() {
	int *ptr;
	size_t i;
	static const char nombreFichero[] = "../Permutaciones.txt";
  	FILE *fichero = fopen(nombreFichero, "r");
   	if (fichero != NULL) {
      		char linea[128]; 
      		while ( fgets(linea, sizeof linea, fichero ) != NULL) {
        		//fputs(linea, stdout); 
			ptr = split(linea);
			nElements = numElementos();
			//para comprobar que salió bien
			for ( i = 0; i < nElements; ++i ) {
      				printf("%d,", ptr[i]);
			}
			printf("\n");
			
      		}
      		fclose(fichero);
   	} else {
      		perror(nombreFichero); 
		return (-1);
   	}
	return(0);
}
/*long Iterador () {
	int indices[];
	
	long maximo = 0;
}*/
