#include <iostream>

class ValidatorInteger {
private:
    int err_no {0}; // номер ошибки
public:
    ValidatorInteger() = default;
    int get_errno() const       // возвращает значение поля err_no
        { return err_no; }
//    bool is_valid(int x) const  // проверка условия для значения x (сама проверка реализуется в дочерних классах)
//        { return true; };
};

class ValidatorRange : public ValidatorInteger {
private:
    int min_value {0}, max_value {0};  // диапазон [min_value; max_value]
public:
    ValidatorRange(int min, int max) : min_value(min), max_value(max)
        {   }
    bool is_valid(int x) const // возвращает true, если x принадлежит диапазону [min_value; max_value], иначе false
    {
        return (x >= min_value && x <= max_value) ? true : false;
    }
};

class ValidatorPositive : public ValidatorInteger {
public:
    ValidatorPositive() = default;
    bool is_valid(int x) const // возвращает true, если x больше или равно нулю, иначе false
    {
        return x >= 0;
    }
};

int main()
{
    ValidatorRange vr(-5, 7);
    ValidatorPositive v_positive;

    int num{0};
    std::cin >> num;
    std::cout << vr.is_valid(num) << ' ' << v_positive.is_valid(num) << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}