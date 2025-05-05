#include <iostream>

// Базовый
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
};

// Дочерний
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Функция
void playSound(const Animal& a) {
    a.makeSound();  // вызывает Dog::makeSound(), если передан объект Dog
}
    

int main()
{
    Animal a;
    Dog d;
    playSound(a);
    playSound(d);
    
    return 0;
}