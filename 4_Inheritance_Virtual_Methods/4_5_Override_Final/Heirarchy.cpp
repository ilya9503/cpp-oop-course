#include <iostream>

enum type_life {
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

class Protists {
    const type_life type {lf_protists}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Protists() { }
};

class Plants : public Protists {
    const type_life type {lf_plants}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Plants() { }
};

class Mosses : public Plants {
    const type_life type {lf_mosses}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Mosses() { }
};

class Flowering : public Plants {
    const type_life type {lf_flowering}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Flowering() { }
};

class Animals : public Protists {
    const type_life type {lf_animals}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Animals() { }
};

class Worms : public Animals {
    const type_life type {lf_worms}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Worms() { }
};

class Mammals : public Animals {
    const type_life type {lf_mammals}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Mammals() { }
};

class Human : public Mammals {
    const type_life type {lf_human}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Human() { }
};

class Monkeys : public Mammals {
    const type_life type {lf_monkeys}; // вид живого организма
public:
    virtual const type_life get_type() const override { return type; }
    virtual ~Monkeys() { }
};

int main(void)
{
    // здесь продолжайте функцию main
    Protists* life[] {
        new Plants,
        new Flowering,
        new Flowering,
        new Monkeys,
        new Animals,
        new Worms,
        new Worms,
        new Human,
        new Monkeys,
        new Mammals,
        new Animals,
        new Animals
    };

    int count_animals{0};
    int count_monkeys{0};

    for(int i = 0; i < std::size(life); ++i){
        if(life[i]->get_type() == lf_animals) count_animals++;
        if(life[i]->get_type() == lf_monkeys) count_monkeys++;
    }

    Animals* lf_lst1[count_animals];
    Monkeys* lf_lst2[count_monkeys];

    int j{0}, k{0};
    for(int i = 0; i < std::size(life); ++i){
        if(life[i]->get_type() == lf_animals) lf_lst1[j++] = (Animals*)life[i];     // преобразование типов указателей
        if(life[i]->get_type() == lf_monkeys) lf_lst2[k++] = (Monkeys*)life[i];
    }    

    // Plants, Flowering, Flowering, Monkeys, Animals, Worms, Worms, Human, Monkeys, Mammals, Animals, Animals
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (auto p : life)
        delete p;   // выделена на каждый эл-т. Пожтому delete[] life не получится

    return 0;
}