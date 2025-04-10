#include <iostream>

// здесь объявляйте класс
class Window {
    static unsigned long total;
    int width, height, color;
public:
    Window() = delete;
    Window(int w, int h, int c) : width(w), height(h), color(c)
        { total++; }
    static unsigned long get_total()    // возвращает значение поля total
        { return total; }
    void set_size(int w, int h)         // записывает в поля width, height переданные значения w, h
        { width = w; height = h; }
    void get_size(int& w, int& h)       // возвращает значения полей width и height
        { w = width; h = height;  }
    int get_color()                     // возвращает значение поля color
        { return color; }
};

unsigned long Window::total{0};

int main(void)
{
    // здесь продолжайте функцию main
    Window* ptr_wnd = new Window(200, 100, 255);
    //std::cout << Window::get_total() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_wnd;
    return 0;
}