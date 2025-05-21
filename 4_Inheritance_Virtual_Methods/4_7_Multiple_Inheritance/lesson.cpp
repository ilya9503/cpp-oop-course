/*
    4.7 Множественное наследование. Порядок вызова конструкторов и деструкторов
    Дочерний класс наследуется от нескольких базовых

    При наличии нескольких базовых классов можно легко нарушить логику работы всей этой конструкции,
        так как классы не редко разрабатываются разными программистами и учесть их согласованную работу становится не так то просто.

    Применять множественное наследование следует с крайней осторожностью и лучше здесь придерживаться устоявшихся подходов
        к построению таких конструкций.

    Сначала вызываются конструкторы базовых классов в порядке их указания при наследовании, затем, конструктор дочернего класса Line.
        А деструкторы отрабатывают в обратном порядке

    Часто множественное наследование используют для наполнения дочернего класса определенным функционалом
    То есть, с указанием каждого нового базового класса, дочерний класс приобретает все больше и больше
    возможностей. И, наоборот, убирая часть базовых классов, дочерний класс теряет соответствующую часть
    функционала.
*/

#include <iostream>
#include <fstream>

class GeomSerialize {   // базовый функционал для сохранения геометрических фигур в файл
protected:
    bool fl_saved {false};
public:
    GeomSerialize()
        { std::cout << "GeomSerialize: constructor" << std::endl; }
    virtual ~GeomSerialize()
        { std::cout << "GeomSerialize: destructor" << std::endl; }

    virtual void save(std::ostream& os) const = 0;
    virtual void load(std::istream& is) = 0;
};

class GeomBase {        // базовый функционал для отрисовки фигуры
protected:
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    GeomBase(int a = 0, int b = 0, int c = 0, int d = 0)
        : x0(a), y0(b), x1(c), y1(d)
        { std::cout << "GeomBase: constructor" << std::endl; }
    virtual ~GeomBase()
        { std::cout << "GeomBase: destructor" << std::endl; }
 
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0; this->y0 = y0;
        this->x1 = x1; this->y1 = y1;
    }
 
    virtual void draw() const = 0;
};
 
class Line : public GeomBase, public GeomSerialize {    // наследуем сразу от 2-ух базовых классов (получаем функционал 2 базовых классов и свой собственный)
private:
    double length{0.0};
public:
    Line(int a = 0, int b = 0, int c = 0, int d = 0) : GeomBase(a, b, c, d)
        { std::cout << "Line: constructor" << std::endl; }
    ~Line()
        { std::cout << "Line: destructor" << std::endl; }
 
    virtual void draw() const
        { printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1); }

    virtual void save(std::ostream& os) const override
        { os.write((char *)this, sizeof(*this)); }
 
    virtual void load(std::istream& is) override
        { is.read((char *)this, sizeof(*this)); }
};

int main()
{
    // порядок расположения переменных : ln -> x0 y0 x1 y1 fl_saved length (GeomBase->GeomSerialize->Line)
    Line ln(1, 2, 10, 20);

    GeomBase* ptr_b = &ln;
    GeomSerialize* ptr_sz = &ln;
 
    GeomBase& lnk_b = ln;
    GeomSerialize& lnk_sz = ln;

    ptr_b->draw();
    
    std::ofstream ofs("line.dat");  // открываем файловый поток
    lnk_sz.save(ofs);
    ofs.close();
    
    return 0;
}