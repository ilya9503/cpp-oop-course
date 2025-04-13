/*
    Паттерн Singleton (синглтон)
    пример использования статических переменных и методов класса
    Смысл этого паттерна прост. Объявляется класс, так, чтобы от него мог существовать ровно один объект в один момент времени

    Указатель instance_ptr является статическим тк
        не должен относиться к самим объектам класса (лишь ссылаться на один, при его наличии)
        и быть определенным в области видимости класса, так как непосредственно связан с логикой паттерна Singleton.
*/

#include <iostream>

class Singleton {
    int data {0};
    static Singleton* instance_ptr;
    Singleton() = default;
public:
    Singleton(const Singleton&) = delete;
    ~Singleton()
        { instance_ptr = nullptr; } // для того, чтобы в можно было создать только один объект
    static Singleton* get_instance()
    {
        // Если статическое поле instance_ptr равно nullptr, значит, ни одного объекта класса не существует, и он создается
        if(instance_ptr == nullptr) {
            instance_ptr = new Singleton();
        }
        return instance_ptr;
    }

    void set_data(int d) {data = d;}    // записываем данные
    int get_data() { return data; }     // читаем данные
};

Singleton* Singleton::instance_ptr = nullptr;   // класс не имеет ни одного объекта

int main()
{
    Singleton* ptr = Singleton::get_instance();     // вызываем метод без привязки к объекту (static) 
    Singleton* ptr2 = Singleton::get_instance();

    std::cout << ptr << std::endl;      // ссылаются на один и тот же объект
    std::cout << ptr2 << std::endl;

    delete ptr;
    ptr = nullptr;
    //delete ptr2;

    return 0;
}