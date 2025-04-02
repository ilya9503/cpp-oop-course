#include <iostream>
#include <string>

// здесь объявляйте класс
class Goods {
public:
    std::string name;   // название
    double weight;      // вес
    int price;          // цена

    const std::string& get_name()   // возвращает ссылку на поле name
        {  return this->name; }
    double get_weight()             // возвращает значение поля weight
        { return this->weight; }
    int get_price()                 // возвращает значение поля price
        { return this->price; }
};


int main(void)
{
    // здесь продолжайте функцию main
    Goods   book {.name = "Основы ООП", .weight = 234.5, .price = 2000},
            toy {.name = "Oculus Quest 3", .weight = 204.6, .price = 80000};

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}