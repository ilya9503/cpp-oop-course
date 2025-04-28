#include <iostream>
#include <string>

// здесь объявляйте класс
class SquareValue {
    unsigned value {0}; // квадрат числа
public:
    SquareValue() = default;
    SquareValue(unsigned x) : value(x*x)
        {   }
    const SquareValue& operator=(unsigned x)
        { value = x*x; return *this; }
    operator unsigned()
        { return value; }

};

int main()
{
    // здесь продолжайте функцию main
    SquareValue sq = 9;
    SquareValue& lnk_sq = sq;
    SquareValue&& lnk_r_sq = static_cast<SquareValue&&>(lnk_sq);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}