/*
    4.4 Виртуальные (virtual) методы (функции)
    Статический полиморфизм
        Перегрузка функций
        Вызов методов базового класса через дочерний
    Динамический полиморфизм
        Виртуальные методы (функции)

    Смысл виртуальных методов:
        Они позволяют вызывать методы производного (наследующего) класса через указатель или ссылку на базовый класс.
    Благодаря таблице виртуальных методов, компилятор выбирает какую реализацию метода вызвать для дочернего/базового класса
*/

#include <iostream>

// Базовый
class GeomBase {
protected:
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0; this->y0 = y0;
        this->x1 = x1; this->y1 = y1;
    }
    // vptr - указатель на таблицу виртальных методов
    virtual void draw() const   // виртуальный метод
    {
        printf("GeomBase: %d, %d, %d, %d\n", x0, y0, x1, y1);
    }
};

// Дочерний
class Line : public GeomBase {
private:
    double length{0.0};
public:
    // vptr - указатель на таблицу виртальных методов
    void draw() const
    {
        printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1);
    }
};

int main()
{
    Line* ptr_ln = new Line;    // указатель на дочерний класс
    GeomBase* ptr_b = ptr_ln;   // указатель на базовый класс
 
    ptr_ln->draw();             // вызов метода дочернего класса
    ptr_b->draw();              // вызов метода базового класса
 
    delete ptr_ln;
    return 0;
}