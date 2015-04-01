/*		Capitulo 6 Apartado b
	Curso c++
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NMA 100 // máximo número de elementos de la matriz

enum clase // tipo enumerado
{
	libro, revista
};


typedef struct // estructura variable
{
	unsigned numref;
	char titulo[30];
	char autor[20];
	char editorial[25];
	enum clase libro_revista;
	union
	{
		struct
		{
			unsigned edicion;
			unsigned anyo;
		} libros;
		char nomrev[30];
	} lr;
} tficha3; // FICHA DE LIBRO

/***************************************************************
Función lee datos de libros y revistas
***************************************************************/
int static leerFicha(tficha3 bibli[], int NMAX)
{
	int clase;
	char resp = 's';
	int k = 0; // número de elementos introducidos
	while (tolower(resp) == 's' && k < NMAX)
	{		
		printf("Numero de refer. ");
		scanf("%u", &bibli[k].numref);
		printf("Titulo           ");
		scanf("%s", bibli[k].titulo);
		printf("Autor            ");
		scanf("%s", bibli[k].autor);
		printf("Editorial        ");
		scanf("%s", bibli[k].editorial);

		do
		{
			printf("Libro o revista (0 = libro, 1 = revista) ");
			scanf("%d", &clase); fflush(stdin);
		} while (clase != 0 && clase != 1);
		if (clase == libro)
		{
			bibli[k].libro_revista = libro;
			printf("Edicion          ");
			scanf("%u", &bibli[k].lr.libros.edicion);
			printf("Anyo de public.   ");
			scanf("%u", &bibli[k].lr.libros.anyo); fflush(stdin);
		}
		else
		{
			bibli[k].libro_revista = revista;
			printf("Nombre revista   "); gets(bibli[k].lr.nomrev);
		}
		k++;
		do
		{
			printf("\nMas datos a introducir? s/n ");
			resp = getchar();
			fflush(stdin);
		} while (tolower(resp) != 's' && tolower(resp) != 'n');
	}
	return k;
}

/***************************************************************
Función para listar todos los elementos de la matriz***************************************************************/
void static escribirFicha(tficha3 bibli[], int n)
{
	system("cls");
	printf("\t** MOSTRANDO BIBLIOTECA COMPLETA **\n\n");
	int k = 0;
	for (k = 0; k < n; k++)
	{
		printf("%d  %s\n", bibli[k].numref, bibli[k].titulo);
		printf("%s - Ed. %s\n", bibli[k].autor, bibli[k].editorial);

		switch (bibli[k].libro_revista)
		{
		case libro:
			printf("Edición %u - año %u\n",
				bibli[k].lr.libros.edicion,
				bibli[k].lr.libros.anyo);
			break;
		case revista:
			printf("%s\n", bibli[k].lr.nomrev);
		}
		system("pause");
	}
}

// Menu principal de este partado
void static uniones()
{
	static tficha3 biblioteca[NMA]; // matriz de estructuras
	int n = 0; // número actual de elementos de la matriz
	system("cls");

	printf("\t**UNIONES Y ESTRUCTURAS VARIABLES\n\n");
	printf("\t**BIBLIOTECA**\n\tINTRODUCCION DE DATOS**\n\n");
	
	printf("Introducir datos.\n");
	n = leerFicha(biblioteca, NMA);	
	printf("Listado de libros y revistas\n");
	escribirFicha(biblioteca, n); // listar todos los libros y revistas
}