#include <iostream>
#include <cstring>

// здесь объявляйте класс
class StringChars {
    char* buffer {nullptr};     // массив символов строки
    size_t length {0};          // длина строки (число символов)
public:
    StringChars(const char* b)
    {
        length = strlen(b);
        buffer = new char[length+1]{0};
        strncpy(buffer, b, length);
    }
    StringChars(const StringChars& other)
    {
        this->length = other.length;
        this->buffer = new char[length+1]{0};
        strncpy(this->buffer, other.buffer, length);        
    }
    StringChars operator+(const StringChars& right) const
    {
        char* res = this->buffer;
        res = strcat(res, right.buffer);
        res[strlen(res)+1] = '\0';
        return StringChars(res);
    }
    ~StringChars()
    {
        delete [] buffer;
    }
    char* to_str() const             // возвращает массив buffer
        { return buffer; }
    size_t get_length() const        // возвращает значение поля length
        { return length; }
};


int main(void)
{
    // здесь продолжайте функцию main
    StringChars str_1("Hello"); // buffer = "Hello", length = 5
    std::cout << str_1.to_str() << " " << str_1.get_length() << std::endl;
    StringChars str_2 = str_1;  // buffer = "Hello", length = 5
    std::cout << str_2.to_str() << " " << str_2.get_length() << std::endl;

    StringChars str1("Hello, "), str2("C++");
    StringChars res = str1 + str2; // buffer = "Hello, C++", length = 10
    std::cout << res.to_str() << " " << res.get_length() << std::endl;

    StringChars* ptr_str1 = new StringChars("Language");
    StringChars* ptr_str2 = new StringChars("C++");
    StringChars res1 = ptr_str1->operator+(*ptr_str2);
    std::cout << res1.to_str() << " " << res1.get_length() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete ptr_str1;
    delete ptr_str2;

    return 0;
}