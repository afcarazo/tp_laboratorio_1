/*
 * biblioteca.c
 *
 *  Created on: Apr 7, 2021
 *      Author: Agust
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "biblioteca.h"

float sumar(float a, float b)
{
    float suma;
    suma = a + b;
    return suma;
}

float resta(float a, float b)
{
    float resta;
    resta = a - b;
    return resta;
}

int dividirRobusta(int a, int b, float* c)
{
    int todoOk =0;

    if(b!=0 && c!= NULL)
    {
        *c = (float)a/b;
        todoOk=1;
    }

    return todoOk;
}


float multiplicacion(float a, float b)
{
    float multiplicacion;
    multiplicacion = a * b;
    return multiplicacion;
}


void factorial(int operadorUno, int operadorDos, int *factorialUno, int *factorialDos)

{
    float factorialPrimerOperando = 1;
    float factorialSegundoOperando = 1;

    if(operadorUno==1 || operadorUno==0 || operadorDos==1 || operadorDos==0 )
    {
        *factorialUno =1;
        *factorialDos =1;
    }
    else
    {
        for (float i = 1; i <= operadorUno; i++)
        {
            factorialPrimerOperando = factorialPrimerOperando * i;
        }
        for (float k = 1; k <= operadorDos; k++)
        {
            factorialSegundoOperando = factorialSegundoOperando * k;
        }
    }

    *factorialUno = factorialPrimerOperando;
    *factorialDos = factorialSegundoOperando;
}
