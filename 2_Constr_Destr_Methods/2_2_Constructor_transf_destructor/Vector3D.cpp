#include <iostream>
#include <string.h>
#include <cstdlib>

class Vector3D {
    int x, y, z;
public:
    Vector3D(const char* str)   // по умолчанию
    {
        if(atoi(str)){
            x = atoi(str);
        } else 
            x = 0;

        str = strchr(str, ' ');
        if(str){
            str++;
            y = atoi(str);
        } else
            y = 0;

        str = strchr(str, ' ');
        if(str){
            str++;
            z = atoi(str);
        } else
            z = 0;

        std::cout << "x = " << x << " , y = " << y << " , z = " << z << std::endl;    
    }

    Vector3D(int* ar)  // перегруженный
    {
        x = ar[0];
        y = ar[1];
        z = ar[2];
        
        std::cout << "x = " << x << " , y = " << y << " , z = " << z << std::endl;
    }
    void get_coords(int& a, int& b, int& c) 
        { a = x; b = y; c = z; }
};

int main()
{
    Vector3D v1 = "1 2 -5";             // x=1, y=2, z=-5
    Vector3D v2 = "1.5 2.2 -5.7";       // x=1, y=2, z=-5
    Vector3D v3 = "1.5 2.2 -5.7 data";  // x=1, y=2, z=-5

    int coords_1[] = {2, 4, 7}, coords_2[] = {5, 3, 1, 0, 20};
    Vector3D v4 = coords_1; // x=2, y=4, z=7
    Vector3D v5 = coords_2; // x=5, y=3, z=1

    return 0;
}