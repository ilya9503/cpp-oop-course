/*
    В C++ интерфейс — это абстрактный класс, который определяет только набор методов (обычно чисто виртуальных),
        но не реализует их. Он служит контрактом: любой класс, реализующий интерфейс, обязан реализовать эти методы.
*/

#include <iostream>
#include <string>

// здесь объявляйте классы
class Dish {
protected:
    std::string name; // наименование
    int price {0}; // цена
public:
    Dish(std::string n, int pr) : name(n), price(pr)
        {   }
    virtual void print_dish() // выводит информацию о блюде в выходной поток
    {
        printf("Dish: %s; %d\n", name.c_str(), price);
    }
};

class FishDish : public Dish {
    int weight {0};
public:
    FishDish(std::string n, int pr, int w) : Dish(n, pr), weight(w)
        {   }
    virtual void print_dish() // выводит информацию о блюде в выходной поток
    {
        printf("FishDish: %s; %d; %d\n", name.c_str(), price, weight);
    }
};

class MeatDish : public Dish {
    short fry_type {1}; int weight {0};
public:
    MeatDish(std::string n, int pr, short ft, int w) : Dish(n, pr), fry_type(ft), weight(w)
        {   }
    virtual void print_dish() // выводит информацию о блюде в выходной поток
    {
        printf("MeatDish: %s; %d; %hd; %d\n", name.c_str(), price, fry_type, weight);
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    FishDish* ptr_fd_1 = new FishDish("Устрицы", 900, 300);
    MeatDish* ptr_md_1 = new MeatDish("Бекон", 800, 2, 420);
    FishDish* ptr_fd_2 = new FishDish("Форель", 400, 210);

    Dish* dishes[3];
    dishes[0] = ptr_fd_1;
    dishes[1] = ptr_md_1;
    dishes[2] = ptr_fd_2;

    for(int i = 0; i < 3; ++i)
        dishes[i]->print_dish();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete dishes[0];
    delete dishes[1];
    delete dishes[2];

    return 0;
}