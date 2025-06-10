#include <iostream>

// здесь объявляйте функцию
template <typename T> T min_3(T a, T b, T c)
{
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int main()
{
    // здесь продолжайте функцию main
    int res_1 = min_3(1, -6, 10);
    double res_2 = min_3(0.5, 0.3, 0.1);
    char res_3 = min_3('a', 'b', '0');
    std::cout << res_1 << " " << res_2 << " " << res_3 << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}