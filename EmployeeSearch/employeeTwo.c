#include <string.h>
#include <stdio.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetptr, int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endptr = ptr + tableSize;
    for(; ptr < endptr; ptr++){
        if((*functionPtr) (targetptr, ptr) == 0){
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

//functions that *functionPtr can point to
//returns 0 if true
static int compareEmployeePhoneNumer(const void *targetptr, PtrToConstEmployee tableValueptr){
    return strcmp((char *) targetptr, tableValueptr->phone);
}

static int compareEmployeeSalary(const void *targetptr, PtrToConstEmployee tableValueptr){
    return * (double *) targetptr != tableValueptr->salary;
}
static int compareEmployeeIDNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long *) targetPtr != tableValuePtr->idNumber;

}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValueptr){
    return strcmp((char *) targetPtr, tableValueptr->name);
}

//Wrappers
PtrToEmployee searchEmployeeTablebyIDNumber(PtrToConstEmployee ptr, int size, long number){
    return searchEmployeeTable(ptr, size, &number, compareEmployeeIDNumber);

}

PtrToEmployee searchEmployeeTablebyName(PtrToConstEmployee ptr, int size, char * name){
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeTablebyPhoneNumber(PtrToConstEmployee ptr, int size, char * phoneNumber){
    return searchEmployeeTable(ptr, size, phoneNumber, compareEmployeePhoneNumer);
}

PtrToEmployee searchEmployeebySalary(PtrToConstEmployee ptr, int size, double salary){
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}