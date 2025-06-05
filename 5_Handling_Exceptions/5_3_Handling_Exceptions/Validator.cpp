#include <iostream>
#include <string>

// здесь объявляйте классы
class Validator {
protected:
    std::string msg_ex; // сообщение исключения
public:
    // виртуальные методы и деструктор для наследования
    Validator(const std::string& msg) : msg_ex(msg)
        {   }
    virtual bool is_valid(int x, bool exception = true) const = 0; // проверка условия для значения x (сама проверка реализуется в дочерних классах)
    virtual ~Validator() { }
};

class ValidatorRange : public Validator {
    int min_value {0}, max_value {0};  // диапазон [min_value; max_value]
public:
    ValidatorRange(const std::string& exc, int min, int max) : Validator(exc), min_value(min), max_value(max)
        {   }   // можно было не делать конструктор базового класса, через this->msg_ex инициализировать поле
    bool is_valid(int x, bool exception = true) const // возвращает true, если x принадлежит диапазону [min_value; max_value], иначе false
    {
        if(exception) {
            if(x >= min_value && x <= max_value)
                return true;
            else
                throw msg_ex;
        }
        else 
            return x >= min_value && x <= max_value;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    ValidatorRange vr("Value is outside the range [0; 15]", 0, 15);
    int x{0};
    std::cin >> x;

    try {
        vr.is_valid(x);
    }
    catch(std::string exc) {
        std::cout << exc << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}