/*
 ============================================================================
 Name        : trabajoPracticoDos.c
 Author      : Agustina Carazo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define ELEMENTS 1000
#define NAME_LEN 51
#define LASTNAME_LEN 51


int main(void) {
    char salir='n';
    Employee arrayEmployees[ELEMENTS];
    int id=1;
    char name[NAME_LEN];
    char lastName[LASTNAME_LEN];
    float salary=0;
    int sector=0;
    int flagAlta=0;
    initEmployees(arrayEmployees,ELEMENTS);

    do
       {
           system("cls");
           printf("\n\n------------------------------"  );
           printf(" \n          BIENVENIDO"             );
           printf("\n------------------------------\n\n");
           int opcion;

           if(!utn_getNumero(&opcion," 1.ALTAS\n 2.MODIFICAR\n 3.BAJA\n 4.INFORMES\n 5.SALIR\n\n Ingrese la opcion deseada: ","\nERROR, opcion invalida.\n\n",1,5,2))
           {
           }

           switch(opcion)
           {

           case 1:
               if(employeeValidation(arrayEmployees,ELEMENTS,id,name,lastName,salary,sector)==0)
               {
                   printf("\nEL alta del empleado ha sido exitosa.\n\n");
                   flagAlta=1;
                   id++;
               }
               else
               {
                   printf("\nOcurrio un problema al realizar el alta.\n\n");
               }

               break;

           case 2:
               if(flagAlta==1)
               {
                   if(!modifyEmployee(arrayEmployees,ELEMENTS))
                   {
                       printf("\nModificacion exitosa!\n\n");
                   }
                   else
                   {
                       printf("\n\nOcurrio un problema al realizar la modificacion.\n\n");
                   }
               }
               else
               {
                   printf("\nPrimero deberias realizar el alta de algun empleado\n\n");
               }
               break;

           case 3:
               if(flagAlta==1)
               {
                   if(!bajaEmpleado(arrayEmployees,ELEMENTS)&&flagAlta!=0)
                   {
                       printf("\nBaja exitosa!\n\n");
                   }
                   else
                   {
                       printf("\n\nOcurrio un problema al realizar la baja.\n\n");
                   }
               }
               else
               {
                   printf("\nPrimero deberias realizar el alta de algun empleado\n\n");
               }
               break;
           case 4:
               if(flagAlta==1)
               {
                   printf("Informar\n");
                   reportsMenu(arrayEmployees,ELEMENTS);
               }
               else
               {
                   printf("\nPrimero deberias realizar el alta de algun empleado\n\n");
               }

               break;

           case 5:
               printf("\nEsta seguro de que desea salir? s/n: ");
               fflush(stdin);
               scanf("%c",&salir);
               break;

           default:
               printf("La opcion ingresada no es valida.\n\n ");
               break;

           }
           system("pause");

       }
       while(salir=='n');

	return EXIT_SUCCESS;
}



