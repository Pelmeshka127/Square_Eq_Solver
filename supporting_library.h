#ifndef SUPPORTING_LIBRARY_H_
#define SUPPORTING_LIBRARY_H_

const double Eps = 1e-5;

/// функция сравнивает два числа типа double
int Is_Eq_Double(double first, double second);

/// функция выясняет является число достаточно малым, чтобы считать его 0
int Is_Zero(double number);

/// функция очищает буффер ввода
void Skip_Line();

#endif