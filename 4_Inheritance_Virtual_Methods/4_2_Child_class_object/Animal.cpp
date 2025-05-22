#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    short old {0};
};

class Cat : public Animal {
    int color {0}; double weight {0.0};
public:
    Cat(std::string n, short o, int c, double w) : color(c), weight(w)
        { name = n; old = o; }
    void get_data(std::string& name, short& old, int& color, double& weight)
    {
        name = this->name;
        old = this->old;
        color = this->color;
        weight = this->weight;
    }
};

class Dog : public Animal {
    int height {0}; int speed {0};
public:
    Dog(std::string n, short o, int h, int s) : height(h), speed(s)
        { name = n; old = o; }
    void get_data(std::string& name, short& old, int& height, int& speed)
    {
        name = this->name;
        old = this->old;
        height = this->height;
        speed = this->speed;       
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Cat cat_1("Zeus", 5, 0, 1.2), cat_2("Poseidon", 7, 122, 0.9);
    Dog dog_1("Rex", 10, 50, 32);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}