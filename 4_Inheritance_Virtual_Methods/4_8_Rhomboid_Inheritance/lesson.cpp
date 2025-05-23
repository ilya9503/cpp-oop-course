/*
    4.8 Ромбовидное наследование. Закрытый конструктор и деструктор

    class General -> class GeomBase, class GeomSerialize -> class Line
    Чтобы избежать проблемы общих методов при Ромбовидном наследовании,
        нужно наследовать общий базовый класс виртуально (virtual public General)
    Лучше избегать ромбовидного наследования при проектировании архитектуры программы

    Если требуется использовать ромбовидное наследование, используем
        механизм виртуального наследования

    protected - данные доступны наследникам, но не извне
    private - данные доступны только внутри класса
    public - данные доступны везде

    Если в protected помещаем конструктор - защищаем класс от создания объектов
    Если в protected помещаем деструктор - создавать объекты можно только в куче, в стеке запрещено

*/

#include <iostream>
#include <fstream>

class General { // данный класс используется только для наследования
protected: // защищаем класс от создания объектов
    General()
        { std::cout << "General: constructor" << std::endl; }
public:
    size_t get_size_obj() const { return sizeof(*this); }
};

class GeomSerialize : virtual public General {
protected:
    bool fl_saved {false};
public:
    GeomSerialize()
        { std::cout << "GeomSerialize: constructor" << std::endl; }
    virtual ~GeomSerialize()
        { std::cout << "GeomSerialize: destructor" << std::endl; }

    virtual void save(std::ostream& os) const = 0;
    virtual void load(std::istream& is) = 0;
    //size_t get_size_obj() const { return sizeof(*this); }   // Добавим метод с одинаковой сигнатурой в базовые классы
};

class GeomBase : virtual public General {   // виртуальное наследование класса General
protected:
    int x0{0}, y0{0}, x1{0}, y1{0};
public:
    GeomBase(int a = 0, int b = 0, int c = 0, int d = 0)
        : x0(a), y0(b), x1(c), y1(d)
        { std::cout << "GeomBase: constructor" << std::endl; }
    virtual ~GeomBase()
        { std::cout << "GeomBase: destructor" << std::endl; }
 
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0; this->y0 = y0;
        this->x1 = x1; this->y1 = y1;
    }
 
    virtual void draw() const = 0;

    //size_t get_size_obj() const { return sizeof(*this); }   // Добавим метод с одинаковой сигнатурой в базовые классы
};
 
class Line : public GeomBase, public GeomSerialize {
private:
    double length{0.0};
protected:  // теперь мы можем создавать объекты только с помощью оператора new (в куче, но не в стеке)
    ~Line()
        { std::cout << "Line: destructor" << std::endl; }
public:
    Line(int a = 0, int b = 0, int c = 0, int d = 0) : GeomBase(a, b, c, d)
        { std::cout << "Line: constructor" << std::endl; }

 
    virtual void draw() const
        { printf("Line: %d, %d, %d, %d\n", x0, y0, x1, y1); }

    virtual void save(std::ostream& os) const override
        { os.write((char *)this, sizeof(*this)); }
 
    virtual void load(std::istream& is) override
        { is.read((char *)this, sizeof(*this)); }

    static void delete_object(Line* ptr)
    {
        delete ptr;
    }
};

int main()
{
/*
    Line ln(1, 2, 10, 20);
 
    GeomBase* ptr_b = &ln;
    GeomSerialize* ptr_sz = &ln;
 
    GeomBase& lnk_b = ln;
    GeomSerialize& lnk_sz = ln;

    size_t res = ln.get_size_obj();     // ambiguous, если явно не указывать область видимости ln.GeomBase::get_size_obj()
    std::cout << res << std::endl;
*/

    Line* ptr_ln = new Line(1, 2, 10, 20);
    Line::delete_object(ptr_ln);
    return 0;
 
    return 0;
}