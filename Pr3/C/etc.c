#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>

#include "etc.h"
#define MAXDIGITOS 19

clock_t t0, t1;
char path[]="";
double time_taken=0;
bool flagt = false;
int tamElementos = 0;
int * nDigElementos = NULL;
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
	static struct option long_options[] = {
	  {"di",  no_argument,       	0,  'i' },
	  {"do", 	no_argument,       	0,  'o' },
	  {"f",   required_argument, 	0,  'f' },
	  {"t",   no_argument,				0,  't' },
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
				strcpy(p,optarg);
				strcpy(path,optarg);
	      break;
			case 't':
	      *t_flag = true;
				flagt = true;
	      break;
			case '?':
	  		printf ("[!] ERROR. Opcion incorrecta `-%c'.\n", optopt);
				exit(1);
		}
	}
}

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
	//fflush(stdout);
  printf(" Elementos [%d] => ", tamElementos);
	int count = 0;
  for (i = 0; i < tamElementos; i++) {
      printf("%s ", elementos[i]);
  }
	printf("\n");
	fflush(stdout);
  printf("Maxima permutacion => %ld\n",maximo);
 	if (!flagt) printf("-------------------------------------------------\n");
}

void mi_strcpy (char* s1, char* s2, int pos){
  char* ptr = &s1[pos];
  char* ptr2 = s2;
  while (*ptr2 != '\0') {
      *ptr = *ptr2;
      ptr++;
      ptr2++;
  }
  *ptr = '\0';
}

long long ToLong(char ** elementos, int * indices, int tamElementos, int * nDigElementos){
  char *permutacion=malloc(MAXDIGITOS*sizeof(char));
	char *ptr;
	int pos = 0;
  for (i = 0; i < tamElementos; i++) {
      	mi_strcpy(permutacion, elementos[indices[i]], pos);
				pos += nDigElementos[indices[i]];
  }
	long long res = strtol(permutacion, &ptr, 10);
	free (permutacion);
	return res;
}

int * getnDigELementos(){
	return nDigElementos;
}

int getTamElementos(){
	return tamElementos;
}

char ** split(char linea[]) {
  // puntero que recorre linea
	int lineaI = 0;
  // digito que vamos a guardar en elementos y su puntero para recorrerlo
	char * digito = (char *) malloc((sizeof(char)*MAXDIGITOS));
	int digitoI = 0;
  // elementos que vamos a permutar y su puntero para recorrerlo
	char ** res = (char ** ) malloc(sizeof(char)*MAXDIGITOS*MAXDIGITOS);
  nDigElementos = (int * ) malloc(sizeof(int)*MAXDIGITOS);
  int resI = 0;
	tamElementos = 0;

  int i = 0;
  for(i; i<MAXDIGITOS; i++) nDigElementos[i]=0;

	while ((linea[lineaI] != '\n')  && (linea[lineaI] != EOF)) {

		if (linea[lineaI] == ',') {
      res[resI] = (char * ) malloc(sizeof(char)*(digitoI+1));
      i = 0;
      for(i; i < digitoI; i++){
        res [resI][i] = (char) digito[i];
      }
      res[resI][digitoI+1] = '\0';
      free(digito);
			digito = (char *) malloc((sizeof(char)*MAXDIGITOS));
      nDigElementos[resI] = digitoI;
			digitoI = 0;
      resI++;
      tamElementos++;
		}else {
			digito[digitoI] = linea[lineaI];
			digitoI++;
		}
		lineaI++;
	}
  res [resI] = (char * ) malloc(sizeof(char)*resI);
  i = 0;
  for(i; i < digitoI; i++){
    res [resI][i] = (char) digito[i];
  }
  nDigElementos[resI] = digitoI - 1;
  free(digito);
  tamElementos++;

	return res;
}
