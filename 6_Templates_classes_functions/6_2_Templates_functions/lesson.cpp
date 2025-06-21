/*
    Шаблоны функций. Продолжение
*/

#include <iostream>

// Параметр шаблона с начальным значением typename RT = double
template <typename RT = double, typename T1, typename T2>     // C++14 auto
RT sq_rect(T1 a, T2 b)
{
    return a * b;
}

template <int calc_t = 1, typename T1, typename T2>     // C++14 auto
auto get_rect(T1 width, T2 height)
{
    if(calc_t == 1)
        return width * height;
    else
        return 2 * (width + height);
}

int main()
{
    int res_1 = sq_rect(5, 6.5);                    // double sq_rect<int, double>(int a, double b)
    double res_2 = sq_rect(5, 6);                   // int sq_rect<int, int>(int a, int b)
    short res_3 = sq_rect<short>(2, 3);             // int sq_rect<short, short>(short a, short b)
    short res_4 = sq_rect<double>(2, 3);            // double sq_rect<double, int>(double a, int b)

    double res_5 = get_rect(5, 6.5);
    int res_6 = get_rect<2>(5, 6.5);    // <2> 
 
    return 0;
}