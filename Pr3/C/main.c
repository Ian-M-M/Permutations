#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "etc.h"
#include "permutator.h"

bool f_flag = false;	// -f nombreFile
bool t_flag = false;	// -t tiempo que tarda en encontrar el maximo de todas las permutaciones
bool di_flag = false;	// --di Debug input
bool do_flag = false;	// --do Debug output
/*
	BruteForce() devuelve el numero máximo de todas las 
	permutaciones del conjunto de numeros contenido en elementos 
*/
long long BruteForce (char **elementos, int tamElementos, int * nDigElementos) {
	int *indices = malloc(tamElementos*sizeof(int)); // Orden a mostrar los indices
	Permutator(tamElementos);	// Llamamos al constructor del permutador
	long long maximo = 0;	// Numero maximo de todas las permutaciones
	long long valor = 0;	// Contedrá el valor obtenido tras una permutacion
	while(hasMore()) {	
		indices = getNext();	// Actualizamos el orden tras la permutacion
		valor = ToLong(elementos, indices, tamElementos, nDigElementos);
		// Comprobamos si la permutacion es mayor 
		if (valor > maximo) {
      		maximo = valor;
  		}
	}
	free(indices);		//Liberamos memoria
	return maximo;
}

int main(int argc, char * argv[]){
	// Elementos contiene punteros que apuntan a punteros de char
  	char **elementos = NULL;		// Puntero de punteros char
  	int * nDigElementos = NULL;	// Un puntero de integers que representa los no. digitos de cada elemento 
  	int tamElementos;		// Numero total de elementos en el array elementos
	long maximo = 0;		// Maximo numero encontrado tras las permutaciones
	char path[500]="";		// Ruta del archivo 

	// Obtemos los parametros de la consola
	GetParam(argc, argv, &di_flag, &do_flag, &f_flag, &t_flag, path);

	if (!f_flag) {
		printf("[!] ERROR. -f file requerido\n");
		exit(1);
	}

	// Si solo se ha indica el archivo no funciona
	if (!di_flag && !do_flag && !t_flag ) {
		printf("[!] ERROR. Necesitamos más opciones\n");
		exit(1);
	}

	// Se imprime el contenido del archivo
	if (di_flag) Input();

	FILE *fichero = fopen(path, "r");
  	if (fichero != NULL) {
    	char linea[128];
    	while ( fgets(linea, sizeof linea, fichero ) != NULL) {
      		elementos = (char **) split(linea);// Obtenemos los elementos de la linea leida
      		tamElementos = getTamElementos();
      		nDigElementos = getnDigELementos();
			if (t_flag) ComienzaTimer();/* Contamos el tiempo que tarda en encontrar el 
										maximo tras realizar todas las permutaciones
										contenidas en elementos */
			// Algoritmo de fuerza bruta
			maximo = BruteForce(elementos, tamElementos, nDigElementos);
			if (t_flag) FinTimer();	
			if (do_flag) Output(elementos, maximo);		// Debug output
			if (t_flag) T_Output();	// Se muestran los tiempos 
      		free(elementos);	// Liberamos memoria
    	}
		pclose(fichero);
  	} else {
		perror(path);
		return (1);
	}
  return(0);
}
