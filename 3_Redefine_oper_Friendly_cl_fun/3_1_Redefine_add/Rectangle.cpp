#include <iostream>

// здесь объявляйте класс
class Rectangle {
    int x0 {0}, y0 {0}, x1 {0}, y1 {0}; // координаты верхнего левого угла (x0, y0) и правого нижнего (x1, y1)
public:
    Rectangle() = default;
    Rectangle(int a, int b, int c, int d) : x0(a), y0(b), x1(c), y1(d)
        {   }
    Rectangle operator+(const Rectangle& right)
    {
        return Rectangle(get_min(x0, right.x0), get_min(y0, right.y1), get_max(x1, right.x1), get_max(y1, right.y1));
    }
    int get_min(int x, int y)
        { return x < y ? x : y; }
    int get_max(int x, int y)
        { return x > y ? x : y; }
    void get_coords(int& x0, int& y0, int& x1, int& y1) const    // возвращает значение соответствующих полей
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(int x0, int y0, int x1, int y1)        // заносит в соответствующие поля переданные значения
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    Rectangle rect_1(-5, 0, 10, 12);
    Rectangle rect_2(1, -2, 7, 14);
    Rectangle res = rect_1.operator+(rect_2);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}