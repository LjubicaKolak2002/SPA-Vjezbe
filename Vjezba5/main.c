#include "prioritetniRed.h"
#include <stdio.h>

int main() {

	PrioritetniRed* red = stvori();

	Element el;
	el.prioritet = 85;
	dodaj_na_kraj(red, el);

	el.prioritet = 60;
	dodaj_na_kraj(red, el);

	el.prioritet = 80;
	dodaj_na_kraj(red, el);

	el.prioritet = 25;
	dodaj_na_kraj(red, el);

	el.prioritet = 30;
	dodaj_na_kraj(red, el);

	el.prioritet = 70;
	dodaj_na_kraj(red, el);

	el.prioritet = 50;
	dodaj_na_kraj(red, el);

	el.prioritet = 23;
	dodaj_na_kraj(red, el);

	el.prioritet = 10;
	dodaj_na_kraj(red, el);

	el.prioritet = 20;
	dodaj_na_kraj(red, el);

	el.prioritet = 70;
	dodaj_na_kraj(red, el);

	/*Element el;
	el.prioritet = 2;
	dodaj_na_kraj(red, el);

	el.prioritet = 6;
	dodaj_na_kraj(red, el);

	el.prioritet = 2;
	dodaj_na_kraj(red, el);

	el.prioritet = 1;
	dodaj_na_kraj(red, el);

	el.prioritet = 8;
	dodaj_na_kraj(red, el);

	el.prioritet = 5;
	dodaj_na_kraj(red, el);

	el.prioritet = 4;
	dodaj_na_kraj(red, el);

	el.prioritet = 6;
	dodaj_na_kraj(red, el);

	el.prioritet = 7;
	dodaj_na_kraj(red, el);

	el.prioritet = 3;
	dodaj_na_kraj(red, el);*/

	ispis(red);

	ukloni_vrh(red);
	ispis(red);

	oslobodi(red);

	
}