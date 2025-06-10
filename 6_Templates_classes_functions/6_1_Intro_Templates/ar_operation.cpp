#include <iostream>

enum ar_operation {
    ar_sum = 1, // сложение
    ar_sub = 2, // вычитание
    ar_mul = 3 // умножение
};

// здесь объявляйте класс и функцию
template<typename T> T calc_data(T a, T b, ar_operation type=ar_sum)
{
    T temp;
    switch (type) {
        case 1:
            temp = a + b;
            break;
        case 2:
            temp = a - b;
            break;
        case 3:
            temp = a * b;
            break;
        default:
            return temp;
            break;
    }
    return temp;
}

class Complex {
    int re {0}, im {0}; // действительная и мнимая части
public:
    Complex(int r=0, int i=0) : re(r), im(i)
        {   }

    int real() const // возвращает значение поля re
        { return re; }
    int imag() const // возвращает значение поля im
        { return im; }
    void set_value(int real, int imag) // заносит в поля re и im переданные значения
    {
        re = real;
        im = imag;
    }

    Complex operator+(const Complex& left)
    {
        return Complex(re + left.re, im + left.im);
    }

    Complex operator-(const Complex& left)
    {
        return Complex(re - left.re, im - left.im);
    }

    Complex operator*(const Complex& left)
    {
        return Complex(re * left.re - im * left.im, re * left.im + im * left.re);   // cm1.re * cm2.re - cm1.im * cm2.im, cm1.re * cm2.im + cm2.re * cm1.im
    }
/*     const Complex& operator=(const Complex& left)
    {

    } */
};

int main()
{
    // здесь продолжайте функцию main
    Complex cmp_1(-5, 23), cmp_2(14, 7);

    Complex res_1 = calc_data(cmp_1, cmp_2, ar_sub);
    double res_2 = calc_data(0.5, 10.4, ar_sum);    // 10.9
    int res_3 = calc_data(5, -11, ar_mul);          // -55

    Complex c2 = 15;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}