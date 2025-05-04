#include <iostream>
#include <string>

// здесь объявляйте классы
class SmartPhone {
protected:
    std::string model;
    double weight {0.0};
public:
    SmartPhone() = delete;
    SmartPhone(std::string m, double w) : model(m), weight(w)
        {   }
    const std::string& get_model() const // возвращает поле model
        { return model; }
    double get_weight() const // возвращает поле weight
        { return weight; }
};

class IPhone : public SmartPhone {
private:
    int memory_volume {0};
    int display_size {0};
public:
    IPhone(std::string m, double w, int mv, int ds) : SmartPhone(m, w), memory_volume(mv), display_size(ds)
        {   }
    void get_info(int& memory, int& size) // возвращает значения полей memory_volume и display_size
    {
        memory = memory_volume;
        size = display_size;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    IPhone iPhone12("iPhone12", 0.17, 64000, 11); // порядок: model, weight, memory_volume, display_size
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}