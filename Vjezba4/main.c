#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"
int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	/*FILE* fd;
	char buffer[1024];
	Dictionary dict;

	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		add(dict, buffer);
	}

	fclose(fd);

	print(dict);
	print(filterDictionary(dict, filter));

	destroy(dict);*/

	Dictionary dict = create();
	add(dict, "prva\n");
	add(dict, "druga\n");
	add(dict, "ovajenajduza\n");
	add(dict, "deseta\n");
	add(dict, "nedjelja\n");
	/*char* max_word = find_max(dict);
	printf("Najduza rijec je: %s\n", max_word);

	int number = count_word(dict);
	printf("Ukupan broj rijeci je: %d\n", number);*/

	//add_to_start(dict, "u glavu\n"); //izokrene ih zbog abecede
	//print(dict);
	//add_at_end(dict, "dodaj mene\n");
	//print(dict);
	add_before(dict, "end", "druga");
	print(dict);
}