#include <iostream>

// здесь объявляйте классы
class BoxError : public std::exception {    // базовый класс для исключений
protected:
    std::string msg;
public:
    BoxError(const std::string& m) : msg(m) {   }
    const char* what() const noexcept override { return msg.data(); }   // переопределяем std::exception::what()
};

class BoxLimitError : public BoxError {
public:
    BoxLimitError(const std::string& m) : BoxError(m) {   }
};

class BoxCalcError : public BoxError {
public:
    BoxCalcError(const std::string& m) : BoxError(m) {   }
};



class Box3D {
    enum {limit_dim = 100}; // предельное значение габарита (любого)
    short a{0}, b{0}, c{0}; // габариты
public:
    Box3D(short a1=0, short b1=0, short c1=0)
    {
        if(a1 < 0 || a1 > limit_dim || b1 < 0 || b1 > limit_dim || c1 < 0 || c1 > limit_dim)
            throw BoxLimitError("Exceeding the size range.");

        this->a = a1;
        this->b = b1;
        this->c = c1;
    }

    void get_dims(short& a, short& b, short& c) // возвращаются значения соответствующих полей
    {
        a = this->a;
        b = this->b;
        c = this->c;
    }

    void set_dims(short a, short b, short c) // в соответствующие поля заносятся переданные значения
    {
        if(a < 0 || a > limit_dim || b < 0 || b > limit_dim || c < 0 || c > limit_dim)
            throw BoxLimitError("Exceeding the size range.");

        this->a = a;
        this->b = b;
        this->c = c;
    }

    Box3D operator+(const Box3D& right)
    {
        short res_a = a + right.a;
        short res_b = b + right.b;
        short res_c = c + right.c;

        if(res_a < 0 || res_a > limit_dim || res_b < 0 || res_b > limit_dim || res_c < 0 || res_c > limit_dim)
            throw BoxCalcError("Calculation: Exceeding the size range.");

        return Box3D(res_a, res_b, res_c);
    }

    Box3D operator-(const Box3D& right)
    {
        short res_a = a - right.a;
        short res_b = b - right.b;
        short res_c = c - right.c;

        if(res_a < 0 || res_a > limit_dim || res_b < 0 || res_b > limit_dim || res_c < 0 || res_c > limit_dim)
            throw BoxCalcError("Calculation: Exceeding the size range.");

        return Box3D(res_a, res_b, res_c);
    }

};

int main()
{
    // здесь продолжайте функцию main
    try {
        Box3D box(5, -1, 10);
    }
    catch(const BoxCalcError& exc) {
        std::cout << exc.what() << std::endl;
    }
    catch(const BoxLimitError& exc) {
        std::cout << exc.what() << std::endl;
    }
    catch(const BoxError& exc) {
        std::cout << exc.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}