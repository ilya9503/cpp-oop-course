/*
    Напомню, что производную любой функции f в точке x можно найти по формуле:
        diff(x) = (f(x+dt) - f(x)) / dt

    RAII - «Получение ресурса есть инициализация» (англ. Resource Acquisition Is Initialization (RAII)) —
        программная идиома объектно-ориентированного программирования.
    Смысл её в том, что с помощью программных механизмов получение некоторого ресурса неразрывно совмещается с инициализацией,
        а освобождение — с уничтожением объекта.
*/

#include <iostream>
#include <math.h>

using func_diff_dobule = double(*)(double); // указатель на функцию double func(double); Определили пользовательский тип через using
 
// Класс для того, чтобы взять производную любой функции сигнатуры double <имя функции>(double);
// sin(), cos() и тд
class Diff {
    func_diff_dobule func {nullptr};    // указатель на функцию
    double dt {0.001};
public:
    Diff(func_diff_dobule f, double delta = 0.001) : func(f), dt(delta)
        { }
 
    double operator()(double x)
    {
        return (func(x+dt)-func(x)) / dt;
    }
};

int main()
{
    Diff sin_diff(sin); // в параметр копируется указатель на функцию sin() из библиотеки math.h
 
    double res = sin_diff(3.1415/2.0); // 3.1415/2.0
    std::cout << res << std::endl;
 
    return 0;
}