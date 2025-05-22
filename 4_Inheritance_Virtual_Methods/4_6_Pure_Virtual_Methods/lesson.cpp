/*
    Чисто виртуальные методы. Абстрактные классы

    Благодаря этим конструкциям и механизму наследования появляется возможность описывать логику программы на обобщенном уровне,
        не привязываясь к конкретной реализации

    То есть, определяя метод без тела, мы в базовом классе создам универсальный интерфейс для вызова произвольных методов с
        аналогичной сигнатурой из дочерних классов.
    Сами же виртуальные методы без реализаций получили название чисто виртуальных методов (pure virtual function, method).

    Абстрактные классы
    Любой класс в языке C++, который содержит или наследует без переопределения хотя бы один чисто виртуальный метод, является абстрактным.
    Это значит, что объекты этого класса создавать не получится
*/

#include <iostream>

class GeomBase {
protected:
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0; this->y0 = y0;
        this->x1 = x1; this->y1 = y1;
    }
 
    virtual void draw() const = 0;  // Виртуальный метод с отсутствующим телом (обязательно должен быть переопределен в дочернем классе)

};
 
class Line : public GeomBase {
private:
    double length{0.0};
public:
    virtual void draw() const override
    {
        printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1);
    }
};

class Rect : public GeomBase {
public:
    virtual void draw() const override
        { printf("Rect: %d, %d, %d, %d\n", x0, y0, x1, y1); }
};
 
class Ellipse : public GeomBase {
public:
    virtual void draw() const override
        { printf("Ellipse: %d, %d, %d, %d\n", x0, y0, x1, y1); }
};

class Circle : public GeomBase {
public:
    virtual void draw() const override
        { printf("Circle: %d, %d, %d, %d\n", x0, y0, x1, y1); }
};

enum {max_geoms = 1000};

int main()
{
    size_t count_g = 5; // число геометрических фигур
    GeomBase* geoms[max_geoms] = {nullptr};
 
    geoms[0] = new Line;
    geoms[1] = new Rect;
    geoms[2] = new Line;
    geoms[3] = new Ellipse;
    geoms[4] = new Circle;

/*
    пример динамического полиморфизма, когда вызываемый метод (draw) определяется не в момент компиляции программы,
    а в момент ее работы.

*/

    for(size_t i = 0;i < count_g; ++i)
        geoms[i]->draw();
 
    for(size_t i = 0;i < count_g; ++i)
        delete geoms[i];
 
    return 0;
}