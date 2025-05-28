/*
    Использовать static или const методы для безопасности
    
*/

#include <iostream>

// здесь объявляйте класс
class Vector3D {
    enum {min_coord = -100, max_coord = 100};
    int x{0}, y{0}, z{0};                       // координаты в трехмерном пространстве
public:
    Vector3D(int x=0, int y=0, int z=0)
    {
        if(!check_coords(x) || !check_coords(y) || !check_coords(z))
            throw -2;        

        this->x = x;
        this->y = y;
        this->z = z;
    }

    void get_coords(int& x, int& y, int& z) const      // возвращает значения координат
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    static bool check_coords(int x)                   // проверяем выход за пределы
    {
        return x >= min_coord && x <= max_coord;
    }

    void set_coords(int x, int y, int z)               // задает значения координат
    {
        if(!check_coords(x) || !check_coords(y) || !check_coords(z))
            throw -1;

        this->x = x;
        this->y = y;
        this->z = z;
    }

    int& operator[](int x)
    {
        switch(x) {
            case 0:
                return this->x;
            case 1:
                return this->y;
            case 2:
                return this->z;
            default:
                throw "Incorrect index.";
        }
    }


};


int main(void)
{
    // здесь продолжайте функцию main
    try {
        Vector3D v3(10, 1000, -500);
    }
    catch(const char* exc) {
        std::cout << exc << std::endl;
    }
    catch(int exc) {
        std::cout << exc << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}