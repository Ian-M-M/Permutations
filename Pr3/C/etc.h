#ifndef _etc_h
#define _etc_h
/*
	ComienzaTimer(): Método que comienza a contar el
	tiempo
*/
void ComienzaTimer();

/*
	FinTimer(): Para de contar el tiempo 
*/
void FinTimer();

/*
	Input(): Muestra el nombre del fichero
	y su contenido
*/
void Input();

/*
	GetParam(): Gestion de los parametros
	pasados al programa
*/
void GetParam(int argc, char * argv[], bool * di_flag, bool * do_flag,	bool * f_flag, bool * t_flag, char * path);

/*
	T_Output(); Muestra el tiempo que ha tardado
	en obtener el maximo genererado de todas las 
	combinaciones del conjunto de elementos
*/
void T_Output();

/*
	Output(): Imprime el conjunto de elementos 
	con su correspondiente maximo valor de todas
	lac combinaciones
*/
void Output(char ** elementos, long maximo);

/*
	mi_strcpy(): Método usado para copiar el
	contenido de un puntero de caracteres en otro 
	puntero de caracteres desde la posicion 
	indicada por parametro. Se usa para concatenar
	en una "string" los elementos segun el orden
	indicado por indices.
*/
void mi_strcpy (char* s1, char* s2, int pos);

/*
	ToLong(): Pasa el numero obtenido tras la 
	combinacion a long long 
*/
long long ToLong(char ** elementos, int * indices, int tamElementos, int * nDigElementos);

/* 
	getnDigELementos(): Devuelve un puntero de
	integer que contiene el numero de digitos
	de cada uno de los elementos del conjunto
	que se está combianando
*/
int * getnDigELementos();

/*
	getTamElementos(): Devuelve el numero de 
	elementos del conjuunto contenido en el 
	puntero elementos que apunta a caracteres
*/
int getTamElementos();
char ** split(char linea[]);

#endif
