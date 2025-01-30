#include "longnum.h"
#include <stdio.h>
#include <stdlib.h>

/*pomocna funkcija koja okrece listu znamenaka, trebati ce na vise mjesta jer ce se operacije uglavnom oslanjati na dodavanje u glavu liste
ne gradi novu listu nego preuredjuje dobivenu listu*/
LongNumber reverse(LongNumber num) {

	LongNumber previous = NULL;
	LongNumber current = num->next;
	LongNumber next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	num->next = previous;
	return num;
}

/*cita broj iz tekstualne datoteke znamenku po znamenku i gradi listu (dugi broj)*/
LongNumber read_longnum(char* fname) {
	FILE* fp = fopen(fname, "rt");
	if (!fp)
		printf("Datoteka se ne moze otvoriti\n");

	int number;

	LongNumber lst = (Digit*)malloc(sizeof(Digit));
	lst->z = 0; 
	lst->next = NULL;

	while ((number = fgetc(fp)) != EOF){
		LongNumber new_num = (Digit*)malloc(sizeof(Digit));
		new_num->z = number - '0';

		new_num->next = lst->next;
		lst->next = new_num;
	}
	fclose(fp);
	return lst;
}

/*ispisuje broj na ekran */
void print_longnum(LongNumber num) {

	num = reverse(num);
	LongNumber tmp = num ->next;

	while (tmp != NULL) {
		printf("%d", tmp->z);
		tmp = tmp->next;
	}
	printf("\n");
	num = reverse(num);

}

/*zapisuje broj u tekstualnu datoteku znamenku po znamenku*/
void write_longnum(LongNumber num, char* fname) {
	FILE* fp2 = fopen(fname, "wt");
	if (!fp2)
		printf("Datoteka se ne moze otvoriti\n");

	num = reverse(num);

	LongNumber tmp = num->next;
	while (tmp != NULL) {

		fprintf(fp2, "%d", tmp->z);
		tmp = tmp->next;
	}

	fclose(fp2);
	
	num = reverse(num);
}

/*oslobadja listu znamenaka*/
void delete_longnum(LongNumber num) {

	while (num != NULL) {
		LongNumber tmp = num;
		num = num->next;
		free(tmp);
	}
}
	
/*zbraja dva broja. Algoritam zbraja znamenku po znamenku i prenosi ostatak na iducu znamenku.Gradi se potpuno nova lista (broj) kao rezultat.*/
LongNumber add_longnum(LongNumber a, LongNumber b) {
	LongNumber tmpA = a->next;
	LongNumber tmpB = b->next;

	int carry = 0;
	int res = 0;

	LongNumber new_lst = (Digit*)malloc(sizeof(Digit));
	new_lst->z = 0;
	new_lst->next = NULL;

	while (tmpA != NULL || tmpB != NULL) {
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->next = NULL;
		if (tmpA == NULL && tmpB != NULL) {  
			res = tmpB->z + carry;
		}

		else if (tmpA != NULL && tmpB == NULL) {
			res = tmpA->z + carry;
		}

		else {
			res = tmpA->z + tmpB->z + carry;
		}

		carry = 0;

		if (res <= 9) {
			new_elem->z = res; 
			new_elem->next = new_lst->next;
			new_lst->next = new_elem;
		}
		else {
			new_elem->z = res % 10;
			new_elem->next = new_lst->next;
			new_lst->next = new_elem;
			carry = 1;
		}

		tmpA = tmpA != NULL ? tmpA->next : NULL;
		tmpB = tmpB != NULL ? tmpB->next : NULL;
		res = 0;
	}

	if (carry == 1) {
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->z = 1;
		new_elem->next = new_lst->next;
		new_lst->next = new_elem;
	}

	return reverse(new_lst);
}

/*pomocna funkcija koja mnozi broj sa znamenkom (uz prenosenje ostatka na iducu znamenku). Gradi se potpuno nova lista (broj) kao rezultat.*/
LongNumber mul_by_digit(LongNumber num, int z) {

	LongNumber lst = (Digit*)malloc(sizeof(Digit));
	lst->z = 0;
	lst->next = NULL;

	int carry = 0;
	int res = 0;

	LongNumber tmp = num->next;

	while (tmp != NULL) {
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->next = NULL;

		res = tmp->z * z + carry;
		carry = 0; 

		if (res <= 9) {
			new_elem->z = res;
			new_elem->next = lst->next;
			lst->next = new_elem;
		}

		else {
			new_elem->z = res % 10;
			new_elem->next = lst->next;
			lst->next = new_elem;
			carry = res / 10;
			//printf("%d ", carry);
		}
		tmp = tmp->next;
		res = 0;
	}
	if (carry > 0) {
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->z = carry;
		new_elem->next = lst->next;
		lst->next = new_elem;
	}
	return reverse(lst);
}


/*pomocna funkcija koja mnozi broj sa potencijom od 10 (odnosno dodaje nule na pocetak broja) Gradi se potpuno nova lista (broj) kao rezultat.*/
LongNumber mul_by_pow10(LongNumber num, int pow) {

	LongNumber lst = (Digit*)malloc(sizeof(Digit));
	lst->z = 0;
	lst->next = NULL;

	int res = 0;
	LongNumber tmp = num->next;
	for (int i = 0; i < pow; i++) { 
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->z = 0;
		new_elem->next = lst->next;
		lst->next = new_elem;
	}

	while (tmp != NULL) {
		LongNumber new_elem = (Digit*)malloc(sizeof(Digit));
		new_elem->z = tmp->z;
		new_elem->next = lst->next;
		lst->next = new_elem;

		tmp = tmp->next;
	}

	return reverse(lst);
}

//Mnozi dva broja oslanjajuci se na prethodne funkcije
LongNumber mul_longnum(LongNumber a, LongNumber b) {

	LongNumber tmpB = b->next;

	LongNumber new_lst = (Digit*)malloc(sizeof(Digit));
	new_lst->z = 0;
	new_lst->next = NULL;

	int pow = 0;

	while (tmpB != NULL) {
		LongNumber elem = mul_by_pow10(a, pow);

		LongNumber tmp = mul_by_digit(elem, tmpB->z);

		new_lst = add_longnum(new_lst, tmp);

		tmpB = tmpB->next;

		pow++;

	}
	return new_lst;
}