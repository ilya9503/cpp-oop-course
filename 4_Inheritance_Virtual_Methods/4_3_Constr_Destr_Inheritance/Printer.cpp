#include <iostream>
#include <string>

// здесь объявляйте классы
// Базовый
class Printer {
public:
    enum type_printer {pr_none = 0, pr_needle = 1, pr_jet = 2, pr_laser = 3};
protected:  // доступны дочерним, недоступны извне
    std::string model;
    type_printer type {pr_none};
public:
    Printer() = delete;
    Printer(std::string m, type_printer ty) : model(m), type(ty)
        {   }
    const std::string& get_model() const // возвращает поле model
        { return model; }
    type_printer get_type() const // возвращает поле type
        { return type; }
};

// Дочерний 1
class PrinterJet : public Printer {
private:
    bool color {false};
    short speed {0};
public:
    PrinterJet(std::string m, bool col, short sp) : Printer(m, pr_jet), color(col), speed(sp)
        {   }
    void get_data(std::string& model, type_printer& type, bool& color, short& speed) const
    {
        model = this->model;
        type = this->type;
        color = this->color;
        speed = this->speed;
    }
};

// Дочерний 2
class PrinterLaser : public Printer {
private:
    bool color {false};
    short speed {0};
public:
    PrinterLaser(std::string m, bool col, short sp) : Printer(m, pr_laser), color(col), speed(sp)
        {   }
    void get_data(std::string& model, type_printer& type, bool& color, short& speed) const
    {
        model = this->model;
        type = this->type;
        color = this->color;
        speed = this->speed;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    Printer* pr_lst[4];
    pr_lst[0] = new PrinterJet("Brother Jet 600", true, 5);
    pr_lst[1] = new PrinterLaser("Canon Laser 10", false, 10);
    pr_lst[2] = new PrinterJet("Samsung Jet 100", true, 7);
    pr_lst[3] = new PrinterLaser("BaLaser 1 Pro", true, 21);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete pr_lst[0];
    delete pr_lst[1];
    delete pr_lst[2];
    delete pr_lst[3];

    return 0;
}