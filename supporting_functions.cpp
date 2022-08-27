#include <stdio.h>
#include <math.h>

#include "supporting_library.h"

int Is_Eq_Double (double first, double second)
{
    return (fabs(first - second) < Eps);
}

int Is_Zero (double number)
{
    return Is_Eq_Double(number, 0);
}

void Skip_Line()
{
    while (getchar() != '\n');
}