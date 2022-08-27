#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "square_solver_library.h"
#include "supporting_library.h"

void Input_Coeff(double *a, double *b, double *c) 
{
    assert(a != NULL); /// проверка
    assert(b != NULL); /// указателей на
    assert(c != NULL); /// неравенство NULL

    puts("Решим уравнение вида ax^2 + bx + c = 0"); // -> ax^2
    puts("Введите значения коэффициентов a, b и c соответственно.");

    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    { 
        printf("Введены некорректные значения коэффициентов, попробуйте ещё раз\n");
        Skip_Line();
    }
    printf("Уравнение имеет вид: %lgx^2 + %lgx + %lg = 0\n", *a, *b, *c);
}

void Main_Solver (double a, double b, double c, struct Roots * solution) 
{
    assert(isfinite(a)); /// если переменные
    assert(isfinite(b)); /// не являются числами,
    assert(isfinite(c)); /// то прога завершается
    assert(solution != NULL);

    if (Is_Zero(a) || Is_Zero(c))
    {
        Linear_Solver (a, b, c, solution); /// вызов функции, решающей линейное уравнение
    }
    else
    {
        Square_Solver (a, b, c, solution); /// вызов функции, решающей квадратное уравнение
    }
}

void Linear_Solver (double a, double b, double c, struct Roots * solution)
{
    assert(solution != NULL);
    assert(Is_Zero(a) || Is_Zero(c));

    if (Is_Zero(a) && Is_Zero(c))
    {
        if (Is_Zero(b))
        {
            solution->Num_Of_Roots = Inf_Roots;
        }
        else
        {
            solution->x1 = 0;
            solution->Num_Of_Roots = One_Root;
        }
    }
    else if (Is_Zero(c) && (! Is_Zero(a)))
    {
        if (Is_Zero(b))
        {
            solution->x1 = 0;
            solution->Num_Of_Roots = One_Root;
        }
        else
        {
            solution->x1 = 0 < -b / a ? 0 : -b / a;
            solution->x2 = 0 > -b / a ? 0 : -b / a;
            solution->Num_Of_Roots = Two_Roots;
        }
    }
    else
    {
        if (Is_Zero(b))
        {
            solution->Num_Of_Roots = Zero_Roots;
        }
        else
        {
            solution->x1 = -c / b;
            solution->Num_Of_Roots = One_Root;
        }
    }
}

void Square_Solver (double a, double b, double c, struct Roots * solution) // solution
{ 
    assert(solution != NULL);

    if (Is_Zero(b))
    {
        if (a * c > 0)
        {
            solution->Num_Of_Roots = Zero_Roots;
        }
        else
        {
            double sqrt_c_a = sqrt(-c / a);
            solution->x1 = -sqrt_c_a;
            solution->x2 = sqrt_c_a;
            solution->Num_Of_Roots = Two_Roots;
        }
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            solution->Num_Of_Roots = Zero_Roots;
        }
        else if (D == 0)
        {
            solution->x1 = -b / a;
            solution->Num_Of_Roots = One_Root;
        }
        else
        {
            double sqrt_D = sqrt(D);
            solution->x1 = (-b - sqrt_D) / (2 * a);
            solution->x2 = (-b + sqrt_D) / (2 * a);
            solution->Num_Of_Roots = Two_Roots;
        }
    }
}

void Print_Roots (const struct Roots * solution) 
{
    assert(solution != NULL);
    switch (solution->Num_Of_Roots) 
    {
        case Inf_Roots:
            printf("Уравнение имеет бесконечное множество корней\n");
            break;

        case Zero_Roots:
            printf("Уравнение не имеет решений\n");
            break;

        case One_Root:
            printf("Уравнение имеет единственный корень: %lg\n", solution->x1);
            break;

        case Two_Roots:
            printf("Уравнение имеет два корня: %lg и %lg\n", solution->x1, solution->x2);
            break;

        default:
            fprintf(stderr, "Ошибка, переменная Num_Of_Roots из структуры "
                            "Equation_Value получила неправильное значение %d"
                            "в функции %s в файле %s\n", solution->Num_Of_Roots, __PRETTY_FUNCTION__, __FILE__);
  }
  puts("\n");
}
