#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include "etc.h"
int tamArray;
clock_t t0, t1;
int i;
char nombreFich[] = "";
double time_taken;
bool flagt = false;
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
    	time_taken = ((double) (t1 - t0) )/CLOCKS_PER_SEC;
	
}

long long ToLong(int * elementos, int * indices, int n, int nDigitos){
	char integerTostring[1024];
        char *permutacion=malloc(nDigitos*sizeof(char));
	char *ptr;

        for (i = 0; i < n; i++) {
		sprintf(integerTostring, "%d", elementos[indices[i]]);
            	strcat(permutacion, integerTostring);
        }
	long long res = strtol(permutacion, &ptr, 10);
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
void GetParam(int argc, char * argv[], bool * di_flag, bool * do_flag,
		bool * f_flag, bool * t_flag, char * path) {
	if (argc < 3){
        	printf(" [!] ERROR. Número de argumentos incorrectos\n");
        	exit(1);
    	}
	static struct option long_options[] = {
        {"di",  no_argument,       	0,  'i' },
        {"do", 	no_argument,       	0,  'o' },
        {"f",   required_argument, 	0,  'f' },
        {"t",   no_argument,		0,  't' },
        {0,     0,                	0,  0   }
    };
	int long_index =0;
	int opt = 0;
	while ((opt = getopt_long(argc, argv,"iof:t", 
                   long_options, &long_index )) != -1) {
        	switch(opt) {
            		case 'o':
                		*do_flag = true;
                		break;
            		case 'i':
                		*di_flag = true;
                		break;
			case 'f':
                		*f_flag = true;
				strcpy(nombreFich,optarg);
				strcpy(path,optarg);
                		break;
			case 't':
                		*t_flag = true;
				flagt = true;
                		break;
           	 	case '?':
          			fprintf (stderr, "[!] ERROR. Opción incorrecta `-%c'.\n", optopt);
				exit(1);
        	}
	}
}

void Input(){ 
	printf("Ruta del fichero => %s\n",nombreFich);
	FILE *fichero = fopen(nombreFich, "r");
	if (fichero != NULL) {
      		char linea[128];
      		while ( fgets(linea, sizeof linea, fichero ) != NULL) {
			printf("%s", linea);
      		}
      		fclose(fichero);
   	} else {
      		perror(nombreFich);
		exit(1);
   	}
	printf("-------------------------------------------------\n");
}

void T_Output() {
	printf("Tiempo => %LFs\n", time_taken);
	printf("-------------------------------------------------");
}

void Output(int * elementos, long maximo) {
        printf("\nElementos [%d] => { ", tamArray);
        for (i = 0; i < tamArray; i++) {
            printf("%d ", elementos[i]);            
        }
        printf("}");        
        printf("\nMaxima permutacion => %ld\n",maximo);
     	if (!flagt) printf("-------------------------------------------------");  
}
