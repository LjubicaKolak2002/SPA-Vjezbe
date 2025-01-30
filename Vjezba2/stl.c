#include "stl.h"
#include <stdio.h>
#include <stdlib.h>

//Funkciju koja cita binarnu STL datoteku i vraca ispunjenu Objekt3D  strukturu
Objekt3D* cita_binarno(FILE* fp)
{
	int i;
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	if (!objekt)
		return NULL;

	fseek(fp, 80, SEEK_SET);//zaglavlje, 80  nula

	fread(&(objekt->n), sizeof(unsigned int), 1, fp); //broj trokutova
	//printf("NIZ JE %d", objekt->n);
	objekt->niz = (Trokut*)malloc(objekt->n * sizeof(Trokut));
	if (!objekt->niz)
		return NULL;

	for (i = 0; i < objekt->n; i++)
	{
		fread(&(objekt->niz[i]), 50, 1, fp);
	}
	return objekt;
}

//Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
void zapisuje_bin(FILE* fp2, Objekt3D* objekt) {

	char zaglavlje[80] = { 0 };
	fwrite(zaglavlje, 1, 80, fp2);
	fwrite(&(objekt->n), sizeof(unsigned int), 1, fp2); //n trokuta
	for (int i = 0; i < objekt->n; i++)
	{
		fwrite(&(objekt->niz[i]), 50, 1, fp2);
	}
}

//Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
void zapisuje_tex(FILE* fp3, Objekt3D* objekt) {
	//zaglavlje?
	fprintf(fp3, "solid ime\n");
	int i, j;
	for (i = 0; i < objekt->n; i++)
	{
		fprintf(fp3, "\tfacet normal %f %f %f\n", objekt->niz[i].normala.x, objekt->niz[i].normala.y, objekt->niz[i].normala.z);
		fprintf(fp3, "\t\touter loop\n");

		for (j = 0; j < 3; j++)
		{
			fprintf(fp3, "\t\t\tvertex %f %f %f\n", objekt->niz[i].koordinata[j].x, objekt->niz[i].koordinata[j].y, objekt->niz[i].koordinata[j].z);
		}
		fprintf(fp3, "\t\tendloop\n");
		fprintf(fp3, "\tendfacet\n");
	}
	
}

//Funkciju koja brise Objekt3D strukturu
void brise_Objekt3D(Objekt3D* objekt) {
	free(objekt->niz);
	free(objekt);

}

//Napisati funkciju koja cita tekstualnu STL datoteku
void cita_tex(FILE* fp4) {

}
