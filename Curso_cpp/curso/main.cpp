#include <stdio.h>
#include "nota_media.cpp"
#include "estructuras.cpp"
#include <stdlib.h>
using namespace std;

int SALIR = 0;

//printf("\n-texto-\n");

void static menuCap6()
{	
	system("cls");
	printf("\n\t**MENU DE Capitulo 6 C++**\n\n");
	printf("\t1 - Ap1 - Notas Medias\n\n");
	printf("\t2 - Ap2 - Matriz Unidimensional\n\n");
	printf("\t3 - Ap3 - Contador de apariciones de letras\n\n");
	printf("\t4 - Ap4 - Entrada con get\n\n");
	printf("\t5 - Ap5 - Matriz Bidimensional\n\n");
	printf("\t6 - Ap6 - Copia de matrices\n\n");
	printf("\t7 - Ap7 - Estructuras\n\n");
	printf("\t8 - Ap8 - Matriz St\n\n");
	printf("\tv - Volver\n\n");
	printf("Elija una opcion :  ");

	// elegir opecion del menu	
	int cara=0;
	scanf("%d", &cara);

	switch (cara)
	{
	case 1:
		system("cls");
		//Pide notas x teclado,y calcula la media
		nota_media();
		break;
	case 2:
		system("cls");
		matrizUni(); /*matriz unidimensional*/
		break;
	case 3:
		system("cls");
		letras();  /* contador de apariciones de una letra en texto*/
		break;
	case 4:
		system("cls");
		getCpp();	  /* entrada de teclado con get*/
		break;
	case 5:
		system("cls");
		matrizBi();	  /* matriz bidimentnsional*/
		break;
	case 6:
		system("cls");
		copiarMatrices();  /* Copiar matrices */
		break;
	case 7:
		system("cls");
		estructuras();		/* estructuras */
		break;
	case 8:
		system("cls");
		matrizSt();		/* Matriz St */
		break;
	case 'v':
		break;
	}

	//cap 6 - Estructura de datos ----------------------------------------
}

int main()
{
	char car;
	
		system("cls");
		printf("\n\t**MENU DE CURSO C++**\n\n");
		printf("\t1 - Capitulo 6 - Estructuras de datos\n\n");
		printf("\tq - Salir\n\n");
		printf("\tEscoja una opcion :  ");

		// elegir opecion del menu	
		fflush(stdout);
		fflush(stdin);
		car = getchar();
		fflush(stdout);
		fflush(stdin);
		// Swuitch
		switch (car)
		{
		case '1':
			// Estructura de datos
			menuCap6();
			system("pause");
			break;
		case 'q':			
			break;	
	}	
	//--------------------------------------------------------------------
	
	//system("pause");
	return 0;
}