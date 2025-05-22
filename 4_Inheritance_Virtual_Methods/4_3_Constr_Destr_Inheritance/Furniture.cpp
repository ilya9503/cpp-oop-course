#include <iostream>
#include <string>

// здесь объявляйте классы
class Furniture {
public:
    enum type_furniture {fr_none = 0, fr_table = 1, fr_chair = 2, fr_closet = 3};
protected:
    short width {0}, height {0}, depth {0}; // габариты
    type_furniture type {fr_none};
public:
    Furniture(short w, short h, short d, type_furniture ty)
    : width(w), height(h), depth(d), type(ty)
        {   }
    void get_dims(short& width, short& height, short& depth) const // возвращает значения габаритов
    {
        width = this->width;
        height = this->height;
        depth = this->depth;
    }
    type_furniture get_type() const // возвращает поле type
        { return type; }
};

class Table : public Furniture {
private:
    std::string model;
public:
    Table(std::string m, short w, short h, short d) : Furniture(w, h, d, fr_table), model(m)
        {   }
    const std::string& get_model() const
        { return model; }
};

class Chair : public Furniture {
private:
    int color {0}; int weight {0};
public:
    Chair(short w, short h, short d, int col, int wei) : Furniture(w, h, d, fr_chair), color(col), weight(wei)
        {   }
    void get_data(int& color, int& weight)
    {
        color = this->color;
        weight = this->weight;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    Furniture* fr_lst[5];
    fr_lst[0] = new Table("Черноземья стол 10", 10, 20, 30);
    fr_lst[1] = new Table("Белоземья стол 21", 6, 5, 22);
    fr_lst[2] = new Chair(3, 5, 7, 132, 1650);
    fr_lst[3] = new Chair(3, 6, 5, 200, 1750);
    fr_lst[4] = new Table("Бурый стол", 11, 6, 8);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete fr_lst[0];
    delete fr_lst[1];
    delete fr_lst[2];
    delete fr_lst[3];
    delete fr_lst[4];

    return 0;
}