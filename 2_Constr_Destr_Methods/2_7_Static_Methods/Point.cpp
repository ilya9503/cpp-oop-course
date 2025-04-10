#include <iostream>

// здесь объявляйте класс
class Point {
    static int MIN_COORD;
    static int MAX_COORD;
    int x {0}, y {0};
    bool check_coord(int coord);    // возвращает true, если coord в диапазоне [MIN_COORD; MAX_COORD], и false в противном случае
public:
    // Конструкторы
    Point(int a=0, int b=0)
    {
        if(check_coord(a) && check_coord(b)) { x = a; y = b; }   
    }
    // Методы
    static void set_bounds(int left, int right);       // меняет значения полей на MIN_COORD = left, MAX_COORD = right
    static void get_bounds(int& left, int& right);     // возвращает значения полей MIN_COORD, MAX_COORD
    void set_coords(int x, int y);  // записывает в поля x, y переданные значения, если метод check_coord для переданных x, y возвращает true (для обоих одновременно)
    int get_x() { return x; };      // возвращает значение поля x
    int get_y() { return y; };      // возвращает значение поля y

};

int Point::MIN_COORD{0};    // объявление и инициализация статических переменных класса
int Point::MAX_COORD{20};

int main(void)
{
    // здесь продолжайте функцию main
    Point::set_bounds(-100, 100);
    Point pt(-5, 7);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}

// Внешние реализации методов класса Point
/*
Point::Point(int a=0, int b=0)
{
    if(check_coord(a) && check_coord(b)) {
        x = a;
        y = b;
    }   
}
*/
bool Point::check_coord(int coord)
{
    return coord >= MIN_COORD && coord <= MAX_COORD;
}
void Point::set_coords(int x, int y)
{
    if(check_coord(x) && check_coord(y)) {
        this->x = x;
        this->y = y;
    }
}
void Point::set_bounds(int left, int right)
{
    MIN_COORD = left;
    MAX_COORD = right;
}
void Point::get_bounds(int& left, int& right)
{
    left = MIN_COORD;
    right = MAX_COORD;
}