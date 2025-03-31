#include <iostream>

// здесь объявляйте класс
class Table {
    unsigned width, height, depth;
public:
    void set_dims(unsigned width, unsigned height, unsigned depth) // заносит в поля width, height, depth переданные значения
    {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    unsigned get_width(){ return this->width; }     // возвращает значение поля width
    unsigned get_height(){ return this->height; }   // возвращает значение поля height
    unsigned get_depth(){ return this->depth; }     // возвращает значение поля depth
};

int main(void)
{
    // здесь продолжайте функцию main
    Table t1, t2, t3;
    t1.set_dims(10, 10 , 5);
    t2.set_dims(7, 20 , 7);
    t3.set_dims(12, 40 , 6);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}