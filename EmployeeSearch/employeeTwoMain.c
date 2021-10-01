//Compile script: gcc employeeTwo.c employeeTable.c employeeTwoMain.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(){

    //defined in employeeTwo.c
    PtrToEmployee searchEmployeeTablebyPhoneNumber(Employee table[], int sizeTable, char * phoneNumber);
    PtrToEmployee searchEmployeebySalary(Employee table[], int sizeTable, double salary);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchptr;

    //compare

    //Phone number found
    matchptr = searchEmployeeTablebyPhoneNumber(EmployeeTable, EmployeeTableEntries, "111-111-1111");

    if(matchptr != NULL){
        printf("Employee with phone number 111-111-1111 found at record %d\n", matchptr - EmployeeTable);
    } else {
        printf("Employee with phone number 111-111-1111 not found\n");
    }

    //Phone number not found
    matchptr = searchEmployeeTablebyPhoneNumber(EmployeeTable, EmployeeTableEntries, "000-000-0000");
    if(matchptr != NULL){
        printf("Employee with phone number 000-000-0000 found at record %d\n", matchptr - EmployeeTable);
    }else{
        printf("Employee with phone number 000-000-0000 not found\n");
    }

    return EXIT_SUCCESS;
}

