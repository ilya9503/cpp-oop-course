#include <iostream>
#include <string>

// здесь объявляйте класс
class ArrayException {
protected:
    std::string msg; // сообщение об ошибке (исключении)
public:
    ArrayException(const char* e) noexcept : msg(e)
        {   }
    ArrayException(const ArrayException& ar_e) noexcept : msg(ar_e.msg)
        {   }
    virtual ~ArrayException()
        {   }
    const char * what() const noexcept // возвращает строку, хранящуюся в объекте msg
    {
        return msg.c_str();
    }
};

int main()
{
    // здесь продолжайте функцию main
    try {
        throw ArrayException("Main exception");
    }
    catch(const ArrayException& exc)
    {
        std::cout << exc.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}