/*
    2.2 Конструктор преобразования. Деструктор

    Ключевое слово explicit
        Если по каким-либо причинам неявное преобразование типов следует запретить, то перед конструктором преобразования достаточно
        прописать ключевое слово explicit, которое было введено в стандарте C++11
    Explicit - stated clearly and in detail, leaving no room for confusion or doubt

*/

#include <iostream>

class Complex {
    double re;
    double im;
 
public:
    Complex() : re(0.0), im(0.0)                            // по-молчанию
        { }
    Complex(double real) : re(real), im(0.0)                // с 1 параметром (Конструктор преобразования)
        { }
    Complex(double real, double imag) : re(real), im(imag)  // с 2 параметрами
        { }
 
    void get_data(double& re, double& im)                   // геттер
    {
        re = this->re;
        im = this->im;
    }
    const Complex& add(const Complex& other)                // сумма двух комплексных чисел
    {
        this->re += other.re;
        this->im += other.im;
        return *this;
    }
};

int main()
{
    Complex c1;             // Complex c1 = Complex c1 {}
    Complex c2(0.5);        // Complex c2{0.5}  Complex c2 = 0.5 Конструктор преобразования
    Complex c3(-5.4, 7.8);  // Complex c3{-5.4, 7.8}  Complex c2 = {-5.4, 7.8}

    
    /*
        c2.add(4.3);
            1. Компилятор создает временный объект класса Complex и инициализирует его КОНСТРУКТОРОМ ПРЕОБРАЗОВАНИЯ
            2. Передает временный объект в метод add()
    */
   //c2.add(c3);
    c2.add(4.3);
    double re, im;
    c2.get_data(re, im);
 
    std::cout << re << " " << im << std::endl;
 
    return 0;
}