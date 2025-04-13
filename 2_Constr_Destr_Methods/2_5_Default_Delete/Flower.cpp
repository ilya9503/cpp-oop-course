#include <iostream>
#include <cstring>

// здесь объявляйте класс
class Flower {
    char name[100] = {0};   // название цветка
    int price {0};          // цена цветка
public:
    // Конструкторы
    Flower(const char* n, int p) : price(p)
    {
        strncpy(this->name, n, 100);
        std::cout << n << " " << name << std::endl;
    }
    Flower(const Flower& other) = delete;   // запрещаем конструктор копирования
    // Методы
    void get_data(char* name, int& price) // получение значения полей name и price
    {
        strcpy(this->name, name);
        price = this->price;
        // *this->name = *name;
    }
    void get_name()
    {
        std::cout << this->name << std::endl;
    }
    void get_price()
    {
        std::cout << this->price << std::endl;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    //Flower f("Роза", 1000);
    //Flower f0;
    //Flower f_cp(f);
    Flower flower("Тюльпан", 120);
    flower.get_name();
    flower.get_price();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}