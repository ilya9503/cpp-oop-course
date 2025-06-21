/*
    Введение в шаблоны функций.
    Обобщенное программирование на C++ или просто шаблоны (templates)
    Шаблон нужен для того, чтобы избежать дублирования текста и отладки программы при множественных перегрузках

*/

#include <iostream>

template <typename T>

T sq_rect(T a, T b) // шаблон функции (абстракция на уровне текста программы)
{
    return a * b;
}

template <typename T> void swap(T* x, T* y);

/* int sq_rect(int a, int b)
{
    return a * b;
}

double sq_rect(double a, double b)
{
    return a * b;
} */



int main()
{
    // инстанцирование шаблона функции
    int res_1 = sq_rect(1, 2);
    double res_2 = sq_rect(3.5, 8.9);
    short res_3 = sq_rect<short>(5, 4); // явное указание желаемого типа параметров
    double res_4 = sq_rect(4.2f, 3.2f);

    int x{5}, y{7};
//    int res_5 = *sq_rect(&x, &y);

    double a{7.8}, b{-5.6};
    swap(&a, &b);

    return 0;
}

template <typename T> void swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}