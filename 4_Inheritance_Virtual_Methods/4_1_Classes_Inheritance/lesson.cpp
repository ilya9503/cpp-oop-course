/*
    4.1 Наследование классов. Режим protected
    То есть, в классах можно прописывать три разных режима:
        private – доступ в пределах текущего класса;
        protected – доступ в пределах текущего и всех дочерних от него классах;
        public – общий доступ (внутри и за пределами класса).
*/

#include <iostream>

class GeomBase {      // базовый класс - от которого выполняется наследование
protected:  // данные доступны в базовом и дочерних классах. Но недоступны извне (отличие от private)
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
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

class Line : public GeomBase {   // дочерний (производный) класс - наследник базового класса
    double length{0.0};
public:
    void draw()
    {
        //int x0, y0, x1, y1;
        //get_coords(x0, y0, x1, y1);
        printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1);
    }
};

int main()
{
    Line ln;
    ln.set_coords(1, 2, 10, 20);
    ln.draw();

    return 0;
}