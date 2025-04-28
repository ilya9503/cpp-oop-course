#include <iostream>
#include <cmath>

class Vector3D {
    int x {0}, y {0}, z {0};
    int error_index;    // В случае ошибки, запишет значение в эту ячейку
public:
    Vector3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c)
        { }
        
    int& operator[](int x)  // переопределяем операцию индексирования класса Vector3D[x];
    {
        if(x == 0) return this->x;
        else if(x == 1) return this->y;
        else if(x == 2) return this->z;
        else return error_index;      
    }

    operator double() const  // переопределяем операцию преобразования типа Vector3D[x];
    {
        return sqrt((double)(x*x + y*y + z*z));
    }

    void set_data(int a, int b, int c) { x = a; y = b; z = c; }
};

int main()
{
    Vector3D v1, v2(1, 2, 3);
    v1[0] = 5; // x = 5
    v1[1] = 6; // y = 6
    v1[2] = 7; // z = 7
    int a = v1[1]; // a = y; при v1[0] возвращается x, при v1[2] возвращается z
    double dist = v2; // возвращается евклидово расстояние радиус-вектора v2

    return 0;
}