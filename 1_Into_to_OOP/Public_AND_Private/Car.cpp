#include <iostream>
#include <string>

class Car {
    std::string model;
    int color;
    short width, length, depth;
public:
    void set_data(const Car &car) 
    { 
        model = car.model;
        color = car.color;
        width = car.width; length = car.length; depth = car.depth;
    }

    void set_data(const std::string &model, int color, short width, short length, short depth)
    {
        this->model = model;
        this->color = color;
        this->width = width; this->length = length; this->depth = depth;        
    }
};

int main()
{
    Car my_car, your_car;

    my_car.set_data("BMW", 255, 20, 50, 30);
    your_car.set_data(my_car);

    return 0;
}