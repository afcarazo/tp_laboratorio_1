/*
 * ArrayEmployees.h
 *
 *  Created on: May 13, 2021
 *      Author: Agustina Carazo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

 struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;


#endif /* ARRAYEMPLOYEES_H_ */


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int id of employee
 * \param name[] char name of employee
 * \param lastName[] char last name of employee
 * \param salary float salary of employee
 * \param sector int number of the sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee *list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief finds an empty space and returns the index
 *
 * \param list Employee* Pointer to array of employees
 * \param len int  Array length
 * \return int index (-1) if Error [Invalid length or NULL pointer or without free space] - index position in array. if Ok
 *
 */
int getEmpty(Employee* list, int len);


/** \brief validate the values received as parameters
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int id to evaluate
 * \param name[] char name to evaluate
 * \param lastName[] char last name to evaluate
 * \param salary float salary to evaluate from $ 10000
 * \param sector int sector to evaluate from 101-110
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int employeeValidation(Employee *list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int ID to search
 * \return Return employee index if ok or (-1) if error [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief show one employee
 *
 * \param anEmployee Employee employee to be displayed
 * \return void
 *
 */
void showEmployee(Employee anEmployee);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int ID of the employee to be removed
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Allow modifying an employee
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int length);


/** \brief show modification menu
 *
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \param index int index of the employee to modify
 * \return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int subMenuModify(Employee* list, int length,int index);

/** \brief calculate the total and average salary
 *
 * \param list Employee* list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int totalSalary(Employee* list, int len);

/** \brief show report menu
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int reportsMenu(Employee* list, int len);


/** \brief validate that it is an existing employee before deleting
 *
 * \param list Employee*Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int bajaEmpleado(Employee* list, int len);


