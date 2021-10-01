#include <string.h>
#include <stdlib.h>
#include "employee.h"

Employee EmployeeTable[] = {
    {1000, "All Might", "909-111-1111", 10.30}, 
    {1323, "Eraser Head", "909-456-7890", 8.30}, 
    {1423, "Present Mic", "909-888-7777", 8.23},
    {2091, "Cementos", "626-222-3333", 7.65}, 
    {5005, "Grand Torino", "111-111-1111", 6.75} 
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);
