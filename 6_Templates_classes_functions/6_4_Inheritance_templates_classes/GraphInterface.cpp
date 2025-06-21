#include <iostream>

template <typename T>
class GraphInterface {
public:
    virtual void get_coords(T& x0, T& y0, T& x1, T& y1) const = 0;
    virtual void set_coords(T x0, T y0, T x1, T y1) = 0;
    virtual void draw() const = 0;
    virtual ~GraphInterface() { }
};

// здесь объявляйте классы
template <typename T>
class Elipse : public GraphInterface<T> {
    T x0 {0}, y0 {0}, x1 {0}, y1 {0};
public:
    void get_coords(T& x0, T& y0, T& x1, T& y1) const // возвращает координаты фигуры
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(T x0, T y0, T x1, T y1) // задает координаты фигуры
    {
        
    }
    void draw() const; // отображает координаты фигуры
};

int main()
{
    // здесь продолжайте функцию main

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}