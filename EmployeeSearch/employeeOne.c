#include <string.h>
#include "employee.h"
#include <stdio.h>

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char * targetPhoneNumber){
    const PtrToConstEmployee endptr = ptr + tableSize;
    for(; ptr < endptr; ptr++){
        if (strcmp(ptr->phone, targetPhoneNumber) == 0){
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){

    const PtrToConstEmployee endptr = ptr + tableSize;

    for(; ptr < endptr; ptr++){
        if(ptr->salary == targetSalary){
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

PtrToEmployee searchEmployeeByIDNumber (PtrToConstEmployee ptr, int tableSize, long targetID){
    const PtrToConstEmployee endptr = ptr + tableSize;
    for (; ptr< endptr; ptr++){
        if(ptr->idNumber == targetID){
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if(strcmp(ptr->name, targetName) == 0){
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

