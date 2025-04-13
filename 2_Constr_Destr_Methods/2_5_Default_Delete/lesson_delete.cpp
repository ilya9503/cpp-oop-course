/*
    Ключевые слова default, delete
    При желании мы можем явно отказаться от использования в классе того или иного стандартного конструктора.
    Для этого, начиная со стандарта C++11, вводится ключевое слово delete

    Сокрытие конструкторов - определение конструкторов в приватной секции
    Используя секцию private, мы можем управлять возможностью создания и копирования объектов определенного класса
*/

#include <iostream>

class Vector {
    int x {0};
    int y {0};
    Vector(const Vector& other) = default;  // можно инициализировать объектами класса только через публичный метод
public:
    Vector() = delete;                      // компилятор откажется от использования конструктора по умолчанию
    Vector() = default;                     // компилятор будет использовать конструктор по умолчанию
    Vector(const Vector& other) = delete;   // компилятор откажется от использования и конструктора копирования и конструктора по умолчанию
};

int main()
{
    Vector v1;      // конструктор по умолчанию
    Vector v2(v1);  // конструктор копирования
    Vector v3;
    v3 = v1;        // операция присваивания копированием

    return 0;
}