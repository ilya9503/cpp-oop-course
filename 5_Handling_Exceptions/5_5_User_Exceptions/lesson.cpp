/*
    5.5 Идентификация типов исключений. Пользовательские исключения
    Правила идентификации типов в блоках catch
    T = type (тип)

        Тип в throw             Идентифицируемый тип в catch
        
        T; const T              T; const T; T&; const T&
        T*                      T*; const T*
        const T*                const T*

    В практике программирования, в качестве типов исключений фигурируют КЛАССЫ

    ❌ Почему НЕ стоит использовать простые типы (int, char*) для исключений:
        Нет наследования — нельзя обрабатывать группы ошибок.
        Нет описания ошибки (или нужно придумывать костыли).
        Плохо интегрируется со стандартной библиотекой.
        Повышает риск неправильной обработки (например, catch (...) может не отличить int от других исключений).

    Простые типы допустимы, но они не дают преимуществ и снижают гибкость обработки ошибок.

    Пользовательские классы рекомендуется наследовать от класса std::exception

*/

#include <iostream>

/* ====================================================================================================================================== */
// Пользовательские классы для описания типов исключений
class CardError : public std::exception {   // базовый класс исключений, общий с дочерними
    std::string msg;
public:
    CardError(const char* error) : msg(error)
        { }
    CardError(const CardError& other) : msg(other.msg)
        { }
    const char * what() const noexcept override { return msg.c_str(); }  // noexcept указывает компилятору, что функция не выбрасывает исключений
};
 
class CardLengthError : public CardError {
public:
    CardLengthError(const char* error) : CardError(error)   // заполняем поле msg
        { }
};
 
class CardFormatError : public CardError {
public:
    CardFormatError(const char* error) : CardError(error)
        { }
};
 
class CardNumberError : public CardError {
public:
    CardNumberError(const char* error) : CardError(error)
        { }
};
/* ===================================================================================================================================================== */

class BankCard {
    const int length_number {19};
    std::string number; // 1234-5678-1234-5678
 
    void verify_correct(const std::string& card) const
    {
        if(card.length() != length_number)
            throw CardLengthError("incorrect length card number");    // длина строки не соответствует
 
        const char* p = card.c_str();
        for(int i = 0;i < length_number; ++i) {
            if(i == 4 || i == 9 || i == 14) {
                if(p[i] != '-')
                    throw CardFormatError("incorrect format");      // формат не соответствует
            }
            else if(p[i] < '0' || p[i] > '9')
                throw CardNumberError("only numbers are allowed");  // содержимое не соответствует
        }
    }
 
public:
    void set_number(const std::string& card)
    {
        verify_correct(card);
        number = card;
    }
 
    const std::string& get_number() const { return number; }
};

int main()
{
    BankCard card;
 
    try {
        card.set_number("123a-4567-1234-5678");
    }
    // классы передаем по ссылке, во избежании лишнего копирования
    catch(const CardLengthError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const CardFormatError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const CardNumberError& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const CardError& e) {   // базовый класс будет отлавливать исключения дочерних
        std::cout << e.what() << std::endl;
    }

    return 0;
}