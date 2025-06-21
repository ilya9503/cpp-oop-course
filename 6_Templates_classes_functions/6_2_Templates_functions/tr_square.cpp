#include <iostream>
#include <cmath>

// здесь объявляйте функцию
template <typename T1, typename T2, typename T3>
auto tr_square(T1 a, T2 b, T3 c)
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}


int main()
{
    // здесь продолжайте функцию main
    auto res_1 = tr_square(10, 6, 8);
    auto res_2 = tr_square(5.3, 2.7, 7);
    auto res_3 = tr_square(90, 'a', 55.4);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}