#include <iostream>

// здесь объявляйте классы
class LengthValueError : public std::exception {    // класс для генерации исключений
    std::string msg;
public:
    LengthValueError(const char* error) : msg(error)
        { }
    LengthValueError(const LengthValueError& other) : msg(other.msg)
        { }
    const char * what() const noexcept override { return msg.c_str(); }  // noexcept указывает компилятору, что функция не выбрасывает исключений
};

template <typename T=short>
class Triangle {
    T a{0}, b{0}, c{0}; // длины сторон треугольника
public:
    Triangle(T a1=0, T b1=0, T c1=0) : a{a1}, b{b1}, c{c1}
    {
        if(a1 < 0 || b1 < 0 || c1 < 0)
            throw LengthValueError("Length must be a positive number.");
    }

    void get_abc(T& a1, T& b1, T& c1) const   // константный метод, возвращающий через ссылки значения длин a, b, c (именно в таком порядке);
    {
        a1 = a;
        b1 = b;
        c1 = c;
    }
    void set_abc(T a1, T b1, T c1) // метод, задающий значения длин сторон a, b, c (именно в таком порядке).
    {
        if(a1 < 0 || b1 < 0 || c1 < 0)
            throw LengthValueError("Length must be a positive number.");
        else {    
            a = a1;
            b = b1;
            c = c1;
        }
    }
};

int main()
{
    // здесь продолжайте функцию main
    try {
        Triangle<int> tr(7, -4, 10);
    }
    catch(const LengthValueError& err) {
        std::cout << err.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}