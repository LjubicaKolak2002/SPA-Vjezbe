#include <stdio.h>
#include <string.h>
//mystrlen() – funkcija prima string (char*) i vraca integer koji predstavlja duzinu stringa.
int mystrlen(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}
//mystrcpy() – funkcija prima dva stringa i kopira drugi string u prvi string.
char* mystrcpy(char* string1, char* string2)
{
	int i;
	for (i = 0; i < mystrlen(string2); i++)
	{
		string1[i] = string2[i];

	}
	string1[i] = '\0';
	return string1;
}

/*mystrcmp() – funkcija prima dva stringa i usporeduje ih. Funkcija vraca: broj manji od nula ako je prvi string manji od drugog stringa 
(po leksikografskom poretku),broj veci od nula ako je drugi string manji od prvog i nula ako su stringovi jednaki.*/
int mystrcmp(char* string1, char* string2)
{
	int i;
	for (i = 0; (i < mystrlen(string1) || i < mystrlen(string2)); i++)
	{
		if (string1[i] < string2[i])
		{
			return -1;
		}
		if (string2[i] < string1[i])
		{
			return 1;
		}
	}
	return 0;
}

/*mystrcat() – funkcija „dodaje“ drugi string na kraj prvog stringa.*/
char* mystrcat(char* string1, char* string2)
{
	int i;
	int duljina1 = mystrlen(string1);
	int duljina2 = mystrlen(string2);
	for (i = 0; i < duljina2; i++)
	{
		string1[duljina1] = string2[i];
		duljina1++;
	}
	string1[duljina1] = '\0';
	return string1;
}

/*mystrstr() – funkcija vraca pokazivac (unutar prvog stringa) koji pokazuje na prvo pojavljivanje drugog stringa. Ako ga ne pronade, 
funkcija vraca NULL.*/

char* mystrstr(char* string1, char* string2)
{
	int i, j = 0;
	for (i = 0; i < strlen(string1); i++)
	{
		while (string1[i + j] == string2[j])
		{
			j++;
			if (j == strlen(string2))
			{
				return &(string1[i]);
			}
		}
	}
	return NULL;
}


/*reverse() – prima dva stringa i kopira prvi string u drugi string naopako (funkcija ne postoji u string.h)*/
char* reverse(char* string1, char* string2)
{
	int i, j = 0;
	for (i = strlen(string1) - 1; i >= 0; i--)
	{
		string2[j] = string1[i];
		j++;
	}
	string2[j] = '\0';
	return string2;
}
int main()
{
	/*char string[] = "duzina";
	printf("Mystrlen: %d, strlen: %d", mystrlen(string), strlen(string));
	*/

	/*char string1[50] = "prvi";
	char string2[] = "drugi";
	printf("Mystrcpy: %s, strcpy: %s", mystrcpy(string1, string2), strcpy(string1, string2));*/

	/*char string1[] = "abc";
	char string2[] = "cde";
	printf("Mystrcmp: %d, strcmp: %d", mystrcmp(string1, string2), strcmp(string1, string2));*/

	/*char string1[50] = "dodaj";
	char string2[] = "mene";
	char string3[50] = "treci";
	char string4[] = "cetvrti";
	printf("Mystrcat: %s, strcat: %s", mystrcat(string1, string2), strcat(string3, string4));*/

	char string1[] = "deset";
	char string2[] = "set";
	//char string1[] = "abaaaaabaa";
	//char string2[] = "aaab";
	printf("Mystrstr: %p, strstr: %p", mystrstr(string1, string2), strstr(string1, string2));


	/*char string1[] = "jedan";
	char string2[50] = "dva";
	printf("Reverse: %s", reverse(string1, string2));*/
	return 0;
}