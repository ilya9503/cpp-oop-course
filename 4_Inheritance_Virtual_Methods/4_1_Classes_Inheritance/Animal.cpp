#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    short old {0};
public:
    Animal() = default;
    Animal(std::string n, short age) : name(n), old(age)    // инициализация базового класса
        {   }
    const std::string& get_name() const // возвращает значение поля name
        { return name; }
    short get_old() const               // возвращает значение поля old
        { return old; }
};

class Cat : public Animal {
private:
    int color {0};          // цвет кота
    double weight {0.0};    // вес кота
public:
    Cat(const std::string n, short o, int c, double w)
    : color(c), weight(w)
    {
        this->name = n;
        this->old = o;
    }
    int get_color() const           // возвращает значение поля color
        { return color; }
    double get_weight() const       // возвращает значение поля weight
        { return weight; }
    void set_info(const std::string& name, short old, int color, double weight) // заносит в соответствующие поля переданные значения
    {
        this->name = name;
        this->old = old;
        this->color = color;
        this->weight = weight;
    }
};

class Dog : public Animal {
private:
    std::string breed;  // порода собаки
    short length {0};   // длина собаки
public:
    Dog(std::string name, short old, std::string br, short len)
    : breed(br), length(len)
    {
        this->name = name;
        this->old = old;
    }
    const std::string& get_breed() const    // возвращает значение поля breed
        { return breed; }
    short get_length() const                // возвращает значение поля length
        { return length; }
    void set_info(const std::string& name, short old, const std::string& breed, short length) // заносит в соответствующие поля переданные значения
    {
        this->name = name;
        this->old = old;
        this->breed = breed;
        this->length = length;        
    }
};