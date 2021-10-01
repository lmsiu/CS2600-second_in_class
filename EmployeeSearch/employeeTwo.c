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
//returns 0 if false

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