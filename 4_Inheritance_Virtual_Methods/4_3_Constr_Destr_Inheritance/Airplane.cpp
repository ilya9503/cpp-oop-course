#include <iostream>
#include <string>

// здесь объявляйте классы
class Airplane {
protected:
    std::string model;
    unsigned max_speed {0};
    int length {0};
public:
    Airplane() = delete;
    Airplane(std::string m, unsigned ms, int len) : model(m), max_speed(ms), length(len)
        {   }
    const std::string& get_model() const // возвращает поле model
        { return model; }
    unsigned get_max_speed() const // возвращает поле max_speed
        { return max_speed; }
    int get_length() const // возвращает поле length
        { return length; }
};

class MS21 : public Airplane {
private:
    std::string drive_model; // модель двигателя
    double weight {0.0}; // вес
public:
    MS21(std::string m, unsigned ms, int len, std::string dm, double w)
    : Airplane(m, ms, len), drive_model(dm), weight(w)
        {   }
    void get_info(std::string& drive, double& weight) const // возвращает значения полей drive_model и weight
    {
        drive = drive_model;
        weight = this->weight;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    MS21 ms21("MS 21", 1000, 212, "PD-14", 11.3); // порядок: model, max_speed, length, drive_model, weight
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}