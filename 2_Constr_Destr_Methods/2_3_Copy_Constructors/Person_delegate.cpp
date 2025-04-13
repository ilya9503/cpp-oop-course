#include <iostream>
#include <string>

class Person {
    std::string fio;    // ФИО
    short old {0};      // возраст
    long salary {0};    // зп
public:
    // Конструктор с 1 параметром
    Person(const std::string& fio) : fio(fio)
        { std::cout << "Person(string)" << std::endl; }
    // Делегирующий конструктор
    Person(std::string fio, short old, long salary) : Person(fio)
    {
        this->old = old;
        this->salary = salary;
        std::cout << this->fio << std::endl;
    }
    // Метод чтения приватных полей
    void get_data(std::string& fio, short& old, long& salary)
    {
        fio = this->fio; old = this->old; salary = this->salary;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Person* ptr_p = new Person("Рахманинов С.В.", 75, 13204);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_p;

    return 0;
}