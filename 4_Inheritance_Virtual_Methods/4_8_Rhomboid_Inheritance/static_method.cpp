#include <iostream>

// здесь объявляйте класс
class Object {
protected:
    ~Object() = default;
public:
    Object() = default;
    static void remove_object(Object* obj)
        { delete obj; }
};

int main(void)
{
    // здесь продолжайте функцию main
    Object* ptr_obj = new Object();
    Object::remove_object(ptr_obj); // обращаемся через класс, тк static
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}