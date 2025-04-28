#include <iostream>
#include <iomanip>

// здесь объявляйте класс
class Distance {
    long dist {0}; // дистанция в миллиметрах
public:
    Distance() = default;
    Distance(long d) : dist(d)
        {}
    friend void set_distance(Distance& dst, long value);    // заносит в поле dist объекта dst значение value
    friend long get_distance(const Distance& dst);          // возвращает значение поля dist объекта dst
    friend double distance_to_meters(const Distance& dst);  // возвращает значение поля dist объекта dst в метрах
    friend Distance operator+(const Distance& left, const Distance& right);     // функция сложения 2 объектов Distance
};

// Дружественные функции для класса Distance
void set_distance(Distance& dst, long value)
    { dst.dist = value; }
long get_distance(const Distance& dst)
    { return dst.dist; }
double distance_to_meters(const Distance& dst)
    { return (double)dst.dist / 1000; }
Distance operator+(const Distance& left, const Distance& right)
{
    return Distance(left.dist + right.dist);
}

int main(void)
{
    // здесь продолжайте функцию main
    Distance d(783);
    std::cout << std::fixed << std::setprecision(2);    // выставляем точность
    std::cout << get_distance(d) << ' ' << distance_to_meters(d) << std::endl;
    //Distance d;
    //Distance d2 = 1000;
    Distance d1(100), d2(543);
    Distance res_1 = d1 + d2; // dist = 643
    Distance res_2 = d1 + 500; // dist = 600
    Distance res_3 = 10 + d2; // dist = 553
    std::cout << get_distance(res_1) << ' ' << get_distance(res_2) << ' ' << get_distance(res_3) << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}