#include<iostream>
#include <stdlib.h>
#pragma warning(disable : 4996)

using namespace std;

typedef struct lista{
	unsigned int nr;
	lista *nastepna;
}lista;

int main() {
	unsigned int n, x;
	long int k;
	scanf("%i", &x);
	for (int j = 0; j < x; j++) {
		scanf("%i %i", &n, &k);
		if (k < 0)k = n + k + 1;
		//tworzenie list
		lista *glowa = (lista *)malloc(sizeof(lista));
		lista *l = glowa;
		lista *pom = glowa;
		//wype³nianie list
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				(*glowa).nr = 1;
				(*glowa).nastepna = glowa;
			}
			else if (i > 0 && i < n - 1) {
				l = (lista *)malloc(sizeof(lista));
				(*pom).nastepna = l;
				(*l).nr = i + 1;
				pom = l;
			}
			else if (i == n - 1) {
				l = (lista *)malloc(sizeof(lista));
				(*pom).nastepna = l;
				(*l).nr = i + 1;
				(*l).nastepna = glowa;
			}
		}
		//dzia³anie algorytmu polega na usuwaniu co drugiego elementu listy 
		//wyœwietlany jest tylko element który usuwany jest w kolejnoœci wed³ug liczby k
		l = (*glowa).nastepna;
		pom = glowa;
		for (int i = 0; i < n - 1; i++) {
			if (i == k - 1) {
				printf("%i\n", (*l).nr);
			}
			(*pom).nastepna = (*l).nastepna;
			pom = (*pom).nastepna;
			free(l);
			l = (*pom).nastepna;
		}
		if (n == k)printf("%i\n", (*l).nr);
		free(l);
	
	}
	return 0;
}