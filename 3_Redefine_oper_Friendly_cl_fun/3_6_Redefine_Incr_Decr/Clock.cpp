#include <iostream>

// здесь объявляйте класс
class Clock {
    unsigned tm {0}; // текущее время
public:
    // Конструкторы
    Clock() = default;
    Clock(unsigned x) : tm(x)
        {   }
    // Методы
    unsigned get_time() const // возвращает значение поля tm
        { return tm; }
    unsigned operator+(const Clock& other)
        { return tm + other.tm; }
    const Clock& operator+=(unsigned x)
        { tm += x; return *this; }
    const Clock& operator-=(unsigned x)
    {
        tm -= x;
        if(tm < 0) tm = 0;
        return *this;
    }
    const Clock& operator+=(const Clock& other)
        { tm += other.tm; return *this; }
    const Clock& operator-=(const Clock& other)
    {
        tm -= other.tm;
        if(tm < 0) tm = 0;
        return *this;
    }
    unsigned operator++(int)
        { return tm++; }
    unsigned operator++()
        { return ++tm; }
    unsigned operator--(int)
    {
        unsigned value = tm;
        tm = (tm-1 < 0) ? 0 : tm-1;
        return value;
    }
    unsigned operator--()
    {
        tm = (tm-1 < 0) ? 0 : tm-1;
        return tm;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Clock cl;       // tm = 0
    Clock cl5(100);  // tm = 100

    Clock cl1(40), cl2(1000);
    //Clock res = cl1 + cl2; // cl1.tm + cl2.tm (объекты cl1, cl2 не меняются)
    Clock r_1 = cl1 += 10; // tm += 10
    Clock r_2 = cl2 -= 10; // tm -= 10
    Clock r_3 = cl2 += cl1; // cl2.tm += cl1.tm
    Clock r_4 = cl1 -= cl2; // cl1.tm -= cl2.tm
    unsigned tm_1 = cl1++; // tm++
    unsigned tm_2 = ++cl1; // ++tm
    unsigned tm_3 = cl1--; // tm--
    unsigned tm_4 = --cl1; // --tm

/*
    При выполнении любых операций вычитания отрицательное результирующее время (если оно получается отрицательным) приравнивать нулю.
    В функции main создайте два объекта класса Clock в виде переменных clock_1, clock_2 со значениями времен 100, 430 соответственно.
    Создайте еще один объект в виде переменной res и присвойте ему сумму объектов clock_1 и clock_2.
*/
    Clock clock_1(100), clock_2(430);
    Clock res = clock_1 + clock_2;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}