/* Cap 6 - Estructuras de datos
* estructuras.cpp
*/
#include <stdio.h>
#define NELEMENTOS 10
#define NLETRAS ('z'-'a'+1)
#define EO '~'
#define FILAS_MAX 10  // número máximo de filas
#define COLS_MAX  10  // número máximo de columnas
//-----------variables de copiarmatrices----------------
#define FILAS 3			// filas
#define COLS 3			// columnas
//----------Variables matriz ST ------------------------
#define NA 100      // número máximo de alumnos

// copia una array en otro
void static CopiarArrays(float destino[][COLS], float origen[][COLS])
{
	int fila = 0, col = 0;
	for (fila = 0; fila < FILAS; fila++)
	{
		for (col = 0; col < COLS; col++)
			destino[fila][col] = origen[fila][col];
	}
}

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
		printf("Numero de filas de la matriz:    ");
		scanf("%d", &filas);
	}
	while (filas < 1 || filas > FILAS_MAX);
	
	do
	{
		printf("Numero de columnas de la matriz: ");
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

// copia el contenido de una matrz en otra
void static copiarMatrices()
{
	static float a[FILAS][COLS], c[FILAS][COLS];

	int fila = 0, col = 0;
	// Leer datos para la matriz a
	for (fila = 0; fila < FILAS; fila++)
	{
		for (col = 0; col < COLS; col++)
		{
			printf("a[%d][%d] = ", fila, col);
			scanf("%f", &a[fila][col]);
		}
	} // llenamos matriz a

	CopiarArrays(a, c);

	// Escribir los datos de la matriz c
	for (fila = 0; fila < FILAS; fila++)
	{
		// Escribir una fila
		for (col = 0; col < COLS; col++)
			printf("%10g", c[fila][col]);

		printf("\n"); // fila siguiente
	}
}

//--------DEFINICIO DE ESTRUCTURAS-----------------
typedef struct
{
	int dia, mes, anyo;
} tfecha;

typedef struct
{
	char nombre[40];
	char direccion[50];
	long telefono;
	tfecha fecha_nacimiento;
} tficha;
// trabajo con estructuras------------------------
void static estructuras()
{
	tficha persona, otraPersona;

	// introduccion de datos de la persona
	printf("Nombre :  ");
	scanf("%s", &persona.nombre);
	printf("Direccion :  ");
	scanf("%s", &persona.direccion);
	printf("Telefono :  ");
	scanf("%ld", &persona.telefono); // conversion a long
	printf("Fecha de nacimiento \n");
	printf("Dia :  ");
	scanf("%d", &persona.fecha_nacimiento.dia);// int
	printf("Mes :  ");
	scanf("%d", &persona.fecha_nacimiento.mes);
	printf("Año :  ");
	scanf("%d", &persona.fecha_nacimiento.anyo);

	// copia de estucturas
	otraPersona = persona;

	// escribir los datos de la estructura copiada
	printf("\n\n---------------\n");
	printf("Nombre : %s \n", otraPersona.nombre);
	printf("Direccion : %s \n", otraPersona.direccion);
	printf("Telefono : %ld \n", otraPersona.telefono);
	printf("Fecha Nac:  :");
	printf("%d / ", otraPersona.fecha_nacimiento.dia);
	printf("%d / ", otraPersona.fecha_nacimiento.mes);
	printf("%d \n", otraPersona.fecha_nacimiento.anyo);
}
//-------DEFINICIONES MATRIZ ST -----------------------------
typedef struct
{
	char nombre[60];
	float nota;
} tficha2;

void static matrizSt()
{
	static tficha2 alumno[NA];	// matriz estructura
	int n = 0, i = 0;
	char *fin = NULL;  // para almacenar gets
	int aprobados = 0, suspendidos = 0;

	//entrada de datos
	printf("Introducir Datos");
	printf("Para finalizar introduzca ~");

	printf("Nombre");
	fin = gets(alumno[n].nombre);
	printf("%s", alumno[n].nombre);
}