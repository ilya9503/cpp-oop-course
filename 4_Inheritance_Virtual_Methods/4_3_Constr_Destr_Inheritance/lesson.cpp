/*
    4.3 Порядок вызовов конструкторов и деструкторов при наследовании
    Конструкторы и деструкторы по умолчанию отрабатывают в таком порядке:
        Base: constructor
        Line: constructor
        Line: destructor
        Base: destructor
    Отрабатывают в порядке стека
    Если конструктор по-умолчанию не определен в базовом типе, то его нужно вручную вызвать в дочернем
*/

#include <iostream>

// Базовый
class GeomBase {
protected:
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    GeomBase(int a, int b, int c, int d) : x0(a), y0(b), x1(c), y1(d)
        { std::cout << "Base: constructor" << std::endl; }
    ~GeomBase()
        { std::cout << "Base: destructor" << std::endl; }
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0; this->y0 = y0;
        this->x1 = x1; this->y1 = y1;
    }

    void get_coords(int& x0, int& y0, int& x1, int& y1)
    {
        x0 = this->x0; y0 = this->y0;
        x1 = this->x1; y1 = this->y1;
    }
};

// Дочерний    
class Line : public GeomBase {
private:
    double length{0.0};
public:
    Line() : GeomBase(0, 0, 0, 0)   // перед выполнением конструктора дочернего класса, вызываем конструктор для базового
        { std::cout << "Line: constructor" << std::endl; }
    Line(int a, int b, int c, int d, double l) : GeomBase(a, b, c, d), length(l)   // перед выполнением конструктора дочернего класса, вызываем конструктор для базового
        { std::cout << "Line: constructor" << std::endl; }
    ~Line()
        { std::cout << "Line: destructor" << std::endl; }
    void draw()
    {
        printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1);
    }
};


int main()
{
    Line* ptr_line = new Line();
    delete ptr_line;    // если не освободить память, деструктор не вызывается!
                        // однако, уже после завершения main() ОС автоматически освобождает выделенную память
    return 0;
}