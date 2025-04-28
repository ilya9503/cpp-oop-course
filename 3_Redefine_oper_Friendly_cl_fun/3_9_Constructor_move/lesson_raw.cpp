/*
    Если сейчас запустить эту программу (в Visual Studio 2019), то в консоли увидим следующие строчки:
        DArray create - в функции мэин
        DArray create - в функции create_array()
        DArray copy - конструктор копирования
        DArray delete
        DArray assigment
        DArray delete
        DArray delete
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
};

DArray create_array(int size)   // создает массив заданной длины
{
    DArray ar(size);
    return ar;
}

int main()
{
    DArray ard;
    ard = create_array(10);

    return 0;
}