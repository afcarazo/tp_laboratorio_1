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

int dividir(float a, float b, float* c)
{
    int todoOk =0;

    if(b!=0 && c!= NULL)
    {
        *c = a/b;
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


int factorial(int a, int *b)
{
    int todoOk = 0;
    int fact = 1;

    if(a==0 && b!= NULL)
    {
        *b =1;
        todoOk=1;
    }
    else
    {
        if(a>0 && b!= NULL)
        {
            for(int i=1; i<=a; i++)
            {
                fact= fact *i;
                *b = fact;
                todoOk=1;
            }
        }
    }
    return todoOk;
}
