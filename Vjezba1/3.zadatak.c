/*int** podijeli(int *niz, int n) – dijeli niz duzine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. 
Funkcija vraca dva pokazivaca koji pokazuju na prvi i na drugi dio.*/
#include <stdio.h>
#include <stdlib.h>
int** podijeli(int* niz, int n)
{
	int i, j = 0, k = 0;
	int duljina1 = n / 2;
	int duljina2 = n - duljina1;
	int* kopija1 = (int*)malloc(duljina1 * sizeof(int));
	int* kopija2 = (int*)malloc(duljina2 * sizeof(int));
	int** ispis = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++)
	{
		if (i < duljina1)
		{
			kopija1[j] = niz[i];
			j++;
		}
		else {
			kopija2[k] = niz[i];
			k++;
		}
	}
	ispis[0] = kopija1;
	ispis[1] = kopija2;
	return ispis;
}

int main3()
{
	int niz[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(niz) / sizeof(niz[0]);
	int duljina1 = n / 2;
	int duljina2 = n - duljina1;
	int i;
	int** ispis = podijeli(niz, n);

	for (i = 0; i < duljina1; i++)
	{
		printf("%d ", ispis[0][i]);
	}
	printf("\n");

	for (i = 0; i < duljina2; i++)
	{
		printf("%d ", ispis[1][i]);
	}
	free(ispis[0]);
	free(ispis[1]);
	free(ispis);
	return 0;
}