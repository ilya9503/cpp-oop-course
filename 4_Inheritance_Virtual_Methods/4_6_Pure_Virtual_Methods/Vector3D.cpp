#include <iostream>
#include <cmath>

class Vector3D {
    int x {0}, y {0}, z {0};
    int err{-1};
public:
    Vector3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c)
        { }
    void set_data(int a, int b, int c) { x = a; y = b; z = c; }
    int& operator[](int n)
    {
        switch(n){
            case 0:
               return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                return err;
        }
    }
    operator double()
    {
       return sqrt((double)(x*x + y*y + z*z));
    }
    
};