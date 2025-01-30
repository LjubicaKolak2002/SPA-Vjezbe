/*int* filtriraj(int *niz, int n, int th, int *nth) – vraca novi niz koji sadrzi brojeve iz originalnog niza koji su manji od th.
Originalni niz ima duzinu n. Duzinu novog niza sa brojevima koji su prosli filter treba spremiti u nth. */
#include <stdio.h>
#include <stdlib.h>
int* filtriraj(int* niz, int n, int th, int* nth)
{
	int i,brojac = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			brojac++;
		}
	}

	int* novi = (int*)malloc(brojac * sizeof(int));
	if (!novi)
		return NULL;
	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			novi[j] = niz[i];
			j++;
		}
	}
	*nth = j;
	return novi;
}
int main1()
{
	int niz[] = { 4, 3, 2, 1, 8, 7, 6, 11, 23, 13};
	int n = sizeof(niz) / sizeof(niz[0]);
	int th = 8, nth, i;
	int* ispis = filtriraj(niz, n, th, &nth);
	for (i = 0; i < nth; i++)
	{
		printf("%d ", ispis[i]);
	}
	free(ispis);
	return 0;
}