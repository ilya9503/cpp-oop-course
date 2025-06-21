#include <iostream>
#include <cmath>

// здесь объявляйте функцию
template <typename T>
auto ar_sort(T* ar, size_t len, auto filter)
{
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (filter(ar[j+1], ar[j])) { // ar[j] > ar[j + 1]
                // обмен значений
                T temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }    
}

int main()
{
    // здесь продолжайте функцию main
    int data[] = {5, -3, 10, 0, 33, 7, -12};
    ar_sort<int>(data, sizeof(data)/sizeof(*data), [](auto a, auto b){ return abs(a) < abs(b); });

    for(auto t : data)
        std::cout << t << " ";
    std::cout << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}