#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//kreaira novi prazni rjecnik
Dictionary create() {
	Dictionary empty_dic = (Word*)malloc(sizeof(Word));
	if (!empty_dic)
		return NULL;

	empty_dic->word = NULL;
	empty_dic->count = 0;
	empty_dic->next = NULL;

	return empty_dic;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku, rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str) {

	Dictionary tmp = dict;
	while (tmp->next != NULL) {
		if (strcmp(tmp->next->word, str) == 0) {
			(tmp->next->count)++;
			return;
		}
		else if (strcmp(tmp->next->word, str) > 0) {
			Dictionary new_dic = (Word*)malloc(sizeof(Word));
			if (!new_dic)
				return NULL;

			new_dic->word = _strdup(str);
			new_dic->count = 1;
			new_dic->next = NULL;

			new_dic->next = tmp->next;
			tmp->next = new_dic;
			return;

		}
		tmp = tmp->next;
	}
	Dictionary new_dic = (Word*)malloc(sizeof(Word));
	if (!new_dic)
		return NULL;

	new_dic->word = _strdup(str);
	new_dic->count = 1;
	new_dic->next = NULL;

	tmp->next = new_dic;

}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict) {
	Dictionary tmp = dict->next;

	while (tmp != NULL) {
		printf("%s, %d" ,tmp->word, tmp->count);
		tmp = tmp->next;
		printf("\n");
	}
}

// brise cijeli rjecnik
void destroy(Dictionary dict) {

	while (dict->next != NULL) {
		Dictionary tmp = dict->next;
		dict->next = dict->next->next; //da sacuva iduci nakon brisanja
		free(tmp->word);
		free(tmp);
	}
	free(dict);
}

//Funkcija filter() vraca 1 ako je broj pojavljivanja rijeci između 5 i 10 i ako je rijec duza od 3 znaka.
int filter(Word* w) {
	if (((w->count >= 5) && (w->count <= 10)) && (strlen(w->word) > 3)) {
		return 1;
	}
	else {
		return 0;
	}
}

//Funkcija filterDictionary() vraca izmijenjenu indict listu koja sadrzi samo rijeci za koje je filter()
//funkcija vratila 1 (sve druge rijeci se oslobadaju).
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {

	Dictionary tmp = indict;
	Dictionary tmp_next = indict->next;

	if (indict == NULL) {
		return indict;
	}

	while (tmp_next!= NULL) {
		if (filter(tmp_next) == 0) {
			tmp->next = tmp_next->next;

			free(tmp_next->word);
			free(tmp_next);

			tmp_next = tmp->next;
		}
		else {

			tmp = tmp->next;
			tmp_next = tmp_next->next;
		}
	}
	return indict;
}
//trazi najduzu rijec
char* find_max(Dictionary dict) {
	Dictionary tmp = dict;
	char* max = dict->next->word; //prva rijec je na pocetku najveca
	while (tmp->next != NULL) {
		if (strlen(tmp->next->word) > strlen(max)) {
			max = tmp->next->word;
		}
		tmp = tmp->next;
	}
	return max;
}

//racuna ukupan broj rijeci
int count_word(Dictionary dict) {
	
	Dictionary tmp = dict;
	int cnt = 0;
	while (tmp->next != NULL) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;
	
}
//dodavanje na pocetak
void add_to_start(Dictionary dict, char* word) {
	Dictionary tmp = dict->next;

	Dictionary new_dic = (Word*)malloc(sizeof(Word));

	new_dic->word = _strdup(word);
	new_dic->count = 1;
	new_dic->next = NULL;

	dict->next = new_dic;
	new_dic->next = tmp;

	if (dict == NULL) {
		dict = new_dic;
	}


}

//dodavanje na kraj
void add_at_end(Dictionary dict, char* word) {
	Dictionary tmp = dict;
	Dictionary new_dic = (Word*)malloc(sizeof(Word));

	if (dict == NULL) { //ako je prazna lista
		new_dic->next = dict;
		//return new_dic;
	}

	new_dic->word = _strdup(word);
	new_dic->count = 1;
	new_dic->next = NULL;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_dic;
	new_dic->next = NULL;
	//return dict;
}

//dodavanje prije nekog elementa u listi
void add_before(Dictionary dict, char* word, char* word2) {
	Dictionary new_dic = (Word*)malloc(sizeof(Word));
	Dictionary tmp = dict;

	new_dic->word = _strdup(word);
	new_dic->count = 1;
	//nema new_dic = NULL jer nije zadnji element

	if (dict == NULL) { //prazan
		new_dic->next = NULL;
	}

	if (dict->next == NULL) { //1 element
		new_dic->next = dict;

	}

	while (tmp->next != NULL && strcmp(tmp->next->word, word2) != 0) {
		tmp = tmp->next;
	}
	new_dic->next = tmp->next;
	tmp->next = new_dic;

	


}