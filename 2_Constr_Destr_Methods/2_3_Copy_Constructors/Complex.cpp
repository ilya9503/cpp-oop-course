#include <iostream>
#include <string>
#include <math.h>

// здесь объявляйте класс
class Complex {
    short re{0}, im{0};
public:
    // Конструкторы
    Complex() : re(0), im(0)
        {   }
    Complex(short r) : re(r), im(0)
        {   }
    Complex(short r, short i) : re(r), im(i)
        {   }
    Complex(const Complex& other) : Complex(abs(other.re), abs(other.im))
        { std::cout << re << " " << im << std::endl; }

    // Методы геттеры
    short real()
        { return re; }
    short imag()
        { return im; }
};


int main(void)
{
    // здесь продолжайте функцию main
    //Complex d; // re=0, im=0
    //Complex d = 5; // re=5, im=0
    //Complex d(1, -6); // re=1, im=-6
    Complex digit(-4, 7);
    Complex res(digit);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}