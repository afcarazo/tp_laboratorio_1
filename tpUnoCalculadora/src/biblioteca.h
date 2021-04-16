/*
 * biblioteca.h
 *
 *  Created on: Apr 7, 2021
 *      Author: Agust
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/** \brief evalua el primer ingreso de operandos
 *
 * \param c float* puntero se asigna valor 1 en el primer ingreso
 * \return void
 *
 */
void activarFlag(int *c);

/** \brief reinicia el valor de las banderas cuando se hayan mostrado los resultados del ingreso
 *
 * \param b float* puntero se le asigna un 0 a la bandera que corresponde al primer numero
 * \param x float* puntero se le asigna un 0 a la bandera que corresponde al segundo numero
 * \param f float* puntero se le asigna un 0 a la bandera cuando se realizaron las operaciones
 * \return void
 *
 */
void resetFlag(int *b, int *x, int* f);

/** \brief realiza la suma de dos numeros
 *
 * \param a float primer operando a sumar
 * \param b float segundo operando a sumar
 * \return float retorna resultado de la suma de los dos operandos
 *
 */
float sumar(float a, float b);

/** \brief realliza la resta de dos numeros
 *
 * \param a float primer operando a restar
 * \param b float segundo operando a restar
 * \return float retorna resta de los operandos
 *
 */
float resta(float a, float b);

/** \brief multiplicacion de dos numeros
 *
 * \param a float primer operando a multiplicar
 * \param b float segundo operando a multiplicar
 * \return float retorna multiplicacion de los operandos
 *
 */
float multiplicacion(float a, float b);

/** \brief realiza la division de dos enteros
 *
 * \param a float dividendo de la operacion
 * \param b float divisor de la operacion
 * \return int devuelve 1 si pudo hacer la division o 0 sino lo pudo hacer
 *
 */
int dividir(float a, float b, float* c);


/** \brief calcula el factorial de un numero
 *
 * \param a int numero a factorizar
 * \param b int* puntero al resultado
 * \return int devuelve 1 si pudo realizar la operacion 0 sino lo pudo realizar
 *
 */
int factorial(int a, int *b);

/** \brief muestra el menu de opciones
 *
 * \param a float muestra valor del primer operando
 * \param b float muestra valor del segundo operando
 * \param flagNumeroUno float evalua si se trata del primer ingreso del primer operando
 * \param flagNumeroDos float evalua si se trata del primer ingreso del segundo
 * \return int  devuelve la opcion seleccionada
 *
 */
int menu(float a, float b, float flagNumeroUno, float flagNumeroDos);

#endif /* BIBLIOTECA_H_ */
