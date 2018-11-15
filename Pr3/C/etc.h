#ifndef _etc_h
#define _etc_h
#include <stdbool.h>
int * split(char linea[]);
int numElementos();
void ComienzaTimer();
void FinTimer();
long long ToLong(int * elementos, int * indices, int n, int nDigitos);
int numDigitos (int * elementos);
void GetParam(int argc, char * argv[], bool * di_flag, bool * do_flag,
		bool * f_flag, bool * t_flag, char * path);
void T_Output();
void Output(int * elementos, long maximo);
#endif
