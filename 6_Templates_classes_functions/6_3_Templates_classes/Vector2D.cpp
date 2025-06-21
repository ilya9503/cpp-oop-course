#include <iostream>

// здесь объявляйте класс
template <typename T>
class Vector2D {
    T x{0}, y{0}; // координаты радиус-вектора
public:
    Vector2D() = default;
    Vector2D(T x1, T y1) : x{x1}, y{y1}
        {   }

    T get_x() const { return x; }       // константный метод, возвращающий поле x;
    T get_y() const { return y; }       // константный метод, возвращающий поле y;
    void set_xy(T x, T y)               // метод, задающий значения координат x, y (именно в таком порядке).
    {
        this->x = x;
        this->y = y;
    }
};


int main()
{
    // здесь продолжайте функцию main
    Vector2D<double> vector(-54.2, 10.8);
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}