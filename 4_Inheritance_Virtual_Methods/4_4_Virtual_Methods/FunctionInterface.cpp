#include <iostream>
#include <iomanip>

class FunctionInterface {
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }     // функтор
};

class LinearFunction : public FunctionInterface {
    double k {0.0}; // угловой коэффициент
    double b {0.0}; // смещение
public:
    LinearFunction(double k1, double b1) : k(k1), b(b1)
        {   }
    virtual double func(double arg)        // возвращает значение линейной функции f(arg) = k*arg+b для аргумента arg
    {
        return k * arg + b;
    }
    virtual double operator()(double arg)   // то же самое, только через оператор ()
    {
        return k * arg + b;
    }
};

class ReluFunction : public FunctionInterface {
public:
    ReluFunction() = default;
    virtual double func(double arg) // возвращает значение функции f(arg) = arg, arg > 0, иначе 0
        { return arg > 0 ? arg : 0; }
    virtual double operator()(double arg) // то же самое, только через оператор ()
        { return arg > 0 ? arg : 0; }
};

int main(void)
{
    // здесь продолжайте функцию main
    FunctionInterface* funcs[3] {nullptr};

    funcs[0] = new LinearFunction(0.5, 0);      // через указатель на базовый класс, можно вызвать метод дочернего класса
    funcs[1] = new LinearFunction(1.2, -5.4);
    funcs[2] = new ReluFunction;

    double x{0};
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << funcs[0]->func(x) << " " << funcs[1]->operator()(x) << " " << funcs[2]->func(x) << std::endl;
    

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete funcs[0];
    delete funcs[1];
    delete funcs[2];

    return 0;
}