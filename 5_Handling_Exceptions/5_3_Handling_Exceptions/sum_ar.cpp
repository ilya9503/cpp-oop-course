#include <iostream>

// здесь объявляйте функцию

int sum_ar(short* ar, size_t size)
{
    if(size == 0)
        throw "Array length is zero.";
    
    int sum{0};
    for(int i=0; i < size; ++i)
        sum += ar[i];

    return sum;
}

int main(void)
{
    // здесь продолжайте функцию main
    short ar[]{-1, 0, 10, 5, 3, 2};
    int sm{0};

    try {
        sm = sum_ar(ar, 0);
        std::cout << sm << std::endl;
    }
    catch(const char* ex) {
        std::cout << ex << std::endl;
    }



    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}