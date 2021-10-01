#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(){

    //defined in employeeOne.c
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phonenumberToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;

    //Phone number found example
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-111-1111");

    if(matchPtr != NULL){
        printf("Employee with phone number 909-111-1111 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee with phone number 909-111-1111 NOT found in record ):");
    }

    //Phone number NOT found example
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "222-222-2222");
    
    if(matchPtr != NULL){
        printf("Employee with phone number 222-222-2222 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee with phone number 222-222-2222 NOT found in record ):");
    }


}