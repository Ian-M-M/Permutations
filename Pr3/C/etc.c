#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>

#include "etc.h"
// Los tiempos se disparan si > 12
#define MAXDIGITOS 19		

clock_t t0, t1;				// Variables del contador 
double time_taken = 0;		// de tiempo
char path[500]="";			// Ruta del archivo a leer
bool flagt = false;			// Flag del contador de tiempo
int tamElementos = 0;		// Numero de elementos del conjunto
int * nDigElementos = NULL;	// Un puntero de integers que representa los digitos de cada elementos 
int i = 0;

void ComienzaTimer() {
	t0 = clock();
}

void FinTimer() {
	t1 = clock();
  	time_taken = ((double) (t1 - t0) )/CLOCKS_PER_SEC;
}

void GetParam(int argc, char * argv[], bool * di_flag, bool * do_flag,
	bool * f_flag, bool * t_flag, char * p) {
	if (argc < 3){
		printf(" [!] ERROR. Numero de argumentos incorrectos\n");
		exit(1);
	}
	// Estructura necesaria al ser las opciones de
	// mas de un caracter
	static struct option long_options[] = {
	  {"di", no_argument, 0,  'i' },
	  {"do", no_argument, 0,  'o' },
	  {"f", required_argument,0, 'f' },
	  {"t", no_argument,0,'t' },
	  {0, 0, 0, 0}
  	};
	int long_index =0;
	int opt = 0;
	// Activamos flags leyendo los parametros
	// pasados al programa
	while ((opt = getopt_long(argc, argv,"iof:t",
        long_options, &long_index )) != -1) {
		switch(opt) {
	  		case 'o':
      			*do_flag = true;	// Debug output
        		break;
      		case 'i':
	      		*di_flag = true;	// Debug input
	      		break;
			case 'f':				// Archivo
	      		*f_flag = true;
				strcpy(p,optarg);		// Copiamos la ruta 
				strcpy(path,optarg);	
	      		break;
			case 't':				// Contador del tiempo
	      		*t_flag = true;
				flagt = true;		// Variable necesaria para
	      		break;				// el metodo Output()
			case '?':
	  			printf ("[!] ERROR. Opcion incorrecta `-%c'.\n", optopt);
				exit(1);
		}
	}
}
// Impresión del contenido del archivo 
void Input(){
	printf(" Ruta del fichero => %s\n",path);	
	FILE *fichero = fopen(path, "r");
	if (fichero != NULL) {
		char linea[128];
  	while ( fgets(linea, sizeof linea, fichero ) != NULL) {
			printf("%s", linea);
  	}
		fclose(fichero);
 	} else {
		perror(path);
		exit(1);
 	}
	printf("-------------------------------------------------\n");
}

void T_Output(){
	printf("Tiempo => %fs\n", time_taken);
	printf("-------------------------------------------------\n");
}

void Output(char ** elementos, long maximo){
	
 	printf(" Elementos [%d] => ", tamElementos);
	int count = 0;
	// Imprime el conjunto de elementos
  	for (i = 0; i < tamElementos; i++) {
      	printf("%s ", elementos[i]);
  	}
	printf("\n");
	// Imprime la cobinacion mayor del conjunto
  	printf("Maxima permutacion => %ld\n",maximo);
 	if (!flagt) printf("-------------------------------------------------\n");
}

void mi_strcpy (char* s1, char* s2, int pos){
  	char* ptr = &s1[pos];	// Apunta a al puntero de chars en la posicion
							// pos
  	char* ptr2 = s2;		// Puntero al puntero de chars 
							// donde se guardara la copia
  	while (*ptr2 != '\0') {	// Mientras hayan datos
      	*ptr = *ptr2;		// realiza la copia
      	ptr++;				// Se avanza los punteros
     	ptr2++;	
  	}
  	*ptr = '\0';	// Añadimos el caracter nulo 
}

long long ToLong(char ** elementos, int * indices, int tamElementos, int * nDigElementos){
  	char *permutacion=malloc(MAXDIGITOS*sizeof(char)); // Contedora de la string
									// donde se iran añadiendo los elementos
									// ordenados de acuerdo a indices tras la
									// permutacion
	char *ptr;	// Puntero necesario para pasar la permutacion
				// a long long 
	int pos = 0;	// Posicion donde se empezará a concatenar los elementos
  	for (i = 0; i < tamElementos; i++) {
    	mi_strcpy(permutacion, elementos[indices[i]], pos);
		pos += nDigElementos[indices[i]];
  	}
	// Transforma la string a tipo long long 
	// en base decimal 
	long long res = strtol(permutacion, &ptr, 10);
	free (permutacion); // Liberamos el espacio
	return res;
}

int * getnDigELementos(){
	return nDigElementos;	// Devuelve el num de digitos 
							// de cada elemento del conjunto
							// de numeros
}

int getTamElementos(){	
	return tamElementos;	// Devuelve el numero de elementos
							// del conjunto
}

char ** split(char linea[]) {
  	// Puntero que recorre linea
	int lineaI = 0;
  	// Digito que vamos a guardar en elementos y su puntero para recorrerlo
	char * digito = (char *) malloc((sizeof(char)*MAXDIGITOS));
	// Puntero que recorre digito
	int digitoI = 0;
  	// Elementos que vamos a permutar y su puntero para recorrerlo
	char ** res = (char ** ) malloc(sizeof(char)*MAXDIGITOS*MAXDIGITOS);
  	nDigElementos = (int * ) malloc(sizeof(int)*MAXDIGITOS);
	// Posicion de res
  	int resI = 0;
	tamElementos = 0;

	int i = 0;
	// LLenamos a ceros nDigElementos
  	for(i; i < MAXDIGITOS; i++) nDigElementos[i]=0;
	// Mientras hayan caracteres en la linea leida del archivo...
	while ((linea[lineaI] != '\n')  && (linea[lineaI] != EOF)) {
		// Si encontramos una coma guardamos en res el numero
		//	recorriendo los digitos
		if (linea[lineaI] == ',') {
      		res[resI] = (char * ) malloc(sizeof(char)*(digitoI+1));
      		i = 0;
      		for(i; i < digitoI; i++){
        		res [resI][i] = (char) digito[i];
      		}
      		res[resI][digitoI+1] = '\0'; // Añadimos un caracter nulo 
      		free(digito); // Liberamos memoria
			// Y volvemos a asignarla
			digito = (char *) malloc((sizeof(char)*MAXDIGITOS));
      		nDigElementos[resI] = digitoI;	// Se guarda el numero de digitos
											// del elemento que ocoupa la pos resI
			digitoI = 0;	// Reseteamos a 0
      		resI++;	
      		tamElementos++;	// Aumentamos tamElementos
		}else {
			
			digito[digitoI] = linea[lineaI]; // Guardamos el caracter(digito) leido
			digitoI++;	// Avanza el puntero
		}
		lineaI++;	// Avanza el caracter de linea 
	}
  	res [resI] = (char * ) malloc(sizeof(char)*resI);
  	i = 0;
	// Guarda los digitos del ultimo elemento en res
  	for(i; i < digitoI; i++){
    	res [resI][i] = (char) digito[i];
  	}
  	nDigElementos[resI] = digitoI - 1;		// Restamos 1 en el num de digitos
  	free(digito); 	// Liberamos memoria
  	tamElementos++;	 // Actualizamos num de elementos
	return res;
}
