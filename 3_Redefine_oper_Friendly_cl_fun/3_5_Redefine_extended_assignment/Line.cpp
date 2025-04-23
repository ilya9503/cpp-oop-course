#include <iostream>

// здесь объявляйте класс
class Line {
    short x0 {0}, y0 {0}, x1 {0}, y1 {0};
    int color {0};
public:
    // Конструкторы класса
    Line() = default;
    Line(short a, short b, short c, short d) : x0(a), y0(b), x1(c), y1(d)
        {   }

    // Методы класса
    int get_color() const // возвращает значение поля color
        { return color; }
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
    void set_color(int color) // заносит переданное значение в поле color
        { this->color = color; }

    // Переопределение операторов класса
    const Line& operator=(const Line& other)    // возвращаем const Line& для многократного присвоения
    {
        if(this == &other) return other;

        this->x0 = other.x0;
        this->y0 = other.y0;
        this->x1 = other.x1;
        this->y1 = other.y1;

        return *this;
    }
    const Line& operator+=(const Line& other)
    {
        this->x0 += other.x0;
        this->y0 += other.y0;
        this->x1 += other.x1;
        this->y1 += other.y1;
        return *this;
    }
    const Line& operator-=(const Line& other)
    {
        this->x0 -= other.x0;
        this->y0 -= other.y0;
        this->x1 -= other.x1;
        this->y1 -= other.y1;
        return *this;
    }
    const Line& operator*=(const Line& other)
    {
        this->x0 *= other.x0;
        this->y0 *= other.y0;
        this->x1 *= other.x1;
        this->y1 *= other.y1;
        return *this;
    }
    Line operator+(const Line& other)
    {
        Line temp(
            this->x0 + other.x0,
            this->y0 + other.y0,
            this->x1 + other.x1,
            this->y1 + other.y1
        );
        temp.color = this->color;
        return temp;    // Не получилось вернуть ссылку const Line&
                        // Выделить память на временный объект, тоже неверно (потом не освободить)
                        // Осталось копирование
    }
};

int main()
{
    Line ln3;
    Line ln4(1, 2, 10, 20);

    Line ln_1, ln_2(1, 2, 3, 4);
    ln_1.operator=(ln_2);
    ln_1 = ln_2; // копирование только координат x0, y0, x1, y1 (поле color не копируется)
    Line ln_new(1, 1, 2, 2);
    ln_new += ln_1; // суммирование только для координат для объекта ln_new (поле color без изменений)
    ln_1 -= ln_2; // вычитание только для координат для объекта ln_1 (поле color без изменений)
    ln_new *= ln_2; // умножение только для координат для объекта ln_new (поле color без изменений)
    Line res = ln_new + ln_2; // сложение соответствующих координат объектов ln_new, ln_2 и присваивание результата объекту res 
    
    // При бинарном сложении объектов (последняя команда) координаты в объектах ln_new и ln_2 не меняются.

    return 0;
}

