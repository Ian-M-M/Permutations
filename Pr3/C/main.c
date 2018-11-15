#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "etc.h"
#include "permutador.h"
#include <stdbool.h>
int nElements;
int nDigitos;
bool f_flag= false;
bool t_flag= false;
bool di_flag= false;
bool do_flag = false;
char path[] = "";
// -do: (Debug Output) Permite mostrar el valor máximo obtenido combinando los elementos del conjunto.
// -t: Permite mostrar el tiempo que se ha tardado en calcular el valor máximo.
long BruteForce (int *elementos) {
	int *indices = malloc(nElements*sizeof(int));
	Permutador(nElements);
	long long maximo = 0;
	long long valor = 0;
	while(hasMore()) {
		indices = getNext();
		valor = ToLong(elementos,indices,nElements,nDigitos);
		if (valor > maximo) {
                	maximo = valor;
            	}
	}
	//printf("%ld\n", maximo);
	return maximo;
}

int main (int argc, char* argv[]) {
	
	GetParam(argc, argv, &di_flag, &do_flag, &f_flag, &t_flag, path);
	if (!do_flag && !t_flag) {
		printf("[!] ERROR. Número de argumentos incorrectos\n");
		return (1);
	}
	if (di_flag) Input();
	int *elementos;
	size_t i;
  	FILE *fichero = fopen(path, "r");

   	if (fichero != NULL) {
      		char linea[128];
      		while ( fgets(linea, sizeof linea, fichero ) != NULL) {
			elementos = split(linea);
			nElements = numElementos();
			nDigitos = numDigitos(elementos);
			if (t_flag) ComienzaTimer();
			long maximo = BruteForce(elementos);
			if (t_flag) FinTimer();
			if (do_flag) Output(elementos, maximo);
			if (t_flag) T_Output();
      		}

      		fclose(fichero);
   	} else {
      		perror(path);
		return (1);
   	}
	return(0);
}
