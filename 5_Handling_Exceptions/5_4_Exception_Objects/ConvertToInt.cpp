#include <iostream>
#include <string>
#include <stdlib.h>

// здесь объявляйте класс
class ExceptionConvert {
    std::string msg; // сообщение об ошибке
public:
    ExceptionConvert(const std::string& m) : msg(m)
        {  }
    const std::string& to_msg() const // возвращает строку msg
        { return msg; }
};

class ConvertToInt {
    const char* str{nullptr};
public:
    ConvertToInt() = default;
    int operator()(const char* str)     // функтор
    {
        // То есть, любой нецифровой символ, кроме '+', '-', '.', приводит к ошибке конвертации строки в число.
        const char* x {"+-.0123456789"};    // если есть любой символ кроме этих, то выбрасываем исключение
        bool res{false};
        for(int i=0; str[i] != 0; ++i) {
            for(int j=0; x[j] != 0; ++j) {
                res = res || (str[i] == x[j]);
            }
            if(!res)
                throw ExceptionConvert("Conversion error");
            res = false;
        }

        return atoi(str);
    }
};


int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    // здесь продолжайте функцию main
    ConvertToInt str_to_int;

    try {
        std::cout << str_to_int(str) << std::endl;
    }
    catch(const ExceptionConvert& exc) {
        std::cout << exc.to_msg() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}