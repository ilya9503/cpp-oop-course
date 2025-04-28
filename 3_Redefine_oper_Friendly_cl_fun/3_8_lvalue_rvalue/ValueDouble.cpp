#include <iostream>
#include <utility>

// здесь объявляйте класс
class ValueDouble {
    double value {0.0};
public:
    ValueDouble() = default;
    ValueDouble(double x) : value(x)    // конструктор преобразования
        {   }

    double get_value() const            // возвращает значение поля value
        { return value; }
    friend double operator+(const ValueDouble& left, const ValueDouble& right);
    friend double operator+(const ValueDouble& left, double right);
    friend double operator+(double left, const ValueDouble& right);
};

inline double operator+(const ValueDouble& left, const ValueDouble& right)
{
    return left.value + right.value;
}

inline double operator+(const ValueDouble& left, double right)
{
    return left.value + right;
}

inline double operator+(double left, const ValueDouble& right)
{
    return left + right.value;
}

int main()
{
    // здесь продолжайте функцию main
    ValueDouble obj{8.7};
    ValueDouble& lnk_vd = obj;
    ValueDouble&& lnk_r_vd = std::move(lnk_vd);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}