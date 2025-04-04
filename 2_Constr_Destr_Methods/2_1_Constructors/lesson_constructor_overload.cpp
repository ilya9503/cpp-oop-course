/*
    
*/

#include <iostream>

class Point2D {
    int x {0}, y {0};
public:
    // Перегрузка конструкторов
    Point2D() : x(0), y(0)
        { }
    Point2D(int a, int b) : x(a), y(b)  // однако, лучше использовать 1 конструктор со зн-ями по умолчанию
        { }
    void set_coords(int a, int b) 
        {x = a; y = b;}
    void get_coords(int& a, int& b)
        {a = x; b = y;}
};

int main()
{
    Point2D pt(1, 2);                       // инициализируем при создании, вызывается 1 из конструкторов
    Point2D* ptr_pt = new Point2D(3, 4);

    int x, y;
 
    pt.get_coords(x, y);
    std::cout << x << " " << y << std::endl;
 
    //ptr_pt->set_coords(3, 4);
    ptr_pt->get_coords(x, y);
    std::cout << x << " " << y << std::endl;

    delete ptr_pt;

    return 0;
}