#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "permutator.h"

int *array;
long numLeft, total;
int i, lenght;
void reset(int n) {
	for (i = 0; i < n ; i++) {
		array[i] = i;
	}
	numLeft = total;	// nº de permutaciones restantes
}

long getFactorial(int n) {
	long fact = 1;
	for (i = n; i > 1; i--) {
		fact = fact * i;
	}
	return fact;
}

void Permutator(int n) {
	lenght = n;
	if (n < 1) {
		printf("ERROR: Mínimo 1 elemento");
		exit (1);
	}
	array = malloc(n * sizeof(int));
	total = getFactorial(n);
	reset(n);
	return 0;
}

bool hasMore() {
	if (numLeft > 0) {
		return true;
	}
	return false;
}

int * getNext () {
	if (numLeft == total) {
		numLeft = numLeft -1;
		return array;
	}
	int temp;

	// 1º Buscamos una j tal que a[j] < a[j+1]
	int j = lenght - 2;
	while (array[j] > array[j+1]) {
		j--;
	}

	// 2º Buscamos una k tal que a[j] < a[k]
	int k = lenght - 1;
	while (array[j] > array[k]) {
		k--;
	}

	 // 3º Swap entre a[j] y a[k]
	temp = array[k];
	array[k] = array[j];
	array[j] = temp;

	// 4º Hacemos swap entre todos los valores a[s] y a[r]
	int r = lenght - 1;
	int s = j + 1;

	while (r > s) {
		temp = array[s];
          	array[s] = array[r];
          	array[r] = temp;
          	r--;
          	s++;
	}
	numLeft = numLeft - 1;
        return array;
}
