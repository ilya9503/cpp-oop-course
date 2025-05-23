
#include <iostream>

class Object {
protected:
    int x{0}, y{0};
    int speed {0};
public:
    Object(int x = 0, int y = 0, int speed = 0) : x(x), y(y), speed(speed)
        { }
    virtual ~Object() { }

    void set_speed(int speed) { this->speed = speed; }
    int get_speed() const { return speed; }
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class ObjectFly : virtual public Object {
protected:
    int z {0};              // высота полета (3-я координата)
    double angle {0.0};     // направление полета
public:
    ObjectFly() : Object()
        {   }
    ObjectFly(int z1) : Object(), z(z1)
        {   }
    ObjectFly(int z1, double ang) : Object(), z(z1), angle(ang)
        {   }
    virtual ~ObjectFly() {  }

    int get_z() const               // возвращает значение координаты z
        { return z; }
    double get_angle() const        // возвращает значение угла angle
        { return angle; }
    void set_angle(double angle)    // устанавливает значение угла angle
        { this->angle = angle; }
};

class ObjectOperators : virtual public Object {
public:
    ObjectOperators() : Object()
        {   }
    ObjectOperators(int x, int y) : Object(x, y)
        {   }
    ObjectOperators(int x, int y, int speed) : Object(x, y, speed)
        {   }
    virtual ~ObjectOperators()
        {   }

    void operator+=(int delta) // увеличивает значение скорости на delta
    {
        this->speed += delta;
    }
    void operator-=(int delta) // уменьшает значение скорости на delta
    {
        this->speed -= delta;
    }
};

class Plane : public ObjectOperators, public ObjectFly {
public:
    Plane() : Object(), ObjectOperators(), ObjectFly()
        {   }
    Plane(int x, int y, int z) : Object(x, y), ObjectOperators(x, y), ObjectFly(z)
        {   }
};

int main()
{
    Plane pl(20, 43, 100);
    pl.set_speed(10);
    pl += 5;
    std::cout << pl.get_speed() << " x = " << pl.get_x() << " y = " << pl.get_y() << " z = " << pl.get_z() << std::endl;

    return 0;
}