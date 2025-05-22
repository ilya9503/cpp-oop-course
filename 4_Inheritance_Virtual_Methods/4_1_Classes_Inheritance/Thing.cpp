#include <iostream>
#include <string>

class Thing {
private:
    unsigned id {0};    // идентификатор
protected:
    std::string name;   // название
    int price {0};      // цена
public:
    Thing() = default;
    Thing(std::string n, int p) : name(n), price(p)
        {   }
    void set_data(const std::string& name, int price) // заносит в поля name и price переданные значения
        { this->name = name; this->price = price; }
    unsigned get_id() const // возвращает значение поля id
        { return id; }
    std::string get_name() const // возвращает значение поля name
        { return name; }
    int get_price() const // возвращает значение поля price
        { return price; }
};

class ThingPhisical : public Thing {
private:
    unsigned width {0}, height {0}, depth {0}; // габариты товара
    double weight {0.0}; // вес товара
public:
    ThingPhisical() = default;
    ThingPhisical(std::string n, int pr)
    {
        this->name = n;
        this->price = pr;
    }
    ThingPhisical(std::string n, int pr, unsigned w, unsigned h, unsigned d, double wt)
    : width(w), height(h), depth(d), weight(wt)
    {
        this->name = n;
        this->price = pr;
    }
    void set_dims(unsigned width, unsigned height, unsigned depth) // заносит в поля width, height, depth переданные значения
    {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    void set_weight(double weight) // заносит в поле weight переданное значение
        { this->weight = weight; }
    void get_dims(unsigned& width, unsigned& height, unsigned& depth) const // возвращает габариты товара
    {
        width = this->width;
        height = this->height;
        depth = this->depth;
    }
    double get_weight() const // возвращает вес товара
        { return weight; }
};

class ThingElectro : public Thing {
private:
    unsigned volume {0};                // объем в килобайтах
public:
    ThingElectro() = default;
    ThingElectro(std::string n, int pr)
        { this->name = n; this->price = pr; }
    ThingElectro(std::string n, int pr, unsigned v) : Thing(n, pr), volume(v)
        {  }
    void set_volume(unsigned volume)   // заносит в поле volume переданное значение
        { this->volume = volume; }
    unsigned get_volume() const        // возвращает значение поля volume
        { return volume; }
};


int main()
{
    ThingElectro th3("C++", 500, 120); // name = "Panda", price = 500, volume = 120
    return 0;
}