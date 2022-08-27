#include <stdio.h>
#include <math.h>

#include "unit_test.h"
#include "square_solver_library.h"
#include "supporting_library.h"
#include "color_print.h"

int Test_Square_Solver(const struct Test_Roots * tests)
{
    Roots solution = {}; 

    Main_Solver(tests->test_A, tests->test_B, tests->test_C, &solution);

    return tests->test_Num_Of_Roots == solution.Num_Of_Roots 
           && Is_Eq_Double(tests->test_X1, solution.x1) 
           && Is_Eq_Double(tests->test_X2, solution.x2);

}

void Unit_Test_Square_Solver()
{
    Roots solution = {};
    int successed_test = 0, now_test = 0;
    const struct Test_Roots tests[] = {
        {0,   0,     0,    0,         0,      -1}, /// test 1
        {0,   8,    -9,    1.125,     0,       1}, /// test 2   
        {1,   0,    -4,    -2,        2,       2}, /// test 3
        {0,   0,    -12,   0,         0,       0}, /// test 4
        {5,  -6,    0,     0,         1.2,     2}, /// test 5
        {1,   6,    5,     -5,        -1,      2}, /// test 6
        {9.7, -4.3, -6.7 , -0.638496, 1.08179, 2}, /// test 7
        {4,   -5,   1,     0.25,      1,       2}, /// test 8
        {0,    8,   0,     -0,         0,      1}, /// test 9
    };///a     b    c      x1         x2    Num_Of_Roots
    unsigned long num_of_tests = sizeof(tests) / sizeof(tests[0]);

    for (now_test = 0; now_test < num_of_tests; now_test++)
    {
        double t_A    = tests[now_test].test_A;
        double t_B    = tests[now_test].test_B;
        double t_C    = tests[now_test].test_C;
        double t_X1   = tests[now_test].test_X1;
        double t_X2   = tests[now_test].test_X2;
        int t_N_Roots = tests[now_test].test_Num_Of_Roots;

        if (Test_Square_Solver (&tests[now_test]))
        {
            printf("Тест номер %d (%lgx*x + %lgx + %lg = 0)\n", now_test + 1, t_A, t_B, t_C);
            Coloured_Print("успешно пройден\n",  GREEN);
            Successed_Test_Result(&tests[now_test]);
            successed_test += 1;
            puts("\n");
        }
        else 
        {
            printf("Тест номер %d (%lgx^2 + %lgx + %lg = 0)\n", now_test + 1, t_A, t_B, t_C);
            Coloured_Print("не прошёл проверку\n", RED);
            Print_Failed_Expected(&solution, tests);
            puts("\n");
        }
    }

    Coloured_Print("Пройдено тестов ", GREEN);
    printf("%d / %lu\n",  successed_test,                 num_of_tests);

    Coloured_Print("Провалено тестов ", RED);
    printf("%lu / %lu\n", num_of_tests - successed_test, num_of_tests);
    puts("\n");
}

void Print_Failed_Expected(struct Roots * solution, const struct Test_Roots * tests)
{
    printf("FAILED: (%lgx*x + %lgx + %lg = 0)\n"
        "Num_Of_Roots = %d, x1 = %lg, x2 = %lg\n"      /// реальность
        "EXPECTED:\n"
        "Num_Of_Roots = %d, x1 = %lg, x2 = %lg\n",     /// ожидание
        tests->test_A,        tests->test_B,        tests->test_C, 
        solution->Num_Of_Roots,   solution->x1,      solution->x2,
        tests->test_Num_Of_Roots, tests->test_X1, tests->test_X2); 
}

void Successed_Test_Result(const struct Test_Roots * tests)
{
    switch (tests->test_Num_Of_Roots)
    {
        case Zero_Roots:
            printf("Уравнение не имеет корней\n");
            break;

        case Inf_Roots:
            printf("Уравнение иеет бесконечно много корней\n");
            break;
        case One_Root:
            printf("Уравнение имеет корень %lg\n", tests->test_X1);
            break;
        case Two_Roots:
            printf("Уравнение имеет два корня %lg и %lg\n", tests->test_X1, tests->test_X2);
            break;
        default:
            fprintf(stderr, "Ошибка в функции Unit_Test_Square_solution. Переменная\n" 
                            "test_Num_Of_Roots из стурктуры Test_Roots получила\n"
                            "некорректное значение %d\n", tests->test_Num_Of_Roots);
    }
}