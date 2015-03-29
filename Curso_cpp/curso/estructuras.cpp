/* Cap 6 - Estructuras de datos
* estructuras.cpp
*/
#include <stdio.h>
#define NELEMENTOS 10
#define NLETRAS ('z'-'a'+1)
#define EOF '&'

//matriz unidimensional
void static matrizUni()
{
	printf("\n-MATRIZ_UNIDIMENSIONAL-\n");
	//creacion de una matriz unidimensional
	int m[NELEMENTOS]; // creacion de matriz
	int i = 0;			//subindice

	printf("\n*Introducir los valores de la matriz\n");

	// entrada de datos
	for (int i = 0; i < NELEMENTOS; i++)
	{
		printf("m[%d] = ", i);
		scanf("%d", &m[i]);
	}

	//salida de datos
	printf("\n\n");
	for (int i = 0; i < NELEMENTOS; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\n-MATRIZ_UNIDIMENSIONAL-\n");
	//--------------------------------------------------------------
}

// nº de apariciones de letras en un texto -------------------------
void static letras()
{
	int c[NLETRAS]; // matriz c
	char car;           // índice
	// Poner los elementos de la matriz a cero
	for (car = 'a'; car <= 'z'; car++)
		c[car - 'a'] = 0;
	// Entrada de datos y cálculo de la tabla de frecuencias
	printf("Introducir texto.\n");
	printf("Para finalizar introducir la marca &\n\n");
	while ((car = getchar()) != '&')
	{
		// Si el carácter leído está entre la 'a' y la 'z'
		// incrementar el contador correspondiente
		if (car >= 'a' && car <= 'z')
			c[car - 'a']++;
	}
	// Escribir la tabla de frecuencias
	for (car = 'a'; car <= 'z'; car++)
		printf("  %c", car);
	printf("\n  ---------------------------------------"
		"-------------------------------------\n");
	for (car = 'a'; car <= 'z'; car++)
		printf("%3d", c[car - 'a']);
	putchar('\n');
	//--------------------------------------------------------------
}

