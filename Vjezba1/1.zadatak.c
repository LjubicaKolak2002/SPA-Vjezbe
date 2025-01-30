/*int* podniz(int *niz, int start, int stop) – vraca novi niz koji je kopija dijela niza od indeksa start do indeksa stop.*/
#include <stdio.h>
#include <stdlib.h>
int* podniz(int* niz, int start, int stop)
{
	int* novi = (int*)malloc((stop - start) * sizeof(int));
	if (!novi)
		return NULL;
	int i, j = 0;
	for (i = start; i < stop ; i++)
	{
		novi[j] = niz[i];
		j++;
	}
	return novi;

}

int main0()
{
	int niz[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int start = 3;
	int stop = 7;
	int* ispis = podniz(niz, start, stop);
	int duljina = stop - start;
	int i;
	for (i = 0; i < duljina; i++)
	{
		printf("%d ", ispis[i]);
	}
	free(ispis);
	return 0;
}