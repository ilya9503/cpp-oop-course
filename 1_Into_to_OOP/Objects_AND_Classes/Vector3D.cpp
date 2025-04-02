#include <iostream>
enum {min=-100, max=100};

// здесь объявляйте класс
class Vector3D {
    int x, y, z; // координаты в трехмерном пространстве
public:
    // заносит в поля x, y, z значения a, b, c
    void set_coords(int a, int b, int c)
    {
        x = (a <= max && a >= min) ? a : x;
        y = (b <= max && b >= min) ? b : y;
        z = (c <= max && c >= min) ? c : z;
    }
    // возвращает (через ссылки) значения координат
    void get_coords(int& x, int& y, int& z)
    {
        x = this->x;
        y = this->y;
        z = this->z; 
    } 
};


int main(void)
{
    // здесь продолжайте функцию main
    Vector3D* ptr_v1 = new Vector3D;
    Vector3D* ptr_v2 = new Vector3D;
    ptr_v1->set_coords(10, -5, 7);
    ptr_v2->set_coords(0, 12, -56);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_v1;
    ptr_v1 = nullptr;
    delete ptr_v2;
    ptr_v2 = nullptr;

    return 0;
}