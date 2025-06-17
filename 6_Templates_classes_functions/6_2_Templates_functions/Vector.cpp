#include <iostream>

class Point {
    double x {0}, y{0};
public:
    Point(double x = 0, double y = 0) : x(x), y(y)
        { }
    void get_coords(double& x, double& y) const { x = this->x; y = this->y;}
};

class Vector {
    int x {0}, y{0};
public:
    Vector(int x = 0, int y = 0) : x(x), y(y)
        { }
    void get_coords(int& x, int& y) const { x = this->x; y = this->y;}
};

// здесь объявляйте функцию
template <typename T1=Point, typename T2=double>
T2 sum_coords(const T1 &a)
{
    T2 x, y;
    a.get_coords(x, y);
    return x + y;
}

int main()
{
    // здесь продолжайте функцию main
    Point p(10.5, -4.7);
    Vector v(132, 55);

    double sm1 = sum_coords(p);
    int sm2 = sum_coords<Vector, int>(v); 

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}