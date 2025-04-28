/*
    Добавим конструктор перемещения, чтобы оптимизировать копирование временного
        объекта

    При выборе одного конструктора из множества, компилятор руководствуется правилом пяти:
    при переопределении одного из следующих пяти методов:
        конструктора копирования;
        деструктор;
        операции присваивания;
        конструктора перемещения;
        операции присваивания перемещением
    скорее всего, следует переопределить и четыре остальных.


    Конструктор перемещения (T(T&& other))
    Когда используется:
        Когда создаётся новый объект на основе уже существующего временного (rvalue).
    Например:
        При возвращении объекта из функции (return obj;).
        При инициализации нового объекта с помощью std::move().
    Идея: новый объект захватывает ресурсы старого объекта, старый объект обнуляется.

    Операция присваивания перемещением (T& operator=(T&& other))
    Когда используется:
        Когда уже существующему объекту нужно перекинуть ресурсы от другого объекта.
    Например:
        При obj1 = std::move(obj2);, где obj1 уже существует.
    Идея: Очистить старые ресурсы объекта и перехватить новые.
*/

#include <iostream>

class DArray {              // Упрощенный класс динамического массива
    int *data {nullptr};
    int length {0};
    int capacity {0};
 
public:
    DArray(int size = 0) : length(0), capacity(size)
    {
        std::cout << "DArray create" << std::endl;         
        data = new int[capacity];       
    }
 
    DArray(const DArray& other) : length(other.length), capacity(other.capacity)
    {
        std::cout << "DArray copy" << std::endl;         
        data = new int[capacity];
        for(int i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    // Конструктор перемещения
    DArray(DArray&& move) noexcept : length(move.length), capacity(move.capacity)
    {
        std::cout << "DArray move" << std::endl;
        data = move.data;   // не копируем, а переприсваиваем адрес
        move.data = nullptr;
    }
 
    ~DArray() 
    { 
        std::cout << "DArray delete" << std::endl; 
        delete[] data; 
    }
 
    const DArray& operator=(const DArray& right)
    {
        if(this == &right)
            return *this;
 
        std::cout << "DArray assigment" << std::endl;
 
        length = right.length;
        capacity = right.capacity;
 
        delete[] data;
        data = new int[capacity];
 
        for(int i = 0; i < length; ++i)
            data[i] = right.data[i];
 
        return *this;
    }

    DArray& operator=(DArray&& right) noexcept
    {
        if (this == &right) return *this;
        std::cout << "DArray move assigment" << std::endl;
 
        delete[] data;
        length = right.length;
        capacity = right.capacity;
        data = right.data;
        right.data = nullptr;
 
        return *this;
    }

};

DArray create_array(int size)   // создает массив заданной длины
{
    DArray ar(size);
    return ar;  // сработает конструктор перемещения
}

int main()
{
    DArray ard;
    ard = create_array(10);

    return 0;
}