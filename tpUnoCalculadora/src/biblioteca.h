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
 * \param c float* puntero de bandera se asigna valor 1 en el primer ingreso
 * \return void
 *
 */
void activarFlag(float *c);

/** \brief reinicia el valor de las banderas cuando se hayan mostrado los resultados del ingreso
 *
 * \param b float* puntero de bandera se le asigna un 0 a la bandera que corresponde al primer numero
 * \param x float* puntero de bandera se le asigna un 0 a la bandera que corresponde al segundo numero
 * \param f float* puntero de bandera se le asigna un 0 a la bandera cuando se realizaron las operaciones
 * \return void
 *
 */
void resetFlag(float *b, float *x, float* f);

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

/** \brief realiza la division de dos eneteros
 *
 * \param a int dividendo de la operacion
 * \param b int divisor de la operacion
 * \return int devuelve 1 si pudo hacer la division o 0 sino lo pudo hacer
 *
 */
int dividirRobusta(int a, int b, float* c);

/** \brief realiza el factorial de ambos numeros
 *
 * \param operadorUno int primer operando al cual se calcula el factorial
 * \param operadorDos int segundo operando al cual se calcula el factorial
 * \param factorialUno int* puntero del resultado del primer operando
 * \param factorialDos int* puntero del resultado del segundo operando
 * \return void
 *
 */
void factorial(int operadorUno, int operadorDos, int *factorialUno, int *factorialDos);

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
