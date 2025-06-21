#include <iostream>
#include <cmath>

// здесь объявляйте функцию
template <typename T> double hypot(T a, T b)
{
    return sqrt(a*a + b*b);
}

int main()
{
    // здесь продолжайте функцию main
    double h1 = hypot<double>(1, 0.5);
    double h2 = hypot(6.3, 0.8);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}