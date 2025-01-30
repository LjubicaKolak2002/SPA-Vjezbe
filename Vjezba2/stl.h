#ifndef STL_H
#define STL_H
#include <stdio.h>

typedef struct {
	float x, y, z;
}Vrh;

typedef struct {
	Vrh normala; // nx, n2y ....
	unsigned short boja;
	Vrh koordinata[3]; // v1x, v2x, v3x, v2y ... 
}Trokut;

typedef struct {
	Trokut* niz;
	unsigned int n;
}Objekt3D;


Objekt3D* cita_binarno(FILE* fp);
void zapisuje_bin(FILE* fp2, Objekt3D* objekt);
void zapisuje_tex(FILE* fp3, Objekt3D* objekt);
void brise_Objekt3D(Objekt3D* objekt);
void cita_tex(FILE* fp4);



#endif

