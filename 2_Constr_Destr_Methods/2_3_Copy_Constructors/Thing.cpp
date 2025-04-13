/*
    конструктор по умолчанию: "default constructor";
    конструктор с одним параметром: "constructor 1";
    конструктор с тремя параметрами: "constructor 3";
*/
#include <iostream>
#include <string>

// здесь объявляйте класс
class Thing {
    std::string name;      // наименование предмета
    double weight{0};      // вес предмета (начальное значение 0)
    int price{0};          // цена предмета (начальное значение 0)
public:
    // Конструктор по умолчанию
    Thing() : weight(0), price(0)
        { std::cout << "конструктор по умолчанию: \"default constructor\";" << std::endl; }

    Thing(std::string n) : name(n), weight(0), price(0)
        { std::cout << "конструктор с одним параметром: \"constructor 1\";" << std::endl; }
    // Делегирующий
    Thing(std::string n, double w, int p) : Thing(n)
    {
        this->weight = w;
        this->price = p;
        std::cout << "конструктор с тремя параметрами: \"constructor 3\";" << std::endl;
    }

    // Методы
    std::string& get_name()
        { return this->name; }
    double get_weight()
        { return this->weight; }
    int get_price()
        { return this->price; }
    // Деструктор     
    ~Thing()
        {}
};


int main(void)
{
    // здесь продолжайте функцию main
    //Thing th1;
    //Thing th2("Book");
    //Thing th3("Mouse", 0.1, 13200);
    Thing* ptr_th = new Thing("HP Omen", 2.3, 120000);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_th;

    return 0;
}