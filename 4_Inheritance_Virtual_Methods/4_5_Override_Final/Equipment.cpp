#include <iostream>
#include <string>

// здесь объявляйте классы
class Equipment {
    unsigned long uid{0};           // идентификатор
    static unsigned long counter;   // статический счетчик, создается 1 раз
protected:
    bool is_exists {false}; // наличие оборудования
public:
    Equipment()
        { uid = ++counter; }
    Equipment(bool x) : is_exists(x)
        { uid = ++counter; }
    virtual ~Equipment()
        {   }
    unsigned long get_uid() const // возвращает значение поля uid
        { return uid; }
    virtual void print() const { } // виртуальный метод, переопределяемый в дочерних классах
};

unsigned long Equipment::counter{0};    // инициализируем счетчик

class PC : public Equipment {
    std::string model;  // модель компьютера
    int price {0};      // цена
public:
    PC(std::string m, int pr, bool is_ex) : Equipment(is_ex), model(m), price(pr)
        {   }
    virtual ~PC()
        { printf("~PC\n");  }
    const std::string get_model() const // возвращает значение поля model
        { return model; }
    int get_price() const // возвращает значение поля price
        { return price; }
    virtual void print() const // переопределяемый виртуальный метод
    {
        printf("PC: %s, %d, %d\n", model.c_str(), price, static_cast<int>(is_exists));
    }
};

int main()
{
    Equipment eq; // is_exists = false; uid = 1
    Equipment eq1(true); // is_exists = true; uid = 2
    Equipment eq2(false);
    return 0;
}