/*Deklarirati strukturu Tocka koja sadrzi dva clana: x i y (oba su float). Deklarirati strukturu Poligon koja se sadrzi dva clana:
niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:
Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji ce kao vrhove imati 
parove brojeva iz nizova. Nizovi su duzine n (≥ 3).  */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	float x, y;
}Tocka;

typedef struct {
	Tocka* niz;
	int n;
}Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	if (n < 3)
	{
		printf("Duljina niza nije zadovoljavajuca\n");

	}
	Poligon* novi = (Poligon*)malloc(sizeof(Poligon));
	if (!novi)
		return NULL;

	novi->niz = (Tocka*)malloc(n * sizeof(Tocka));
	novi->n = n;
	for (int i = 0; i < n; i++)
	{
		novi->niz[i].x = niz_x[i];
		novi->niz[i].y = niz_y[i];
	}
	return novi;
}
/*Tocka** pozitivni(Poligon *p, int *np) – funkcija vraca niz pokazivaca na vrhove poligona kojima su obje koordinate pozitivne. 
Broj elemenata u nizu ce biti spremljen u np parametar.*/
Tocka** pozitivni(Poligon* p, int* np)
{
	int brojac = 0, j = 0, i;
	for (i = 0; i < p->n; i++)
	{
		if ((p->niz[i].x > 0) && (p->niz[i].y > 0))
			brojac++;
	}

	Tocka** novi = (Tocka**)malloc(brojac * sizeof(Tocka*));
	if (!novi)
		return NULL;

	for (i = 0; i < p->n; i++)
	{
		if ((p->niz[i].x > 0) && (p->niz[i].y > 0))
		{
			novi[j] = &(p->niz[i]);
			j++;
		}
	}
	*np = j;
	return novi;
}


int main()
{
	float niz_x[] = { 1.3, 6.7, 8.9, -12.5, 5.6 };
	float niz_y[] = { 9.8, 7.7, -12.5, 6.4, 3.9 };
	int n = sizeof(niz_x) / sizeof(niz_x[0]);
	Poligon* ispis = novi_poligon(niz_x, niz_y, n);
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%f %f\n", ispis->niz[i].x, ispis->niz[i].y);
	}
	printf("\n");
	int np;
	Tocka** ispis2 = pozitivni(ispis, &np);
	for (i = 0; i < np; i++) {
		printf("%f %f\n", ispis2[i]->x, ispis2[i]->y);

	}
	free(ispis[0].niz);
	free(ispis);
	free(ispis2);
}