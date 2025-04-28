#include <iostream>

class BottleWater
{
    enum {max_volume = 320}; // максимальный объем воды
    unsigned volume {0}; // объем воды в бутылке
public:
    BottleWater(unsigned volume = 0) : volume(volume)
        { this->volume = (volume <= max_volume) ? volume : max_volume; }
    BottleWater operator + (const BottleWater& right)
    {
        return BottleWater(this->volume + right.volume);
    }
    /*
    const BottleWater& operator + (const BottleWater& right) const
    {
    }
    */
    unsigned get_volume() const { return volume; }
};

int main(void)
{
    // здесь продолжайте функцию main
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;
    std::cout << res.get_volume();
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}