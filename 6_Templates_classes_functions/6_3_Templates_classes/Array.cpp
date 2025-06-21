#include <iostream>

template <typename T=int>
class Array {
    T* data {nullptr};
    size_t size {0};
public:
    Array() = default;
    Array(T* d, size_t size) : size(size)
    {
        // создание массива data и копирование в него значений из массива d
        data = new T[size];
        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }
    Array(const Array& other)
    {
    	// конструктор копирования
        size = other.size;
        data = new T[size];
        for(size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~Array() { delete[] data; }

    Array operator+(const Array& right)
    {
        // здесь реализация операции объединения массивов data и сохранение результата в объекте array_obj
        // сначала должны идти значения массива this->data, а затем, массива right.data
        Array array_obj;
        array_obj.size = size + right.size;
        array_obj.data = new T[array_obj.size];
        for (size_t i = 0; i < size; ++i)
            array_obj.data[i] = data[i];

        for (size_t i = 0; i < right.size; ++i)
            array_obj.data[i + size] = right.data[i];
            
        return array_obj;
    }
    const Array& operator=(const Array& right)
    {
        // здесь реализация операции присваивания и сохранение результата в текущем объекте this
        if(this == &right) return *this;

        delete[] data;
        size = right.size;
        data = new T[size];
        for(size_t i = 0; i < size; ++i)
            data[i] = right.data[i];

        return *this;
    }

    const T* get_data() const { return data; }
    size_t get_length() const { return size; }
};