#ifndef COLOR_PRINT_H_
#define COLOR_PRINT_H_

// consts
const char RED[]   = "\x1b[31m";
const char GREEN[] = "\x1b[32m";
const char RESET[] = "\x1b[0m";

/// функция делает тескт цветным
void Coloured_Print(const char* str, const char* color); //

#endif