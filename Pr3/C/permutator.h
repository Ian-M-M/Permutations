#ifndef _permutator_h
#define _permutator_h
#include <stdbool.h>

/* 
	Se reestablece el array de indices
  	rellenando con el numero de posiciones 
	hasta n-1
 */
void reset(int n);

/* 
	Obtenemos el numero total de permutaciones 
	calculando el factorial del numero de elementos
 */
long getFactorial(int n);

/*
	Constructor del permutador donde se inicializa 
	
 */
void Permutator(int n);

/*
	Devuelve un boleano indicando si faltan más
	permutaciones por procesar
*/
bool hasMore();

/* 
  Devuelve un array con las posiciones
  permutadas(algoritmo de Rosen p. 284)
 */
int * getNext();
#endif
