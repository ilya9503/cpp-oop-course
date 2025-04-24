#include <iostream>

// здесь объявляйте класс
class LineDouble {
    double x0 {0}, y0 {0}, x1 {0}, y1 {0}; // координаты линии
public:
    LineDouble() = default;
    LineDouble(double a, double b, double c, double d) : x0(a), y0(b), x1(c), y1(d)
        {   }
    LineDouble(const LineDouble& other) : x0(other.x0), y0(other.y0), x1(other.x1), y1(other.y1)
        {   }
    void set_coords(double a, double b, double c, double d) // заносит в поля x0, y0, x1, y1 переданные значения
    {
        x0 = a;
        y0 = b;
        x1 = c;
        y1 = d;
    }
    void get_coords(double& a, double& b, double& c, double& d) const // возвращает координаты x0, y0, x1, y1
    {
        a = x0;
        b = y0;
        c = x1;
        d = y1;
    }
    LineDouble operator+(const LineDouble& other)
    {
        return LineDouble(x0 + other.x0, y0 + other.y0, x1 + other.x1, y1 + other.y1);
    }
    const LineDouble& operator+=(double x)
    {
        x0 += x;
        y0 += x;
        x1 += x;
        y1 += x;
        return *this;
    }
    const LineDouble& operator-=(double x)
    {
        x0 -= x;
        y0 -= x;
        x1 -= x;
        y1 -= x;
        return *this;
    }
    const LineDouble& operator+=(const LineDouble& other)
    {
        x0 += other.x0;
        y0 += other.y0;
        x1 += other.x1;
        y1 += other.y1;
        return *this;
    }
    const LineDouble& operator-=(const LineDouble& other)
    {
        x0 -= other.x0;
        y0 -= other.y0;
        x1 -= other.x1;
        y1 -= other.y1;
        return *this;
    }
    const LineDouble& operator++()
    {
        x0 = x0 + 0.1;
        y0 = y0 + 0.1;
        x1 = x1 + 0.1;
        y1 = y1 + 0.1;
        return *this;
    }
    const LineDouble& operator--()
    {
        x0 = x0 - 0.1;
        y0 = y0 - 0.1;
        x1 = x1 - 0.1;
        y1 = y1 - 0.1;
        return *this;
    }
    LineDouble operator++(int)
    {
        LineDouble temp = *this;
        x0 = x0 + 0.1;
        y0 = y0 + 0.1;
        x1 = x1 + 0.1;
        y1 = y1 + 0.1;
        return temp;
    }
    LineDouble operator--(int)
    {
        LineDouble temp = *this;
        x0 = x0 - 0.1;
        y0 = y0 - 0.1;
        x1 = x1 - 0.1;
        y1 = y1 - 0.1;
        return temp;
    }
};

int main()
{
    double a, b, c, d;
    //LineDouble ln; // все координаты должны быть равны нулю
    //LineDouble ln_1(a, b, c, d); // числа a, b, c, d заносятся в соответствующие поля

    LineDouble ln1(1, 2, 3, 4), ln2(10, 20, 30, 40);
    LineDouble ln = ln1 + ln2; // сложение соответствующих координат между собой (объекты ln1, ln2 не меняются)
    LineDouble r_1 = ln1 += 1.5; // к каждой координате прибавляется значение 1.5
    LineDouble r_2 = ln2 -= 0.1; // от каждой координаты вычитается значение 0.1
    LineDouble r_3 = ln2 += ln1; // сумма соответствующих координат с сохранением результата в объекте ln2
    LineDouble r_4 = ln1 -= ln2; // разность соответствующих координат с сохранением результата в объекте ln1
    ln1++; // увеличение каждой координаты на 0.1
    ++ln1; // увеличение каждой координаты на 0.1
    ln2--; // уменьшение каждой координаты на 0.1
    --ln2; // уменьшение каждой координаты на 0.1

    return 0;
}