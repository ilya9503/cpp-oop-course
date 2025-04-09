#include <iostream>

// здесь объявляйте класс
class Clock {
    unsigned tm {0}; // текущее время
public:
    Clock(unsigned t=0) : tm(t)
        {   } 
    unsigned get_time(); // возвращает значение поля tm       
};

unsigned Clock::get_time()
{
    return tm;
}

int main(void)
{
    // здесь продолжайте функцию main
    Clock* ptr_cl = new Clock(12643);
    unsigned res = ptr_cl->get_time();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_cl;

    return 0;
}