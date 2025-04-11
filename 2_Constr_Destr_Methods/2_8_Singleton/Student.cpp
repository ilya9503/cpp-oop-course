#include <iostream>

// здесь объявляйте класс
class Student {
    std::string fio;
    short old;
    Student() = default;
    Student(const Student&) = default;

public:
    const Student& operator=(const Student& ) = delete;
    Student(const std::string& f, short o) : fio(f), old(o)
        {   }
    void set_data(const std::string& fio, short old)   // заносит в соответствующие поля переданные значения
    {
        this->fio = fio;
        this->old = old;
    }
    std::string& get_fio() { return fio; };               // возвращает значение поля fio
    short get_old() { return old; };                      // возвращает значение поля old
};


int main(void)
{
    // здесь продолжайте функцию main
    Student* ptr_st = new Student("Pushkin", 21);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete ptr_st;
    return 0;
}