#include <iostream>

// здесь объявляйте классы
template <typename T>
struct Point {
    T x{0}, y{0};
    Point(T x1=0, T y1=0) : x{x1}, y{y1}
        {   }
};

template <typename D>
class Line {
    Point<D> sp{0}, ep{0};
public:
    Line() = default;
    Line(Point<D> sp1, Point<D> ep1) : sp{sp1}, ep{ep1}
        {   }
    Line(D x0, D y0, D x1, D y1)
    {
        sp.x = x0;
        sp.y = y0;
        ep.x = x1;
        ep.y = y1;
    }

    Point<D> get_sp() const { return sp; } // константный метод, возвращающий структуру Point (поле sp);
    Point<D> get_ep() const { return ep; } // константный метод, возвращающий структуру Point (поле ep);
    void set_coords(Point<D> sp1, Point<D> ep1) // метод с двумя параметрами типа Point, задающий значения полей sp и ep (именно в таком порядке).
    {
        sp = sp1;
        ep = ep1;
    }
};

int main()
{
    // здесь продолжайте функцию main
    Line<unsigned> line(1, 2, 11, 54);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}