#include <iostream>

class Rectangle {
    short x0 {0}, y0 {0}, x1 {0}, y1 {0};
    int border_color {0};
    int fill_color {255};
public:
    Rectangle() = default;
    Rectangle(short a, short b, short c, short d) : x0(a), y0(b), x1(c), y1(d)
        {}
    Rectangle operator=(const Rectangle& right)
    {
        this->x0 = right.x0;
        this->y0 = right.y0;
        this->x1 = right.x1;
        this->y1 = right.y1;
        return *this;
    }
    int get_border_color() const // возвращает значение поля border_color
        { return border_color; }
    int get_fill_color() const // возвращает значение поля fill_color
        { return fill_color; }
    void get_coords(short& x0, short& y0, short& x1, short& y1) const // возвращает значения соответствующих полей
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(short x0, short y0, short x1, short y1) // заносит переданные значения в соответствующие поля
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;        
    }
    void set_border_color(int color) // заносит переданное значение в поле border_color
        { this->border_color = color; }
    void set_fill_color(int color) // заносит переданное значение в поле fill_color
        { this->fill_color = color; }
};

int main()
{
    Rectangle r1;
    Rectangle r2(1, 2, 10, 20);

    Rectangle r;
    r = r2; // копирование только координат x0, y0, x1, y1 (поля border_color и fill_color не копируются)

    return 0;
}