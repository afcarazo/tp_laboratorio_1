/*
 * biblioteca.h
 *
 *  Created on: Apr 7, 2021
 *      Author: Agust
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/** \brief evalua el ingreso de operandos y que se hayan realizado los calculos asignando un 1
 *
 * \param c float* puntero a la bandera corrrespondiente
 * \return void
 *
 */
void activarFlag(int *c);


/** \brief reinicia el valor a 0 de las tres banderas cuando se hayan mostrado los resultados del ingreso
 *
 * \param b float* puntero del ingreso del numero uno
 * \param x float* puntero del ingreso del numero dos
 * \param f float* puntero ejecucion de operacion
 * \return void
 *
 */
void resetFlag(int *b, int *x, int* f);



/** \brief realiza la suma de dos numeros flotantes
 *
 * \param a float primer operando a sumar
 * \param b float segundo operando a sumar
 * \return float retorna resultado de la suma de los dos operandos
 *
 */
float sumar(float a, float b);



/** \brief realliza la resta de dos numeros flotantes
 *
 * \param a float primer operando a restar
 * \param b float segundo operando a restar
 * \return float retorna resta de los operandos
 *
 */
float resta(float a, float b);


/** \brief multiplicacion de dos numeros flotantes
 *
 * \param a float multiplicando
 * \param b float multiplicador
 * \return float retorna producto de factores
 *
 */
float multiplicacion(float a, float b);


/** \brief realiza la division de dos numeros flotantes
 *
 * \param a float dividendo de la operacion
 * \param b float divisor de la operacion
 * \return int devuelve 1 si pudo hacer de lo contario 0
 *
 */
int dividir(float a, float b, float* c);


/** \brief calcula el factorial de un numero entero no mayor a 16, incluye factorial de 0
 *
 * \param a int numero a factorizar
 * \param b int* puntero al resultado
 * \return int devuelve 1 si pudo realizar la operacion de lo contario 0
 *
 */
int factorial(int a, int *b);


/** \brief muestra el menu de opciones
 *
 * \param a float muestra valor del primer operando
 * \param b float muestra valor del segundo operando
 * \param flagNumeroUno float evalua si se trata del primer ingreso del primer operando
 * \param flagNumeroDos float evalua si se trata del primer ingreso del segundo operando
 * \return int  devuelve la opcion seleccionada
 *
 */
int menu(float a, float b, float flagNumeroUno, float flagNumeroDos);

#endif /* BIBLIOTECA_H_ */
