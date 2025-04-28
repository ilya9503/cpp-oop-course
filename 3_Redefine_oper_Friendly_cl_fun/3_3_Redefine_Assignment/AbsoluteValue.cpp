#include <iostream>

class AbsoluteValue {
public:
    unsigned long value {0};
    AbsoluteValue() = default;
    AbsoluteValue(long x)
        { value = x < 0 ? -x : x; }
    const AbsoluteValue& operator=(long x)
    {
        value = x < 0 ? -x : x;
        //std::cout << value << std::endl;
        return *this;
    }
};

int main()
{
    AbsoluteValue* ptr_abv = new AbsoluteValue;
    *ptr_abv = -512;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    delete ptr_abv;

    return 0;
}