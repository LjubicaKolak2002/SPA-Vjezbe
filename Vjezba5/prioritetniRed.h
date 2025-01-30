#ifndef PRIORITETNIRED_H
#define PRIORITETNIRED_H

typedef struct _Element {
	void* podaci;
	int prioritet;
}Element;


typedef struct _PrioritetniRed {
	Element* niz;
	int n;
}PrioritetniRed;

PrioritetniRed* stvori();

void popravi_prema_vrhu(PrioritetniRed* red, int broj);

void dodaj_na_kraj(PrioritetniRed* red, Element element);

void popravi_prema_dnu(PrioritetniRed* red, int r);

Element ukloni_vrh(PrioritetniRed* red);

void ispis(PrioritetniRed* red);

void oslobodi(PrioritetniRed* red);

#endif
