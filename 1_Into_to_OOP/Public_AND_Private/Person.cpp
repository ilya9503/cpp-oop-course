#include <iostream>
#include <string>

// здесь объявляйте структуру
struct Person {
private:
    std::string fio;    // ФИО
    std::string job;    // работа
    unsigned char old;  // возраст
public:
    void set_person_data(const std::string &fio, const std::string &job, unsigned char old) // заносит в соответствующие поля переданные значения
    {
        this->fio = fio;
        this->job = job;
        this->old = old;
    }
    void set_person_data(const Person& p) // заносит в соответствующие поля значения из переданного объекта p
    {
        this->fio = p.fio;
        this->job = p.job;
        this->old = p.old;
    }
    void get_data(std::string &fio, std::string &job, unsigned char& old) // возвращает через ссылки значения полей объекта
    {
        fio = this->fio;
        job = this->job;
        old = this->old;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Person p1, p2;
    p1.set_person_data("С.М. Балакирев", "Просветитель", 84);
    p2.set_person_data(p1);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}