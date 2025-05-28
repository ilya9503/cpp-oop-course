#include <iostream>

class Point {
    enum {min_coord = -10, max_coord = 10};
    int x{0}, y{0};
public:
    Point(int x1=0, int y1=0) : x(x1), y(y1)
    {
        if(x <= min_coord || x >= max_coord || y <= min_coord || y >= max_coord)
            throw "Incorrect coordinate values";
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    try {
        Point pt(11, -5);
    }
    catch(const char* ex) {
        std::cout << ex << std::endl;
    }
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}