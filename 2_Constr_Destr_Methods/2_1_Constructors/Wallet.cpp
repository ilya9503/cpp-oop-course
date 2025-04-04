#include <iostream>

// здесь объявляйте класс
class Wallet {
    long volume;   // количество денег в кошельке (начальное значение 0)
public:
    Wallet(long v=0) : volume(v)        // конструктор
        { }
    void set_volume(long volume)        // заносит в поле volume переданное значение volume
        { this->volume = volume; }
    long get_volume()                   // возвращает значение volume
        { return volume; }
};

int main(void)
{
    // здесь продолжайте функцию main
    Wallet wt1(1000), wt2;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}