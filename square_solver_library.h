#ifndef SQUARE_SOLVER_LIBRARY_H_
#define SQUARE_SOLVER_LIBRARY_H_

/// функция ввода аргументов
void Input_Coeff(double *a, double *b, double *c);

/// функция запоминает значеие корней уравнения и передает целочисленное
/// значение элементу структуры int Roots
void Main_Solver(double a, double b, double c, struct Roots * solution); // name of struct???

/// функция решает линейное уравнение
void Linear_Solver(double a, double b, double c, struct Roots * solution); // name of struct???

/// функция решает квадратное уравнение
void Square_Solver(double a, double b, double c, struct Roots * solution); // name of struct???

/// функция выводит значения корней уравнения
void Print_Roots(const struct Roots * solution); // name of struct???

struct Roots {
    double x1, x2; /// объявление корней в структуре
    int Num_Of_Roots; /// переменная, равная кол-ву корней
};

enum Roots_Count {
    Inf_Roots  = -1,
    Zero_Roots =  0, 
    One_Root   =  1, 
    Two_Roots  =  2, 
}; 

#endif