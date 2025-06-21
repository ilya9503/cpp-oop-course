/*
    Наследование шаблонных классов
*/

#include <iostream>

/*  Базовый класс    */
template <typename T>
class GeomBase {
protected:
    T x0{0}, y0{0}, x1{0}, y1{0};
public:
    GeomBase(T x0, T y0, T x1, T y1) : x0{x0}, y0{y0}, x1{x1}, y1{y1}
        { }
};

/*  Дочерний класс    */
template <typename PT>
class Rectangle : public GeomBase<PT> {
public:
    Rectangle(PT x0, PT y0, PT x1, PT y1) : GeomBase<PT>(x0, y0, x1, y1)
        { puts("Rectangle"); }
};

/*   Пример наследования для обычного класса   
class Rectangle : public GeomBase<int> {    // класс GeomBase инстанцируется
public:
    Rectangle(int x0, int y0, int x1, int y1) : GeomBase<int>(x0, y0, x1, y1)
        { puts("Rectangle"); }
};
*/