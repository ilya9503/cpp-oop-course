/*
    10000 % 3600 = 2800
    2800 % 60 = 40
*/

#include <iostream>

// здесь объявляйте класс
class Clock {
protected:
    unsigned time_current {0}; // текущее время в секундах
public:
    Clock() = default;
    Clock(unsigned x) : time_current(x)
        {   }
    void set_time(unsigned tm)      // заносит в поле time_current значение tm
        { time_current = tm; }
    unsigned get_hours() const      // возвращает количество часов в time_current
        { return time_current / 3600; }
    unsigned get_minutes() const    // возвращает количество минут в time_current (за вычетом часов)
        { return (time_current % 3600) / 60; }
    unsigned get_seconds() const    // возвращает количество секунд в time_current (за вычетом часов и минут)
        { return (time_current % 3600) % 60; }
};

class ClockShow : public Clock {
public:
    enum time_format { tm_hhmmss = 1, tm_hms = 2, tm_ssmmhh = 3, tm_smh = 4};
private:
    time_format format {tm_hhmmss}; // формат отображения времени
public:
    ClockShow() = default;
    ClockShow(unsigned x)
        { this->time_current = x; }
    ClockShow(unsigned x, ClockShow::time_format tf)
        { this->time_current = x; this->format = tf; }
    void show_time() const // выполняет отображение в консоль времени заданном формате
    {
        switch (format)
        {
            case tm_hhmmss:
                printf("%02u:%02u:%02u", get_hours(), get_minutes(), get_seconds());
                break;
            case tm_hms:
                printf("%u:%u:%u", get_hours(), get_minutes(), get_seconds());
                break;
            case tm_ssmmhh:
                printf("%02u:%02u:%02u", get_seconds(), get_minutes(), get_hours());
                break;
            case tm_smh:
                printf("%u:%u:%u", get_seconds(), get_minutes(), get_hours());
                break;
            default:
                break;
        }
    }
};


int main()
{
    // здесь продолжайте функцию main
    unsigned x{0};
    std::cin >> x;
    ClockShow clock(x, ClockShow::tm_hms);
    clock.show_time();
    //Clock cl(10000);
    //cl.set_time(12301);
    //std::cout << cl.get_hours() << " часов " << cl.get_minutes() << " минут " << cl.get_seconds() << " секунд" << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}