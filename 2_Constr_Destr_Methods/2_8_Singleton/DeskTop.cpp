#include <iostream>

// здесь объявляйте класс
class DeskTop {
    int width {0}, height {0};
    DeskTop() = default;
    DeskTop(int w, int h) : width(w), height(h)
        {   }
    DeskTop(const DeskTop&) = default;
public:
    const DeskTop& operator=(const DeskTop& ) { return *this; }
    static DeskTop* get_instance(int w, int h)
    {
        static DeskTop obj(w, h);   // создается только 1 раз (static)
        return &obj;
    }
    int get_width() { return width; };      // возвращает значение поля width
    int get_height() { return height; };    // возвращает значение поля height
};


int main(void)
{
    // здесь продолжайте функцию main
    DeskTop* ptr_desk = DeskTop::get_instance(500, 200); // width = 200, height = 50
    //std::cout << ptr_desk->get_width() << " " << ptr_desk->get_height() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)

    return 0;
}