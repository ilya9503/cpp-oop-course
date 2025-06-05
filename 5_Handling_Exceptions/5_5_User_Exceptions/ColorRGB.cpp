/*
    Чтобы переопределить операцию gray[indx] = color в классе ColorRGB и добавить проверку диапазона color (от 0 до 255),
    нужно вернуть объект-ссылку из оператора [], которая будет обрабатывать присваивание.
    Один из способов — использовать вложенный класс-посредник (proxy class).
*/

#include <iostream>

// здесь объявляйте классы
class ColorRGBError : public std::exception {    // базовый класс для исключений
protected:
    std::string msg;
public:
    ColorRGBError(const std::string& m) : msg(m) {   }
    const char* what() const noexcept override { return msg.data(); }   // переопределяем std::exception::what()
};

class ColorRGBValueError : public ColorRGBError {
public:
    ColorRGBValueError(const std::string& m) : ColorRGBError(m) {   }
};

class ColorRGBIndexError : public ColorRGBError {
public:
    ColorRGBIndexError(const std::string& m) : ColorRGBError(m) {   }
};







class ColorRGB {
    short r{0}, g{0}, b{0}, err{-1};

    class ColorRef {    // вспомогательный класс для проверки grey[indx] = color;
        short& color;
    public:
        ColorRef(short& col) : color(col)
            {   }

        ColorRef& operator=(short val) 
        {
            if(val < 0 || val > 255)
                throw ColorRGBValueError("Valid values must be in the range [0; 255]");

            color = val;
            return *this;
        }

        operator short() const {
            return color;
        }
    };
public:
    ColorRGB(short r=0, short g=0, short b=0)
    {
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            throw ColorRGBValueError("Valid values must be in the range [0; 255]");

        this->r = r;
        this->g = g;
        this->b = b;
    }
    void set_rgb(short r, short g, short b) // в соответствующие поля заносятся переданные значения
    {
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            throw ColorRGBValueError("Valid values must be in the range [0; 255]");
        this->r = r;
        this->g = g;
        this->b = b;
    }

    short operator[](int x) const 
    {
        if(x < 0 || x > 2)
            throw ColorRGBIndexError("Index must be in range [0; 2]");

        switch(x) {
            case 0:
                return r;
            case 1:
                return g;
            case 2:
                return b;
        }
        return err;
    }

    ColorRef operator[](int x)
    {
        if(x < 0 || x > 2)
            throw ColorRGBIndexError("Index must be in range [0; 2]");

        switch(x) {
            case 0:
                return ColorRef(r);
            case 1:
                return ColorRef(g);
            case 2:
                return ColorRef(b);
        }
        return ColorRef(err);        
    }


};

int main()
{
    // здесь продолжайте функцию main
/*
    try {
        ColorRGB yellow(255, 201, -14);
    }
    catch(const ColorRGBIndexError& exc) {
        std::cout << exc.what() << std::endl;
    }
    catch(const ColorRGBValueError& exc) {
        std::cout << exc.what() << std::endl;
    }
    catch(const ColorRGBError& exc) {
        std::cout << exc.what() << std::endl;
    }
*/


    ColorRGB gray(120, 120, 120);

    short r = gray[0];
    short g = gray[1];
    short b = gray[2];

    gray[3] = 254;


    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}