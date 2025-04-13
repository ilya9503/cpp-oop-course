#include <iostream>

class Complex {
    double re{0}, im{0};
public:
	Complex(double real = 0, double imag = 0) : re(real), im(imag) 
		{ }
    double get_real(); // возвращает значение поля re
    double get_imag(); // возвращает значение поля im
};

double Complex::get_real()
{
    return this->re;
}

double Complex::get_imag()
{
    return this->im;
}