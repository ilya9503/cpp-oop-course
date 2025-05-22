#include <iostream>
#include <string>
#include <iomanip>

class Thing {   // Базовый
protected:
    std::string name;
    int price {0};
public:
    Thing(const std::string name = "", int price = 0) : name(name), price(price)
        { }

    const std::string& get_name() const { return name; }
    int get_price() const { return price; }
    virtual void print() {  }
};

class Cart {
    enum { max_total_thing = 100 };
    Thing* goods[max_total_thing] {nullptr}; // товары в корзине
    int count {0}; // текущее количество товаров
public:
    void append(Thing* th)
    {
        if(count >= max_total_thing) return;
        goods[count++] = th;
    }

    Thing** get_goods() { return goods; }
    int get_count() const { return count; }
    void show()
    {
        for(int i = 0; i < count; ++i)
            goods[i]->print();
    }
};

class Table : public Thing {    // Дочерний
    int color {0}; double weight {0.0};
public:
    Table(std::string n, int pr, int col, double w) : color(col), weight(w)
    {
        this->name = n;
        this->price = pr;
    }

    virtual void print() // отображает строку (без кавычек) "Table: name, price, color, weight" (поле weight с точностью до сотых)
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Table: " << this->name << ", " << this->price << ", " << this->color << ", " << this->weight << std::endl;
    }
};

class TV : public Thing {
    int size {0};
public:
    TV(std::string n, int pr, int sz) : size(sz)
    {
        this->name = n;
        this->price = pr;
    }

    virtual void print() // отображает строку (без кавычек) "TV: name, price, size"
    {
        printf("TV: %s, %d, %d\n", this->name.c_str(), this->price, this->size);
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Cart cart;
    Thing* things[4];
    things[0] = new Table("Стол", 12000, 0, 12.70);
    things[1] = new TV("Panasonic", 54000, 43);
    things[2] = new TV("Samsung", 83500, 54);
    things[3] = new Table("Стол 2", 9500, 432, 10.74);

    for(int i = 0; i < 4; ++i)
        cart.append(things[i]);
        
    cart.show();
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete things[0];
    delete things[1];
    delete things[2];
    delete things[3];

    return 0;
}