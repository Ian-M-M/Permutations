#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "etc.h"
#include "permutator.h"

bool f_flag= false;
bool t_flag= false;
bool di_flag= false;
bool do_flag = false;

long long BruteForce (char **elementos,int tamElementos,int * nDigElementos) {
	int *indices = malloc(tamElementos*sizeof(int));
	Permutator(tamElementos);
	long long maximo = 0;
	long long valor = 0;
	while(hasMore()) {
		indices = getNext();
		valor = ToLong(elementos, indices, tamElementos, nDigElementos);
		if (valor > maximo) {
      	maximo = valor;
  	}
	}
	return maximo;
}

int main(int argc, char * argv[]){
  char **elementos=NULL;
  int * nDigElementos=NULL;
  int tamElementos;
	long maximo=0;
	char path[500]="";

	GetParam(argc, argv, &di_flag, &do_flag, &f_flag, &t_flag, path);
	if (!f_flag) {
		printf("[!]ERROR. -f file requerido\n");
		exit(1);
	}
	if (!di_flag && !do_flag && !t_flag ) {
		printf("[!]ERROR. Necesitamos otra opcion\n");
		exit(1);
	}
	if (di_flag) Input();

	FILE *fichero = fopen(path, "r");

  if (fichero != NULL) {
    char linea[128];
    while ( fgets(linea, sizeof linea, fichero ) != NULL) {
      elementos = (char **) split(linea);
      tamElementos = getTamElementos();
      nDigElementos = getnDigELementos();

			//ANTES DEL BRUTEFORCE
			if (t_flag) ComienzaTimer();

			maximo = BruteForce(elementos, tamElementos, nDigElementos);

			//DESPUES DEL BRUTEFORCE
			if (t_flag) FinTimer();
			if (do_flag) Output(elementos, maximo);
			if (t_flag) T_Output();
      free(elementos);
    }
  }
  return(0);
}
