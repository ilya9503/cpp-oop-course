/*
    Операция целого остатка от деления (%) в C++ возвращает остаток от деления одного целого числа на другое. Она работает следующим образом:
        a%b=a−(a/b)×b
    Основные принципы работы:
        Остаток имеет тот же знак, что и делимое (a).
        Модуль остатка всегда меньше модуля делителя (b).
        Если a делится на b без остатка, то результат a % b равен 0.

    С++20:
        #include <format>
        std::cout << std::format("{:02}:{:02}:{:02}\n", hours, minutes, seconds);

*/

#include <iostream>

// здесь объявляйте класс
class Clock {
    unsigned time_current; // текущее время в секундах
public:
    void set_time(unsigned tm) { this->time_current = tm; } // заносит в поле time_current значение tm
    unsigned get_hours() // возвращает количество часов в time_current
    {
        return this->time_current / 3600;
    }
    unsigned get_minutes() // возвращает количество минут в time_current (за вычетом часов)
    {
        return (this->time_current % 3600) / 60;    // time_current % 3600 - оставшиеся секунды переводим в минуты
    }
    unsigned get_seconds() // возвращает количество секунд в time_current (за вычетом часов и минут)
    {
        return this->time_current % 60;     // оставшиеся секунды, после перевода в минуты
    }
};


int main(void)
{
    // Проверка, поддерживается ли стандарт С++20 компилятором. Через директивы препроцессора
    #if __cplusplus >= 202002L
        std::cout << "Компилятор поддерживает C++20!" << std::endl;
    #else
        std::cout << "C++20 не поддерживается." << std::endl;
    #endif

    // здесь продолжайте функцию main
    unsigned tm;
    std::cin >> tm;

    Clock* ptr_cl = new Clock;  // выделяем память в куче для объекта

    ptr_cl->set_time(tm);

    printf("%02u:%02u:%02u", ptr_cl->get_hours(), ptr_cl->get_minutes(), ptr_cl->get_seconds());

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_cl;
    ptr_cl = nullptr;

    return 0;
}