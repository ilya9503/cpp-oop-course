/*
    Переопределение операции (). Функторы
    Классы, объекты которых можно вызывать подобно функциям, носят название функторы
        start – начальное значение счетчика;
        step – шаг изменения счетчика;
        count – текущее значение счетчика.
*/

#include <iostream>

class Counter {
    double start {0.0};     // начальное значение счетчика
    double step {1.0};      // шаг изменения счетчика
    double count {start};   // текущее значение счетчика
 
public:
    Counter(double start = 0.0, double step = 1.0) : start(start), step(step)
        { count = start; }
    
    operator double() const { return count; }
    
    // Возвращаем текущее значение count и увеличиваем на величину step
    double operator()()
    {
        double ret = count;
        count += step;
        return ret;
    }
};

int main()
{
    Counter c1, c2(0.0, 0.5);
 
    double r1 = c1();
    c1();
    double r2 = c1;
 
    std::cout << r1 << " " << r2 << std::endl;
    
    return 0;
}