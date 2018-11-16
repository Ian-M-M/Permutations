#ifndef _etc_h
#define _etc_h
void ComienzaTimer();
void FinTimer();
void Input();
void GetParam(int argc, char * argv[], bool * di_flag, bool * do_flag,	bool * f_flag, bool * t_flag, char * path);
void T_Output();
void Output(char ** elementos, long maximo);
void mi_strcpy (char* s1, char* s2, int pos);
long long ToLong(char ** elementos, int * indices, int tamElementos, int * nDigElementos);
int * getnDigELementos();
int getTamElementos();
char ** split(char linea[]);
#endif
