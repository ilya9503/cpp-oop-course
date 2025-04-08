/*
    2.4 Этапы жизни объектов классов
        1. Выделение памяти под объект.
        2. Инициализация переменных объекта.
        3. Вызов конструктора объекта.
        4. Жизнь объекта.
        5. Вызов деструктора объекта.
        6. Удаление переменных объекта (вызов их деструкторов, при необходимости).
        7. Освобождение памяти, занимаемой объектом.
*/

#include <iostream>

// Класс Log
class Log {
    unsigned id{0};
public:
    Log(unsigned id_log) : id(id_log)
        { std::cout << "Log: constructor" << std::endl; }
    ~Log()
        { std::cout << "Log: destructor" << std::endl;  }
};

// Класс Point
class Point {
    int x {-1};             // отрабатывает до вызова конструктора
    int y {-1};
    Log lg{5};                 // Объект класса lg
public:
    Point() : x(0), y(0)    // список инициализации - отрабатывает до вызова конструктора (более высокий приоритет перед иниц в классе)
        { std::cout << "Point: constructor 1" << std::endl; }
    Point(int a, int b) : x(a), y(b), lg(1)
        { std::cout << "Point: constructor 2" << std::endl; }
    ~Point()
        { std::cout << "Point: destructor" << std::endl;  }
 
    void get_coords(int& a, int& b) { a = x; b = y; }
    void set_coords(int a, int b) { x = a; y = b; }
};

int main()
{
    Point pt1, pt2(1, 2);
    Point* ptr_pt1 = new Point;
    Point* ptr_pt2 = new Point(10, 20);
 
    delete ptr_pt1;
    delete ptr_pt2;
 
    return 0;
}
