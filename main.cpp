#include <stdio.h>
#include <math.h>

#include "square_solver_library.h"
#include "supporting_library.h"
#include "unit_test.h"

const int Exit = 0;
const int Test = 1;
const int Equation = 2;

int main(void)
{
    puts("Данная программа способна решать квадратные уравнения.");
    Roots solver = { .x1 = NAN, .x2 = NAN, .Num_Of_Roots = Inf_Roots };  
    double a = NAN, b = NAN, c = NAN;

    int interactive = true;
    while (interactive)
    {

        puts("Нажмите 1, если хотите убедиться в работоспособности программы.\n"
        "Нажмите 2, чтобы решить свое собственное уравнение.\n"
        "Введите 0 для выхода из программы\n");

        int mode = 0;
        if (scanf ("%d", &mode) == 1)
        {
            switch (mode)
            {
                case Test:
                    Unit_Test_Square_Solver();
                    break;

                case Equation:
                    Input_Coeff (&a, &b, &c);  /// вызов функций ввода,
                    Main_Solver (a, b, c, &solver); /// вызов функции, решающей уравнение
                    Print_Roots (&solver); /// вызов функции, выводящей корни уравнения
                    break;

                case Exit:
                    interactive = false;
                    break;

                default:
                    Skip_Line();
                    puts("Введено некорректное значение");
            }
        }
        else
        {
            Skip_Line();
            puts("Введено некорректное значение."); 
        }
    }
    puts("Завершение программы\n");
    return 0;
}
