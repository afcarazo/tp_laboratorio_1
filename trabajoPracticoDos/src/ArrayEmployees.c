/*
 * ArrayEmployees.c
 *
 *  Created on: May 13, 2021
 *      Author: Agustina Carazo
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define NAME_LEN 51
#define LASTNAME_LEN 51



int initEmployees(Employee* list, int len)
{
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


int getEmpty(Employee* list, int len)
{
    int index=-1;
    if(list!= NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                index=i;
                break;
            }

        }
    }
    return index;
}



int addEmployee(Employee *list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    int index;
    if(list != NULL && len>0 && name!=NULL && lastName!=NULL&& salary>0)
    {
        index= getEmpty(list,len); //posicion vacia donde se cargaran los datos
        if(index!=-1)
        {
            list[index].id= id;
            strcpy(list[index].name,name);
            strcpy(list[index].lastName,lastName);
            list[index].salary=salary;
            list[index].sector=sector;
            list[index].isEmpty=0;
            retorno=0;
        }
    }

    return retorno;
}
int employeeValidation(Employee *list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    system("cls");
    printf("\n\n----------------------\n");
    printf("     Alta empleado"          );
    printf("\n----------------------\n\n");
    printf("ID: %d\n", id);
         if(!utn_getNombre(name,NAME_LEN,"\nIngrese nombre: ","\nERROR\n",2)&&
            !utn_getNombre(lastName,LASTNAME_LEN,"\nIngrese apellido: ","\nERROR\n",2)&&
            !utn_getNumeroFlotante(&salary,"\nIngrese salario: ","\nERROR\n",10000,500000,2)&&
            !utn_getNumero(&sector,"\nIngrese sector: ","\nERROR\n",101,110,2))//se realizan las validaciones de los parametros para luego agregarlos al array
    {
        if(addEmployee(list,len,id,name,lastName,salary,sector)==0)//se agregan los parametros validados al array
        {
            retorno=0;
        }

    }

    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                index=i;
                break;
            }

        }
    }

    return index;
}


void showEmployee(Employee anEmployee)
{
    printf("%2d %10s %10s     %9.2f     %d", anEmployee.id, anEmployee.name,anEmployee.lastName,anEmployee.salary,anEmployee.sector);
}


int printEmployees(Employee* list, int length)
{
    int flag=1;
    int retorno=-1;
    printf("\n-----------------------------------------------\n");
    printf("                  EMPLEADOS                  \n\n");
    printf("ID     NOMBRE     APELLIDO     SALARIO   SECTOR ");
    printf("\n-----------------------------------------------\n\n");
    if(list!=NULL && length>0)
    {
        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                showEmployee(list[i]); // muestra empleado activo
                printf("\n");
                flag=0;
            }
        }

        retorno=0;
        if(flag)   //no se encontro ningun empleado activo
        {
            printf("      No hay empleados que mostrar\n");
            retorno=-1;
        }
        printf("\n\n");
    }
    return retorno;

}


int modifyEmployee(Employee* list, int length)
{
    int retorno =-1;
    int id;
    int index;
    system("cls");
    printf("\nModificar empleado: \n");
    if(list!=NULL && length>0)
    {
        if(printEmployees(list,length)==0)
        {
            utn_getNumero(&id,"\nIngrese ID del empleado: ","\nERROR\n",0,1000,2);//pide id del empleado a modificar
            index=findEmployeeById(list,length,id);
            while(index==-1) //si el id no es correcto se lo vuelve a pedir hasta que sea valido
            {
                printf("\n El ID ingresado no es valido. \n");
                utn_getNumero(&id,"\nIngrese ID del empleado: ","\nERROR\n",0,1000,2);
                index=findEmployeeById(list,length,id);
            }
            if(subMenuModify(list,length,index)!=-1)//menu de modificaciones
            {
                retorno=0;
            }

        }
    }
    return retorno;
}


int subMenuModify(Employee* list, int length,int index)
{
    int opcion;
    int todoOk=-1;
    Employee auxEmpleado;
    if(list!=NULL&&length>0)
    {
        printf("\nQue desea modificar?\n\n");
        printf("1.Nombre\n");
        printf("2.Apellido\n");
        printf("3.Salario\n");
        printf("4.Sector\n");

        printf("\nIngrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion) //menu de modificaciones si los parametros son validos se modifican en el array original
        {
        case 1:

            if(!utn_getNombre(auxEmpleado.name,NAME_LEN,"\nIngrese nombre: ","\nERROR\n",3))
            {
                strncpy(list[index].name,auxEmpleado.name,NAME_LEN);
                todoOk=0;
            }

            break;
        case 2:

            if(!utn_getNombre(auxEmpleado.lastName,LASTNAME_LEN,"\nIngrese apellido: ","\nERROR\n",3))
            {
                strncpy(list[index].lastName,auxEmpleado.lastName,LASTNAME_LEN);
                todoOk=0;
            }


            break;
        case 3:

            if(!utn_getNumeroFlotante(&auxEmpleado.salary,"\nIngrese salario: \n","\nERROR\n",10000,500000,3))
            {
                list[index].salary=auxEmpleado.salary;
                todoOk=0;
            }

            break;
        case 4:

            if(!utn_getNumero(&auxEmpleado.sector,"\nIngrese sector: ","\nERROR\n",101,110,3))
            {
                list[index].sector=auxEmpleado.sector;
                todoOk=0;
            }

            break;
        default:
            printf("La opcion ingresada no es valida. \n");
            break;
        }

    }
    return todoOk;
}


int removeEmployee(Employee* list, int len, int id)
{
    int retorno =-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)//si el id coincide y ademas es un empleado activo se procede a dar de baja
            {
                list[i].isEmpty=1;
                break;
            }
        }
        retorno=0;
    }

    return retorno;
}

int bajaEmpleado(Employee* list, int len)
{
    int retorno=-1;
    int id;
    int indexEmployee;
    if(list!=NULL &&len>0)
    {
        system("cls");
        printf("\nBaja empleado:");
        if( printEmployees(list,len)==0){ //muestra empleados activos
        utn_getNumero(&id,"\nIngrese ID del empleado a dar de baja: ","\nERROR\n",0,1000,2);
        indexEmployee=findEmployeeById(list,len,id);
        while(indexEmployee==-1) //si el id no es valido se lo pide hasta que lo sea
        {
            utn_getNumero(&id,"\nNO hay un empleado con ese ID. Reingrese ID del empleado a dar de baja: ","\nERROR\n",0,1000,2);
            indexEmployee=findEmployeeById(list,len,id);
        }
        if(removeEmployee(list,len,id)==0)
             {
                 retorno=0;
             }
       }
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxList;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if( (order==1 && (list[i].sector>list[j].sector))|| (list[i].sector==list[j].sector && (strcmp(list[i].lastName,list[j].lastName)>0)))//ordenamiento creciente
                {
                    auxList= list[i];
                    list[i]=list[j];
                    list[j]= auxList;
                }
                else
                {
                    if((order==0 && ( list[i].sector<list[j].sector)) || (list[i].sector==list[j].sector && (strcmp(list[i].lastName,list[j].lastName)<0)))//ordenamiento decreciente
                    {
                        auxList= list[i];
                        list[i]=list[j];
                        list[j]= auxList;
                    }
                }
            }
        }
    }

    return 0;
}


int totalSalary(Employee* list, int len)
{
    int retorno=-1;
    float acumuladorSueldo=0;
    int contadorEmpleados=0;
    float sueldoPromedio=0;
    int contadorSuperanPromedio=0;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)//se acumulan salarios y se cuentan los empleados activos
            {
                acumuladorSueldo+=list[i].salary;
                contadorEmpleados++;
            }
        }
        sueldoPromedio=acumuladorSueldo/contadorEmpleados;
        for(int e=0; e<len; e++)
        {
            if(list[e].isEmpty==0&&list[e].salary>sueldoPromedio)//empleados que superan el promedio calculado
            {
                contadorSuperanPromedio++;
            }
        }
        printf("\nEl TOTAL es: $%.2f \n", acumuladorSueldo);
        printf("\nEl sueldo promedio es: $%.2f \n", sueldoPromedio);
        printf("\nLos empleados que superan el sueldo promedio son: %d \n\n",contadorSuperanPromedio);
        retorno=1;
    }
    return retorno;
}

int reportsMenu(Employee* list, int len)
{
    int opcion;
    int upDown;
    int todoOk=-1;
    if(list!=NULL&& len>0)
    {
        system("cls");
        printf("\n\n-----------------------------------------------------------------------------------");
        printf("\n                               INFORMES");
        printf("\n-----------------------------------------------------------------------------------\n\n");

        printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n\n");
        printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
        if(!utn_getNumero(&opcion,"\nIngrese opcion: ","\nERROR\n", 1,2,2))
        {

        }

        switch(opcion) //menu de reportes
        {
        case 1:
            printf("\nDesea ordenar de manera: \n");
            printf("\n0. Decreciente\n");
            printf("\n1. Creciente \n");
            if(!utn_getNumero(&upDown,"\nIngrese opcion: ","\nERROR la opcion no es valida\n\n", 0,1,2))
            {
                sortEmployees(list,len,upDown); // se ordenan empleado de la forma seleccionada
                printEmployees(list,len); //se muestran los empleados ordenados
            }

            break;
        case 2:
            totalSalary(list,len); //salario total - promedio -empleados que superan promedio
            break;
        default:
            printf("\nLa opcion ingresada es invalida\n\n");
            break;
        }
        todoOk=0;
    }
    return todoOk;
}

