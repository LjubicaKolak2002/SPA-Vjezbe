#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892
// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaca)

HashTable* NewTable(int size) {

	HashTable* new_table = (HashTable*)malloc(sizeof(HashTable));
	new_table->size = size;
	new_table->load = 0;
	new_table->table = (Bin**)malloc(size * sizeof(Bin*));

	for (int i = 0; i < new_table->size; i++) {
		new_table->table[i] = NULL;
	}
	return new_table;
}

// od kljuca generira hash kod
unsigned int hash(char* word) {

	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

// dodaje novu rijec u listu na odgovarajucem pretincu
void Insert(HashTable* ht, char* word) {

	unsigned int key = hash(word);
	int index = key % ht->size;
	
	Bin* lst = (Bin*)malloc(sizeof(Bin));

	lst->word = word;
	/*lst->next = NULL;
	if (ht->table[index] == NULL) {
		ht->table[index] = lst;
		ht->load++;
		return;
	}
	*/

	lst->next = ht->table[index];
	ht->table[index] = lst; 
	ht->load++;
}

// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
int Get(HashTable* ht, char* word) {

	unsigned int index = hash(word) % ht->size;

	Bin* ht2 = ht->table[index];
	while (ht2 != NULL)
	{
		if (strcmp(ht2->word, word) == 0) {
			return 1;
		}

		else {
			ht2 = ht2->next;
		}
	}
	return 0;
}

// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
void DeleteTable(HashTable* ht) {

	for (int i = 0; i < ht->size; i++) {

		Bin* h = ht->table[i]; 
		while (h != NULL)
		{
			Bin* tmp = h;
			h = h->next;
			free(tmp->word);
			free(tmp);
		}
	}
	free(ht->table);
	free(ht);

}



