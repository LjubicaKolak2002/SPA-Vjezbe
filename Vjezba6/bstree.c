#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

// Novo prazno stablo
BSTree NewBSTree() {
	return NULL;
}


// Rekurzivno se trazi mjesto za novi cvor u stablu. Ako rijec postoji u stablu, ne dodaje se.
// bst parametar je dvostruki pokazivac.
void AddNode(BSTree* bst, char* word) {

	if ((*bst) == NULL) {
		(*bst) = (Node*)malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else {
		if (strcmp((*bst)->word, word) > 0) {
			AddNode(&(*bst)->left, word);
		}
		else if (strcmp((*bst)->word, word) < 0) {
			AddNode(&(*bst)->right, word);
		}
		else {
			return;
		}
	}
}

// Rekurzivno se prolazi cijelo stablo da bi se pronasla najduza grana (visina stabla).
int BSTHeight(BSTree bst) {
	if (bst == NULL)
		return 0;

	int left = BSTHeight(bst->left);
	int right = BSTHeight(bst->right);


	int max = (left > right) ? left : right;

	return 1 + max;
}

// Ispisuje rijeci u stablu na ekran po abecednom redu.
// In-order setnja po stablu (lijevo dijete, cvor, desno dijete)

void PrintBSTree(BSTree bst) {
	if (bst == NULL)
		return;

	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);

}
// Snima rijec po rijec iz stabla u tekstualnu datoteku. Rijeci su odvojene razmakom.
// Pre-order setnja po stablu (trenutni cvor pa djeca)
void SaveBSTree(BSTree bst, FILE* fd) {
	if (bst == NULL)
		return;

	fprintf(fd, "%s", bst->word);
	fprintf(fd, " ");

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);


}
// Brise stablo (string word i sam cvor) iz memorije.
// Post-order setnja po stablu (prvo djeca pa trenutni cvor)
void DeleteBSTree(BSTree bst) {

	if (bst == NULL)
		return;

	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);
}

// Ucitava rijec po rijec iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
// Rijeci duplicirati sa strdup().
BSTree LoadBSTree(FILE* fd)
{
	BSTree bst = NewBSTree();
	char buffer[1024];

	while (readWord(fd, buffer)) {
		AddNode(&bst, _strdup(buffer));
	}

	return bst;

}


