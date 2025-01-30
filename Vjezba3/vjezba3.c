#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* generiraj(n) – generira niz duzine n sa slucajnim elementima (svaki element se pojavljuje samo jednom u nizu)*/
int* generate(int n) {
	int* array = (int*)malloc(n * sizeof(int));
	array[0] = rand() % 5; // ubacimo na prvu mjesto neki mali broj
	for (int i = 1; i < n; i++) {
		array[i] = array[i - 1] + rand() % 5 + 1;
	}
	return array;
}

/* shuffle(skup) – mijesa elemente u nizu skup */
void shuffle(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n; // neki rand broj iz niza
		// napraviti swap 
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/* presjek(skupA, skupB) – funkcija racuna presjek dva skupa */
int* intersect(int* arrayA, int lenA, int* arrayB, int lenB) {  // O(lenA * lenB) - kvadratna slozenost
	int len = lenA >= lenB ? lenA : lenB; // uzima se duljina veceg
	int* intersectArray = (int*)malloc(len * sizeof(int));
	for (int i = 0, k = 0; i < lenA; i++) {
		for (int j = 0; j < lenB; j++) {
			if (arrayA[i] == arrayB[j]) {
				intersectArray[k] = arrayA[i];
				k++;
				i++;
			}
		}
	}
	return intersectArray;
}

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

/* presjek_sortiran(skupA, skupB) – funkcija racuna presjek dva skupa, gdje je skupB sortirani niz tako da se funkcija oslanja
na upotrebu upotrebom bsearch() funkcije (iz stdlib.h) */
int* intersect_sorted(int* arrayA, int lenA, int* arrayB, int lenB) { //O(lenA * loglenB)
	int len = lenA >= lenB ? lenA : lenB;  // uzimamo vecu duljinu 
	int* intersectArray = (int*)malloc(len * sizeof(int));

	//qsort(arrayB, lenB, sizeof(int), cmp); // qsort na arrayB

	for (int i = 0, j = 0; i < lenA; i++) {
		int* result = bsearch(&arrayA[i], arrayB, lenB, sizeof(int), cmp);
		if (result != NULL) {
			intersectArray[j] = *result;
			j++;
		}
	}
	return intersectArray;
}

int main() {
	srand((unsigned int)time(NULL));

	int* arrayA; int* arrayB; int* intersectArray; int* sortedArrayB; int* sortedArrayA;
	int start, stop;
	int nA = 30000;
	arrayA = generate(nA);
	// 1.slucaj -> duljina prvog na 30 000 elemenata, a drugi varira izmedu 10 000 do 50 000 s korakom od 500
	printf("1.slucaj: Duljina prvog fiksna, drugi varira\n");
	for (int nB = 10000; nB < 50000; nB += 5000) {
		arrayB = generate(nB);
		// izracun presjeka dva nesortirana niza
		start = clock();

		intersectArray = intersect(arrayA, nA, arrayB, nB);

		stop = clock();
		printf("Izracun presjeka za 2 nesortirana niza je: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 5.056, 7.607, 6.401, 7.374, 12.859, 12.493, 13.344, 14.598
		free(intersectArray);

		// izracun vremena izvodenja sortiranog i nesortiranog
		sortedArrayB = generate(nB);
		qsort(sortedArrayB, nB, sizeof(int), cmp);
		start = clock();

		intersectArray = intersect_sorted(arrayA, nA, sortedArrayB, nB);

		stop = clock();
		printf("Izracun presjeka nesortiranog i sortiranog bez qsorta: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 0.116, 0.09, 0.084, 0.112, 0.109, 0.184, 0.146, 0.091
		free(intersectArray);

		// izvodenje sortiranog i nesportiranog al racuna se i qsort 
		shuffle(sortedArrayB, nB);

		start = clock();

		qsort(sortedArrayB, nB, sizeof(int), cmp);
		intersectArray = intersect_sorted(arrayA, nA, sortedArrayB, nB);

		stop = clock();
		printf("Izracun presjeka nesortiranog i sortiranog sa qsortom: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 0.208, 0.158, 0.175, 0.165, 0.236, 0.354, 0.327, 0.264

		printf("\n");

		free(intersectArray);
		free(arrayB);
		free(sortedArrayB);
	}

	free(arrayA);


	// 2.slucaj -> duljina drugog na 30 000 elemenata, a prvi varira izmedu 10 000 do 50 000 s korakom od 500
	/*printf("2.slucaj: Duljina drugog fiksna, prvog varira\n");
	int nB = 30000;
	arrayB = generate(nB);

	for (int nA = 10000; nA < 50000; nA += 5000) {
		arrayA = generate(nA);
		// izracun presjeka dva nesortirana niza
		start = clock();

		intersectArray = intersect(arrayA, nA, arrayB, nB);

		stop = clock();
		printf("Izracun presjeka za 2 nesortirana niza je: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 3.157, 4.407, 6.171, 6.727, 7.869, 9.308, 10.530, 12.351
		free(intersectArray);

		// izracun vremena izvodenja sortiranog i nesortiranog
		sortedArrayB = generate(nB);
		qsort(sortedArrayB, nB, sizeof(int), cmp);
		start = clock();

		intersectArray = intersect_sorted(arrayA, nA, sortedArrayB, nB);

		stop = clock();
		printf("Izracun presjeka nesortiranog i sortiranog bez qsorta: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 0.029,0.049, 0.06, 0.073, 0.09, 0.091, 0.11, 0.168,
		free(intersectArray);

		// izvodenje sortiranog i nesportiranog al racuna se i qsort
		shuffle(sortedArrayB, nB);

		sortedArrayB = generate(nB);
		start = clock();

		qsort(sortedArrayB, nB, sizeof(int), cmp);
		intersectArray = intersect_sorted(arrayA, nA, sortedArrayB, nB);

		stop = clock();
		printf("Izracun presjeka nesortiranog i sortiranog sa qsortom: %lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		// 0.116, 0.118, 0.141, 0.173, 0.244, 0.152, 0.168, 0.179

		printf("\n");

		free(intersectArray);
		free(arrayA);
		free(sortedArrayB);
	}
	free(arrayB);
	*/
	return 0;
}
