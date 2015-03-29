/* Cap 6 - Estructuras de datos
* estructuras.cpp
*/
#include <stdio.h>
#define NELEMENTOS 10
#define NLETRAS ('z'-'a'+1)
#define EO '~'
#define FILAS_MAX 10  // número máximo de filas
#define COLS_MAX  10  // número máximo de columnas

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
	printf("Para finalizar introducir la marca ~\n\n");

	while ((car = getchar()) != EO)
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

// introduccion de datos con get
void static getCpp()
{
	char *c = NULL; // para almacenar el valor retornado por gets
	char texto[40];
	printf("Introducir líneas de texto.\n");
	printf("Para finalizar introducir la marca EOF\n\n");

	// Leer la primera línea de texto
	c = gets(texto);

	while (c != NULL)
	{		
		// Leer otra línea de texto
		c = gets(texto);
	}
}

void static matrizBi()
{
	float m[FILAS_MAX][COLS_MAX];  // matriz m de dos dimensiones
	float sumafila;      // suma de los elementos de una fila
	int filas, cols;     // filas y columnas de la matriz de trabajo
	int fila, col;       // fila y columna del elemento accedido
	do
	{
		printf("Número de filas de la matriz:    ");
		scanf("%d", &filas);
	}
	while (filas < 1 || filas > FILAS_MAX);
	
	do
	{
		printf("Número de columnas de la matriz: ");
		scanf("%d", &cols);
	}
	while (cols < 1 || cols > COLS_MAX);

	// Entrada de datos
	printf("Introducir los valores de la matriz.\n");
	for (fila = 0; fila < filas; fila++)
		for (col = 0; col < cols; col++)
		{
			printf("m[%d][%d] = ", fila, col);
			scanf("%f", &m[fila][col]);
		}
	// Escribir la suma de cada fila
	for (fila = 0; fila < filas; fila++)
	{
		sumafila = 0;
		for (col = 0; col < cols; col++)
			sumafila += m[fila][col];
		printf("Suma de la fila %d = %g\n", fila, sumafila);
	}
	/*
	for (fila = 0; fila < filas; fila++)
	{
	sumafila  = 0;
	for (col = 0; col < cols; col++)
	{
	printf("c[%d][%d] = ", fila, col);
	scanf("%f", &m[fila][col]);
	sumafila += m[fila][col];
	}
	printf("Suma de la fila %d = %g\n", fila, sumafila);
	}
	*/

	printf("\nFin del proceso.\n");
}

