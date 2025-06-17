/*
    Режим private при наследовании
*/

#include <string>

class Table {
protected:
    std::string model;
    int color {0};
public:
    void set_name(const std::string& model) { this->model = model; }
};

class RoundTable : private Table {
	short radius {0};
	short height {0};
public:
    RoundTable(const std::string& model, int color, short radius, short height)
        : radius(radius), height(height)
    {
        set_name(model);
        this->color = color;
    }
};

int main()
{
    RoundTable r("President", 0, 1000, 80);
    //Table& t = r;
    //r.set_name("Resident");
    
    return 0;
}