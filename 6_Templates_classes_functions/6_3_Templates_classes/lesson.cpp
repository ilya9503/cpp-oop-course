/*
    Введение в шаблоны классов

    Шаблоны (templates) в C++ нужны для написания универсального, повторно используемого кода, который может работать с разными типами данных,
        не дублируя одно и то же.

    В языке C++ помимо шаблонов функций можно определять и шаблоны классов (и по аналогии шаблоны структур).
*/

#include <iostream>

template <typename T1, typename T2>   // шаблон класса Point
class Point {
    T1 x {};
    T2 y {};
public:
    Point(T1 a, T2 b) : x{a}, y{b}
        { }
};

template <typename T>   // шаблон класса Point_1
class Point_1 {
    static T counter_obj;
    T x{}, y{};
public:
    Point_1(T a = 0, T b = 0);

    T get_x() { return x; }
    T get_y() { return y; }
    void set_xy(T a, T b);

};

template <typename T>   // инициализация статической переменной класса (общая для всего класса, не пренадлежит объектам)
T Point_1<T>::counter_obj = 0;

template <typename T>   // внешняя реализация конструктора шаблонного класса Point_1
Point_1<T>::Point_1(T a, T b) : x{a}, y{b}
{

}

template <typename T>   // внешняя реализация метода шаблонного класса
void Point_1<T>::set_xy(T a, T b)
{
    x = a;
    y = b;
}


/*
class Point {
    int x {}, y {};
public:
    Point(int a, int b) : x(a), y(b)
        { }
};

class DoublePoint {
    double x {}, y {};
public:
    DoublePoint(double a, double b) : x(a), y(b)
        { }
};
*/

int main()
{
    Point<int, int> pt_i(1, 2);      // явно прописываем тип параметра шаблона
    Point<double, double> pt_d(1, 2);

    Point pt_i2(10, 2.2);    // C++17 вычислит тип T по переданным аргументам, обязательно должен быть конструктор
    Point pt_d2(1.2, 2.3);

    Point_1<int> pt1;
    pt1.set_xy(10, 20);

    std::cout << pt1.get_x() << std::endl;



    return 0;
}