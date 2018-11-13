#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "etc.h"
int tamArray;
clock_t t0, t1;
int i;
int * split(char linea[]) {
	int j;
	int i = 0;
	int c = 0;
	int tam = 0;
	char *numero;
	while (linea[c] != '\0') {
      		if (linea[c] == ',') {
         		tam++;
      		}
      		c++;
   	}
	int *array = malloc((tam + 1) * sizeof(int));
	if (array == NULL) {
  		fprintf(stderr, "Malloc falló\n");
  		exit(-1);
	}
   	const char delimitador[2] = ",";

	numero = strtok(linea, delimitador);
	while (numero != NULL) {
		array[i] = atoi(numero);
		i++;
		numero = strtok(NULL, delimitador);
	}
	tamArray = tam + 1;
	return array;
}

int numElementos() {
	return tamArray;
}

void ComienzaTimer() {
	t0 = clock();
}

void FinTimer() {
	t1 = clock();
    	double time_taken = ((double) (t1 - t0) )/CLOCKS_PER_SEC; 
	printf("%f\n", time_taken);
}

long ToLong(int * elementos, int * indices, int n, int nDigitos){
	char integerTostring[1024];
        char *permutacion=malloc(nDigitos*sizeof(char));
	char *ptr;
	
        for (i = 0; i < n; i++) {
		sprintf(integerTostring, "%d", elementos[indices[i]]);
            	strcat(permutacion, integerTostring);
        }        
	long res = strtol(permutacion, &ptr, 10);
	printf("%ld\n",res);
        return res;
}

int numDigitos (int * elementos) {
	int nDigitos= 0;
	int n;
	for (i = 0; i < tamArray; i++) {
		n = elementos[i];
		while( n != 0){
        		n = n/10;
			nDigitos++;
		}
	}
	return nDigitos;
}
