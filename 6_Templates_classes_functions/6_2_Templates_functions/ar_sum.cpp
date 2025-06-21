#include <iostream>

// здесь объявляйте функцию
template <typename T, typename F>
auto ar_sum(T* ar, size_t len, F filter) // указатель на функцию не сработает с лямбдой bool (*filter)(T), можно через auto
{
    T sum{0};
    for(int i=0; i < len; ++i)
        if(filter(ar[i])) sum += ar[i];

    return sum;
}

int main()
{
    // здесь продолжайте функцию main
    double data[] = {-1, 2.5, -3, -4, 5.1, 6};
    double res = ar_sum<double>(data, (size_t)(sizeof(data)/sizeof(*data)), [](double x){ return x > 0; });

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}