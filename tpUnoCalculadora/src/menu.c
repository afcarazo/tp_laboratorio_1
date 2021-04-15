/*
 * experienciaDeUsuario.c
 *
 *
 *  Created on: Apr 8, 2021
 *      Author: Agust
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "biblioteca.h"

void activarFlag(float *c) {
	*c = 1;
}

void resetFlag(float *b, float *x, float* f) {
	*b = 0;
	*x = 0;
	*f = 0;
}

int menu(float a, float b, float flagNumeroUno, float flagNumeroDos)

{
	int opcion;
	printf("\n *********************************** \n");
	printf("\n *** Bienvenido a la calculadora *** \n");
	printf("\n *********************************** \n");
	printf("\n\n  Menu de opciones \n\n");
	if (flagNumeroUno == 0) {
		printf("\n 1. Ingresar 1er operando (A=x)\n");
	}else{
		printf("\n 1. Ingresar 1er operando (A=%.2f)\n", a);
	}

	if (flagNumeroDos == 0) {
		printf("\n 2. Ingresar 2do operando (B=x)\n");
	} else {
		printf("\n 2. Ingresar 2do operando (B=%.2f)\n", b);
	}
	printf("\n 3. Calcular las operaciones: \n");
	printf("\n a) Calcular la suma (A+B)\n");
	printf("\n b) Calcular la resta (A-B)\n");
	printf("\n c) Calcular la division (A/B)\n");
	printf("\n d) Calcular la multiplicacion (A*B)\n");
	printf("\n e) Calcular el factorial (A!) y (!B)\n");
	printf("\n 4. Informar resultados\n");
	printf("\n 5. Salir\n");
	printf("\n Seleccione una opcion: ");
	scanf("%d", &opcion);
	return opcion;
}
