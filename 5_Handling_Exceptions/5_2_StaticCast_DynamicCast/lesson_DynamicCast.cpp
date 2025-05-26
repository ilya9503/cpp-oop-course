/*
    Оператор dynamic_cast выполняет приведение связанных типов указателей или ссылок подобно операции static_cast,
        но делает это в процессе работы программы.
        
    Нам необходимо определить: относится ли объект th к объекту дочернего класса Ball?
    Так как через параметр можно передать совершенно любой класс, унаследованный от Thing,
        то его принадлежность к классу Ball следует определять в момент выполнения программы.
    На момент компиляции такой определенности мы не имеем. Поэтому следует использовать оператор dynamic_cast для
        динамического приведения типа указателя.

    dynamic_cast работает с классами, в которых должен быть хотябы один виртуальный метод
    оператор dynamic_cast использует механизм RTTI (Run-Time Type Identification)

const_cast              снимает модификатор const (и volatile) для текущего типа данных
reinterpret_cast        преобразование одного типа в другой, с некоторой дополнительной проверкой со стороны компилятора
                        на возможность указанного действия
static_cast             преобразование типов с учетом цепочки наследования классов или структур
dynamic_cast            преобразование типов с учетом цепочки наследования классов или структур в процессе выполнения программы (динамически)

*/

#include <iostream>
#include <memory>   // unique_ptr, shared_ptr умные указатели

class Thing {
public:
    virtual void print() const { }
};
 
class Ball : public Thing {
    int radius;
    int color;
public:
    virtual void print() const override { puts("Ball"); }
    void get_data(int& r, int& c) const { r = radius; c = color; }
};
 
class Mouse : public Thing {
public:
    virtual void print() const override { puts("Mouse"); }
};

class Cart {
public:
    void add_thing(const Thing& th)
    {
        th.print();
 
        const Ball* ptr_ball = dynamic_cast<const Ball *>(&th); // принадлежность th к Ball определяется во время выполнения программы
        // Если th является другим классом, не Ball, то запишется nullptr
        if(ptr_ball) {
            int radius, color;
            ptr_ball->get_data(radius, color);
            puts("th is a Ball");
        }
        else
            puts("th is not a Ball");
    }
};


int main()
{
/*
    Cart cr;
 
    Ball b;
    Mouse m;
 
    cr.add_thing(b);    // передается константная ссылка на базовый класс Thing
    cr.add_thing(m);
*/

    // Операторы static_cast и dynamic_cast с указателями shared_ptr
    // Умные указатели решают проблему утечек памяти и двойного освобождения, часто возникающих при использовании обычных new/delete
    // RAII - Resource Acquisition Is Initialization

    std::shared_ptr<Thing> th{std::make_shared<Thing>()};
 
    std::shared_ptr<Ball> d_bl{std::dynamic_pointer_cast<Ball>(th)};
    std::shared_ptr<Ball> s_bl{std::static_pointer_cast<Ball>(th)};
 
    if(d_bl)
        puts("Ball");
    else
        puts("Not Ball");
 
    return 0;
}