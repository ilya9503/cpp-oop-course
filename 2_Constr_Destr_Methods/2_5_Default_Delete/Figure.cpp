#include <iostream>

// здесь объявляйте класс
class Figure {
    int x0 {0}, y0 {0}, x1{0}, y1 {0};
public:
    // Конструкторы
    Figure(int a=0, int b=0, int c=0, int d=0) : x0(a), y0(b), x1(c), y1(d)
        {   }
    Figure(const Figure& other) = delete;
    const Figure& operator=(const Figure& other) = delete;
    // Методы
    void get_data(int& x0, int& y0, int& x1, int& y1) // получение значения полей x0, y0, x1, y1
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
/*
    Figure f;
    Figure f1(1, 2, 10, 20);    // x0=1, y0=2, x1=10, y1=20
    Figure f2, f3;              // разрешено
    Figure f_cp(f);             // запретить
    f = f2;                     // запретить
*/
    Figure fig(-4, 2, 11, 7);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}