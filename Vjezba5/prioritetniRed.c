#include "prioritetniRed.h"
#include <stdio.h>
#include <stdlib.h>

//stvaranje prioritetnog reda
PrioritetniRed* stvori() {

	PrioritetniRed* novi = (PrioritetniRed*)malloc(sizeof(PrioritetniRed));

	novi->niz = (Element*)malloc(10000 * sizeof(Element));
	novi->n = 0;

	return novi;
}

//popravljanje gomile prema vrhu
void popravi_prema_vrhu(PrioritetniRed* red, int c) {

	if (c == 0) {
		return;
	}

	if ((red->niz[c].prioritet) > (red->niz[((c - 1) / 2)].prioritet)) {

		Element tmp = red->niz[c];
		red->niz[c] = red->niz[((c - 1) / 2)];
		red->niz[((c - 1) / 2)] = tmp;

		popravi_prema_vrhu(red, ((c - 1) / 2));
	}
}

//dodavanje elementa na kraj
void dodaj_na_kraj(PrioritetniRed* red, Element element) {

	red->niz[red->n] = element;
	red->n++;

	popravi_prema_vrhu(red, (red->n - 1));
}

//popravljanje gomile s vrha prema dnu
void popravi_prema_dnu(PrioritetniRed* red, int r) {

	int l = 2 * r + 1;
	int d = 2 * r + 2;
	int max;

	if (l >= red->n && d >= red->n) {
		return;
	}
	//else if (l <= red->n && d > red->n)
		//max = l;
	else {
		if (red->niz[d].prioritet > red->niz[l].prioritet)
			max = d;
		else if (red->niz[l].prioritet > red->niz[d].prioritet)
			max = l;
	}

	if (red->niz[max].prioritet >= red->niz[r].prioritet) {
		Element tmp = red->niz[r];
		red->niz[r] = red->niz[max];
		red->niz[max] = tmp;

		popravi_prema_dnu(red, max);
	}

}

//uklanjanje elementa sa vrha gomile
Element ukloni_vrh(PrioritetniRed* red) {
	//Element tmp = red->niz[0];
	red->niz[0] = red->niz[red->n - 1]; 
	red->niz[red->n - 1].prioritet = NULL;
	red->n--;

	popravi_prema_dnu(red, 0);

	return red->niz[0];
}


void ispis(PrioritetniRed* red) {

	for (int i = 0; i < red->n; i++) {
		printf("%d ", red->niz[i].prioritet);
	}
	printf("\n");
}

void oslobodi(PrioritetniRed* red) {
	free(red->niz);
	free(red);
}
