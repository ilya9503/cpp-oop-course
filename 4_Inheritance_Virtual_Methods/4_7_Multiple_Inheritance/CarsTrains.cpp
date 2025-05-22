#include <iostream>

class PhysicInterface {
public:
    virtual void forward(int speed) = 0;    // движение вперед
    virtual void stop() = 0;                // останов
    virtual void left(double angle) = 0;    // поворот влево
    virtual void right(double angle) = 0;   // поворот вправо

    virtual ~PhysicInterface() { }          // виртуальный, чтобы при удалении дочернего удалился и базовый
};

// здесь объявляйте классы
class Car {
protected:
    int speed {0};          // скорость
    int x {0}, y{0};        // координаты автомобиля (на карте)
    int weight {0};         // вес
    double angle {0.0};     // угол поворота
public:
    Car(int x1, int y1, int w) : x(x1), y(y1), weight(w)
        {   }
    virtual ~Car()  // виртуальный деструктор, потому что класс базовый
        {   }
    void get_coords(int& x, int& y) const  // получение текущих координат
        { x = this->x; y = this->y; }
    int get_speed() const                  // возвращает значение поля speed
        { return speed; }
    int get_weight() const                 // возвращает значение поля weight
        { return weight; }
    double get_angle() const               // возвращает значение поля angle
        { return angle; }
};

class Train {
protected:
    int speed {0};      // скорость
    int x {0}, y{0};    // координаты поезда (на карте)
    int weight {0};     // вес
    double power {0.0}; // мощность
public:
    Train(int x1, int y1, int w, double p) : x(x1), y(y1), weight(w), power(p)
        {   }
    virtual ~Train()
        {   }
    void get_coords(int& x, int& y) const // получение текущих координат
        { x = this->x; y = this->y; }
    int get_speed() const // возвращает значение поля speed
        { return speed; }
    int get_weight() const // возвращает значение поля weight
        { return weight; }
    double get_power() const // возвращает значение поля power
        { return power; }
};

class ModelCar : public Car, public PhysicInterface {
public:
    ModelCar(int x, int y, int w) : Car(x, y, w)
        {   }
    ~ModelCar() = default;
    virtual void forward(int speed) override // заносит значение speed в поле speed
        { Car::speed = speed; }
    virtual void stop() override // устанавливает значение speed равным 0
        { Car::speed = 0; }
    virtual void left(double angle) override // задает значение поля angle равным параметру angle
        { Car::angle = angle; }
    virtual void right(double angle) override // задает значение поля angle равным параметру -angle
        { Car::angle = -angle; }
};

class ModelTrain : public Train, public PhysicInterface {
public:
    ModelTrain(int x, int y, int w, double p) : Train(x, y, w, p)
        {   }
    ~ModelTrain() = default;
    virtual void forward(int speed) override // заносит значение speed в поле speed
        { Train::speed = speed; }
    virtual void stop() override // устанавливает значение speed равным 0
        { Train::speed = 0; }
    virtual void left(double angle) override // задает значение поля angle равным параметру angle
        {  }
    virtual void right(double angle) override // задает значение поля angle равным параметру -angle
        {  }
};

int main(void)
{
    // здесь продолжайте функцию main
    PhysicInterface* obj_lst[] = {
        new ModelCar(0, 0, 1200),
        new ModelTrain(-5, 7, 534200, 574.33),
        new ModelCar(11, 24, 1920),
        new ModelCar(-1, 12, 945)
    };

    for(int i=0; i < std::size(obj_lst); ++i)
        obj_lst[i]->forward(7);
    
    ModelCar* test = static_cast<ModelCar*>(obj_lst[0]);    // преобразуем указатель базового класса к дочернему, чтобы получить доступ к getspeed()
    std::cout << test->get_speed() << std::endl;


    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for(int i=0; i < std::size(obj_lst); ++i)
        delete obj_lst[i];

    return 0;
}