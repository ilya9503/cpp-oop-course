#include <iostream>
#include <string>

class VectorError : public std::exception {     // класс исключения
protected:  // для наследования
    std::string msg;
public:
    VectorError(const std::string& error) noexcept : msg(error)
        { }
    virtual ~VectorError() { }

    const char * what() const noexcept override { return msg.data(); }  // переопределен от std::exception
};

// здесь объявляйте классы
class VectorErrorNegativeCoord : public VectorError {       // дочерний класс исключения
public:
    VectorErrorNegativeCoord() noexcept : VectorError("Negative coordinate value.")
        {   }
    VectorErrorNegativeCoord(const std::string& m) noexcept : VectorError(m)
        {   }
};

class Vector {
    int x{0}, y{0};
public:
    Vector(int x=0, int y=0)
    {
        if(x < 0 || y < 0)
            throw VectorErrorNegativeCoord("Constructor: Negative coordinate value.");

        this->x = x;
        this->y = y;
    }

    int get_x() const { return x; } // возвращает значение x
    int get_y() const { return y; } // возвращает значение y

    void set_xy(int x, int y) // заносит в поля x, y переданные значения
    {
        if(x < 0 || y < 0)
            throw VectorErrorNegativeCoord();

        this->x = x;
        this->y = y;
    }
};

int main()
{
    // здесь продолжайте функцию main
    int x, y;
    std::cin >> x >> y;

    try {
        Vector v(x, y);
        std::cout << x << " " << y << std::endl;
    }
    catch(const VectorError& ve) {
        std::cout << ve.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}