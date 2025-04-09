#include <iostream>

// здесь объявляйте класс
class Thing {
    long id {0};
    int price {0};                  // цена товара
    double weight {0.0};            // вес товара
    bool check_price(int x);        // возвращает true, если x >= 0 и false в противном случае
    bool check_weight(double x);    // возвращает true, если x >= 0 и false в противном случае
public:
    Thing() = default;
    Thing(long a, int b, double c) : id(a)
    {
        price = check_price(b) ? b : price;
        weight = check_weight(c) ? c : weight;
    }
    void get_info(long& id, int& price, double& weight); // возвращает значение соответствующих полей
};

// Внешние реализации
bool Thing::check_price(int x)
    { return x >= 0; }
bool Thing::check_weight(double x)
    { return x >= 0.0; }
void Thing::get_info(long& id, int& price, double& weight)
{
    id = this->id;
    price = this->price;
    weight = this->weight;
}

int main(void)
{
    // здесь продолжайте функцию main
    Thing th(5, 53403, 87.4);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}