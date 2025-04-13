#include <iostream>

class Vector {
public:
    int x {-1}, y {-1};
public:
    Vector() : x(0), y(0) { }
    Vector(int a = 0, int b = 0) : x(a), y(b) { }
};

int main()
{
    Vector v, v2(1, 2);
    std::cout << v2.x << " " << v2.y << std::endl;

    return 0;
}