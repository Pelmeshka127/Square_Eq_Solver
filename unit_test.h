#ifndef UNIT_TEST_H_
#define UNIT_TEST_H_

/// находит кол-во ошибок в тестировании
void Unit_Test_Square_Solver();

/// проверяет один тест на выполняемость
int Test_Square_Solver(const struct Test_Roots * tests);

/// функция выводит ожидаемое и реальное выполнения функции Main_Solver в Unit тесте
void Print_Failed_Expected(struct Roots * solution, const struct Test_Roots * tests);

/// функция выводит результаты одного теста
void Successed_Test_Result(const struct Test_Roots * tests);

struct Test_Roots {
    double test_A, test_B, test_C;
    double test_X1, test_X2;
    int test_Num_Of_Roots;
};

#endif
