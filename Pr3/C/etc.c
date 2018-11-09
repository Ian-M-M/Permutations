#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "etc.h"
size_t tamArray;
int * split(char linea[]) {
	int j;
	int i = 0;
	int c = 0;
	int tam = 0;
	char *numero;
   	//char linea[128] = line;
	while (linea[c] != '\0') {
      		if (linea[c] == ',') {
         		tam++;
      		}
      		c++;
   	}

	//int array[tam + 1];
	int *array = malloc((tam + 1) * sizeof(int));
	if (array == NULL) {
  		fprintf(stderr, "Malloc falló\n");
  		exit(-1);
	}
	int *ptr = array;
   	const char delimitador[2] = ",";

	numero = strtok(linea, delimitador);
	while (numero != NULL) {
		array[i] = atoi(numero);
		i++;
		numero = strtok(NULL, delimitador);
	}
	tamArray = tam + 1;
	//para comprobar que salió bien
	/*
	for (j = 0; j < tamArray; j++) {
		printf("%d,", array[j]);
	}
	printf("\n");
	*/
	return ptr;
}
size_t numElementos() {
	return tamArray;
}
