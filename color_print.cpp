#include <stdio.h>

#include "color_print.h"

void Coloured_Print(const char * str, const char * color) 
{
    printf("%s", color);
    printf("%s", str);
    printf("%s", RESET);
}