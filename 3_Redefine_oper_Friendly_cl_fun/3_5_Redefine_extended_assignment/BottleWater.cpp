#include <iostream>

class BottleWater
{
    enum {max_volume = 640};    // максимальный объем воды
    enum type_assign {
        iadd_operator, isub_operator, imul_operator, idiv_operator    // константы для выбора операции: +=, -=, *=, /=
    };
    short volume {0};           // объем воды в бутылке
public:
    BottleWater(short volume = 0) : volume(volume)
        { }

    short get_volume() const { return volume; }
    short operator+(const BottleWater& right)   // res1 = b1.operator+(b2);
    {
        short sum = volume + right.volume;
        sum = (sum >= 0) ? sum : 0;
        sum = (sum <= max_volume) ? sum : max_volume;
        return sum;
    }
    const BottleWater& operator+=(short v)
    {
        short sum = volume + v;
        volume = (sum <= max_volume) ? sum : max_volume;
        return *this;
    }
    const BottleWater& operator+=(const BottleWater& right)
    {
        short sum = volume + right.volume;
        volume = (sum <= max_volume) ? sum : max_volume;
        return *this;
    }
    const BottleWater& operator-=(short v)
    {
        short sum = volume - v;
        volume = (sum >= 0) ? sum : 0;
        return *this;
    }
    const BottleWater& operator-=(const BottleWater& right)
    {
        short sum = volume - right.volume;
        volume = (sum >= 0) ? sum : 0;
        return *this;
    }
    const BottleWater& operator*=(short v)
    {
        short sum = volume * v;
        volume = (sum <= max_volume) ? sum : max_volume;
        return *this;
    }
    const BottleWater& operator*=(const BottleWater& right)
    {
        short sum = volume * right.volume;
        volume = (sum <= max_volume) ? sum : max_volume;
        return *this;
    }
    const BottleWater& operator/=(short v)
    {
        short sum = volume / v;
        volume = (sum >= 0) ? sum : 0;
        return *this;
    }
    const BottleWater& operator/=(const BottleWater& right)
    {
        short sum = volume / right.volume;
        volume = (sum >= 0) ? sum : 0;
        return *this;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
/*
    BottleWater b1(10), b2(50);
    BottleWater res_1 = b1 + b2; // res_1: volume = 110
    b1 += 100; // volume += 100
    b1 += b2; // b1.volume += b2.volume
    b1 -= 20; // volume -= 20
    b1 *= 2; // volume *= 2
    b1 /= 4; // volume /= 4
    b1 -= b2; // b1.volume -= b2.volume
    b1 *= b2; // b1.volume *= b2.volume
    b1 /= b2; // b1.volume /= b2.volume
*/
    BottleWater bw1(40), bw2(200), res;
    res = bw1 + bw2;    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}