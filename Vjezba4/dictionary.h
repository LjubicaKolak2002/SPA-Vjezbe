#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char* word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word* next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// brise cijeli rjecnik
void destroy(Dictionary dict);

int filter(Word* w);

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));

//trazi najduzu rijec
char* find_max(Dictionary dict);

//racuna ukupan broj rijeci
int count_word(Dictionary dict);

//dodavanja novog elementa na pocetak
void add_to_start(Dictionary dict, char* word);

//dodavanje elementa na kraj
void add_at_end(Dictionary dict, char* word);

//dodavanje prije nekog elementa u listi
void add_before(Dictionary dict, char* word, char* word2);
#endif

