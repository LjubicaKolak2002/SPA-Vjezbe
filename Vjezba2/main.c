#include "stl.h"
#include <stdio.h>

int main()
{
	FILE* fp = fopen("primjerbin.stl", "rb");
	if (fp) {
		printf("radi\n");
	}
	if (!fp)
	{
		printf("Datoteka se ne moze otvoriti!\n");
	}
	Objekt3D* objekt = cita_binarno(fp);
	fclose(fp);

	/*FILE* fp2 = fopen("binarna2.stl", "wb");
	if (!fp2)
	{
		printf("Datoteka se ne moze otvoriti\n");
	}
	else {
		zapisuje_bin(fp2, objekt);

	}
	fclose(fp2);

	FILE* fp3 = fopen("tekstualna2.stl", "wt");
	if (!fp3)
	{
		printf("Datoteka se ne moze otvoriti\n");
	}
	else {
		zapisuje_tex(fp3, objekt);
	}
	fclose(fp3);

	//brise_Objekt3D(objekt);*/
}