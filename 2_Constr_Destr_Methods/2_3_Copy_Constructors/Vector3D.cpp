#include <iostream>

#define MIN     -100
#define MAX      100

// здесь объявляйте класс
class Vector3D {
    int x, y, z;
public:
    // Конструкторы
    Vector3D() : x(0), y(0), z(0)
        {   }
    Vector3D(int a) : x(a), y(0), z(0)
        {   }
    Vector3D(int a, int b, int c) : x(a), y(b), z(c)
        {   }

    void set_coords(int a, int b, int c) // заносит в поля x, y, z значения a, b, c
    {
        if (a >= MIN && a <= MAX &&
            b >= MIN && b <= MAX &&
            c >= MIN && c <= MAX)
        {
            x = a;
            y = b;
            z = c;
        }
        //std::cout << x << " " << y << " " << z << std::endl;
    }
    void get_coords(int& x, int& y, int& z) // возвращает (через ссылки) значения координат
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    //Vector3D v; // x=0, y=0, z=0
    //Vector3D v1 = 5; // x=5, y=0, z=0
    //Vector3D v2(1, 2, 3); // x=1, y=2, z=3
    Vector3D* ptr_v1 = new Vector3D(10, -5, 7);
    Vector3D* ptr_v2 = new Vector3D(0, 12, -56);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_v1;
    delete ptr_v2;

    return 0;
}