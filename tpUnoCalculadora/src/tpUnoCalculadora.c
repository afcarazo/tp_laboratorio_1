/*
 ============================================================================
 Name        : tpUnoCalculadora.c
 Author      : Agustina Florencia Carazo
 division    : 1°A
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
    int flagNumeroUno=0;
    int flagNumeroDos=0;
    int flagCalculado=0;
    int okDivision;
    int okFactorialUno;
    int okFactorialDos;
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
            if (flagNumeroUno==1)
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

        case 3: //obtencion de operaciones de las funciones matematicas
            if (flagNumeroUno==1 && flagNumeroDos==1)
            {
                resultadoSuma = sumar(numeroUno, numeroDos);
                resultadoResta = resta(numeroUno, numeroDos);
                okDivision=dividir(numeroUno, numeroDos,&resultadoDivision);
                resultadoMultiplicacion = multiplicacion(numeroUno, numeroDos);
                okFactorialUno = factorial (numeroUno,&resultadoFactorialNumeroUno);
                okFactorialDos = factorial (numeroDos,&resultadoFactorialNumeroDos);
                activarFlag(&flagCalculado);
                printf("\nCalculando...\n\n");
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

        case 4: // evalucion de posibles errores y presentacion de resultados

            if(flagCalculado==0)
            {
                printf("\nPrimero deberias calcular las operaciones \n\n");
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
                    printf("\nEl resultado de %.2f*%.2f es: %.2f\n", numeroUno,numeroDos, resultadoMultiplicacion);
                    if (okFactorialUno && okFactorialDos )
                    {
                        printf(	"\nEl factorial de %.0f es: %d y El factorial de %0.f es: %d\n\n", numeroUno,resultadoFactorialNumeroUno,numeroDos,resultadoFactorialNumeroDos);
                    }
                    else
                    {
                        if(okFactorialUno==0  && okFactorialDos!=0)
                        {
                            printf("\nEl factorial del numero uno no esta definido ya que es negativo\n");
                            printf("\nEl factorial de %.0f es: %d\n\n", numeroDos,resultadoFactorialNumeroDos);
                        }
                        else
                        {
                            if(okFactorialUno!=0 && okFactorialDos==0)
                            {
                                printf("\nEl factorial de %.0f es: %d", numeroUno, resultadoFactorialNumeroUno);
                                printf("\n\nEl factorial del numero dos no esta definido ya que es negativo\n\n");
                            }
                            else
                            {
                                printf("\nEl factorial de numeros negativos no esta definido\n\n");
                            }
                        }
                    }
                    resetFlag(&flagNumeroUno, &flagNumeroDos, &flagCalculado);
                }
            }
            system("pause");
            break;

        case 5: //salir

            printf("\nEsta seguro de que desea salir? s/n ");
            fflush(stdin);
            salir= getchar();
            if(salir=='s')
            {
                printf("\nUsted ha salido del programa. Muchas gracias por usar la calculadora!!\n\n");
                system("pause");
            }

            break;

        default: // Error
            printf("\nLa opcion ingresada no existe. Reingrese la opcion.\n\n");
            system("pause");
            break;
        }
        system("cls");
    }

    while (salir != 's');

    return 0;
}

