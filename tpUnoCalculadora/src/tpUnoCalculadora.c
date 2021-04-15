/*
 ============================================================================
 Name        : trabajoPracticoCalculadora.c
 Author      : Agustina Carazo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "biblioteca.h"

int main()
{
    //Declaracion de variables

    setbuf(stdout, NULL);
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorialNumeroUno;
    int resultadoFactorialNumeroDos;
    float numeroUno;
    float numeroDos;
    float flagNumeroUno = 0;
    float flagNumeroDos = 0;
    float flagCalculado = 0;
    int okDivision;
    char salir ='n';

    do
    {
        switch (menu(numeroUno, numeroDos, flagNumeroUno, flagNumeroDos)) //Menu de opciones
        {
        case 1: //obtencion del primer operando
            printf("\nIngrese el primer operando: ");
            scanf("%f", &numeroUno);
            activarFlag(&flagNumeroUno);
            break;
        case 2: //obtencion del segundo operando
            if (flagNumeroUno != 0)
            {
                printf("\nIngrese el segundo operando: ");
                scanf("%f", &numeroDos);
                activarFlag(&flagNumeroDos);
            }
            else
            {
                printf("\nPrimero deberias ingresar el primer operando\n\n");
                system("pause");
            }
            break;

        case 3: //obtencion de las operaciones de las funciones matematicas
            if (flagNumeroUno==1 && flagNumeroDos==1)
            {
                activarFlag(&flagCalculado);
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = resta(numeroUno, numeroDos);
                okDivision=dividirRobusta(numeroUno, numeroDos,&resultadoDivision);
                resultadoMultiplicacion = multiplicacion(numeroUno, numeroDos);
                factorial(numeroUno, numeroDos, &resultadoFactorialNumeroUno,&resultadoFactorialNumeroDos);
                printf("\n\nCalculando...\n\n");
            }
            else
            {
                if(flagNumeroUno==1 && flagNumeroDos==0)
                {
                    printf("\nPrimero deberias ingresar el valor del segundo operando\n\n");
                }
                else
                {
                    printf("\nPrimero deberias ingresar los valores de los dos operandos para realizar las ecuaciones\n\n");
                }

            }
            system("pause");
            break;

        case 4: // se muestran resultados

            if(flagCalculado==0)
            {
                printf("\n Primero deberias calcular las operaciones \n\n");
            }
            else
            {
                if (flagNumeroUno && flagNumeroDos)
                {
                    printf("\nEl resultado de %.2f + %.2f es: %.2f\n", numeroUno,numeroDos, resultadoSuma);
                    printf("\nEl resultado de %.2f-%.2f es: %.2f\n", numeroUno,numeroDos, resultadoResta);
                    if (okDivision == 1)
                    {
                        printf("\nEl resultado de %.2f/%.2f es: %.2f \n", numeroUno,numeroDos, resultadoDivision);
                    }
                    else
                    {
                        printf("\nNo es posible dividir por cero\n");
                    }

                    if (numeroUno >= 0 && numeroDos >= 0)
                    {
                        printf(	"\nEl factorial de %.0f es: %d y El factorial de %0.f es: %d\n", numeroUno,resultadoFactorialNumeroUno,numeroDos,resultadoFactorialNumeroDos);
                    }
                    else
                    {
                        if(numeroUno<0 && numeroDos>=0)
                        {
                            printf("\nEl factorial del numero uno no esta definido ya que es negativo\n");
                            printf("\nEl factorial de %.2f es: %d\n", numeroDos,resultadoFactorialNumeroDos);
                        }
                        else
                        {
                            if(numeroDos<0 && numeroUno>=0)
                            {
                                printf("\nEl factorial de %.2f es: %d", numeroUno, resultadoFactorialNumeroUno);
                                printf("\n\nEl factorial del numero dos no esta definido ya que es negativo\n");
                            }
                            else
                            {
                                printf("\nEl factorial de numeros negativos no esta definido \n");
                            }
                        }
                    }

                    printf("\nEl resultado de %.2f*%.2f es: %.2f\n\n", numeroUno,numeroDos, resultadoMultiplicacion);
                    resetFlag(&flagNumeroUno, &flagNumeroDos, &flagCalculado);
                }
                else
                {
                    if(flagNumeroUno==1 && flagNumeroDos==0)
                    {
                        printf("\nPrimero deberias ingresar el valor del segundo operando\n\n");
                    }
                    else
                    {
                        printf("\nPrimero deberias ingresar los valores de los dos operandos para poder mostrar resultados\n\n");
                    }
                }
            }

            system("pause");
            break;

        case 5: //salir

        	 printf("\nEsta seguro de que desea salir? n/s ");
             fflush(stdin);
             salir= getchar();
        	 if(salir=='s'){
        		 printf("\n\nUsted ha salido del programa. Muchas gracias por usar la calculadora!!\n\n");
        	 }

            break;

        default: // Error
            printf("\n\nLa opcion ingresada no existe. Reingrese la opcion\n\n");
            system("pause");
            break;
        }
        system("cls");
    }

    while (salir != 's');

    return 0;
}

