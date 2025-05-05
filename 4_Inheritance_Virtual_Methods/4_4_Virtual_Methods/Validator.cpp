#include <iostream>

// здесь объявляйте классы
class Validator {
public:
    virtual bool is_valid(int x) // возвращает значение true
        { return true; }
};

class PositiveValidator : public Validator {
public:
    virtual bool is_valid(int x) // возвращает значение true, если x >= 0 и false в противном случае
        { return x >= 0; }
};

class RangeValidator : public Validator {
    int left{0}, right{0};  // границы диапазона
public:
    RangeValidator(int l, int r) : left(l), right(r)
        {   }
    virtual bool is_valid(int x) // возвращает значение true, если x в диапазоне [left; right], и false в противном случае
        { return (x >= left && x <= right) ? true : false; }
};

int main(void)
{
    // здесь продолжайте функцию main
    Validator* vs[3] {nullptr};
    vs[0] = new PositiveValidator();
    vs[1] = new RangeValidator(-5, 5);
    vs[2] = new RangeValidator(-15, 10);

    int x;
    if(!(std::cin >> x)) {
        std::cout << "Incorrect input!" << std::endl;
        return 0;
    }

    std::cout << vs[0]->is_valid(x) << " " << vs[1]->is_valid(x) << " " << vs[2]->is_valid(x) << std::endl;
        
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete vs[0];
    delete vs[1];
    delete vs[2];

    return 0;
}