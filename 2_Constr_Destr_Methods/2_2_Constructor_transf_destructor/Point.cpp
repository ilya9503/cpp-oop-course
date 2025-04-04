#include <iostream>
#include <string.h>
#include <cstdlib>

class Point {
    int x, y;
public:
    Point(const char* str)
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

        std::cout << "p.x = " << x << " , p.y = " << y << std::endl;    
    }
    int get_x() { return x; }
    int get_y() { return y; }
};

int main()
{
    Point p1 = "10 5"; // x=10, y=5
    Point p2 = "-8.7 2.3"; // x=-8, y=2
    Point p3 = "14.2 -5.8 point data"; // x=14, y=-5
    Point p_1 = "ab8 2.3"; // x=0, y=2
    Point p_2 = "ab8 2cd"; // x=0, y=2 (cd отбрасывается)

    return 0;
}