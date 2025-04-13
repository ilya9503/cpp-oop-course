#include <iostream>

struct Point
{
    short x, y;
};

class Line {
    short x0, y0, x1, y1; // координаты начала (x0, y0) и конца (x1, y1) линии
public:
    Line(int a=0, int b=0, int c=0, int d=0) : x0(a), y0(b), x1(c), y1(d)   // конструктор по-умолчанию
        {   }

    Line(Point sp, Point ep)    // перегруженный конструктор
    {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }

    void set_coords(short a, short b, short c, short d) // заносит в поля x0, y0, x1, y1 переданные значения
    {
        x0 = a;
        y0 = b;
        x1 = c;
        y1 = d;
    }

    void set_coords(Point sp, Point ep) // заносит в поля x0, y0, x1, y1 переданные значения типа Point
    {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }

    Point get_start() // возвращает координаты (x0, y0) в виде структуры Point
    {
        Point start{x0, y0};
        return start;
    }
    
    Point get_end() // возвращает координаты (x1, y1) в виде структуры Point
    {
        Point end{x1, y1};
        return end;
    }
};

// здесь объявляйте класс Line

int main(void)
{
    Point sp, ep;
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;

    // здесь создавайте объекты класса Line
    Line* ptr_ln1 = new Line(a, b, c, d);
    Line* ptr_ln2 = new Line(sp, ep);

    ptr_ln1->get_start().x;

    std::cout   << ptr_ln1->get_start().x << " " << ptr_ln1->get_start().y <<  " " << ptr_ln1->get_end().x << " " << ptr_ln1->get_end().y << " "
                << ptr_ln2->get_start().x << " " << ptr_ln2->get_start().y <<  " " << ptr_ln2->get_end().x << " " << ptr_ln2->get_end().y << std::endl;


    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_ln1;
    delete ptr_ln2;

    return 0;
}