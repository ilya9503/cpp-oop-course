#include <iostream>
#include <iterator>  // Needed for std::size()

class Array {
    int* data {nullptr};
    size_t size {0};
public:
    // Конструкторы
    Array() = default;  // добавить выделение памяти   
    Array(int* d, size_t s) : size(s)
    {
        data = new int[s]{0};
        for(int i = 0; i < s; ++i)
            data[i] = d[i];
    }
    ~Array()
        { delete[] data; }

    // Переопределение оператора +
    Array operator+(const Array& right)
    {
        // объединение значений массивов data (по порядку) в единый массив; size - итоговая длина результирующего массива data
        // нужно возвращать новый объект!
        size_t temp_size = this->size + right.size;
        int temp_ar[temp_size]{0};
        for(int i = 0; i < this->size; ++i)
            temp_ar[i] = this->data[i];
        int j = 0;
        for(int i = this->size; i < temp_size; ++i)
            temp_ar[i] = right.data[j++];

        Array res(temp_ar, temp_size);
        return res;
    }

    // Переопределение оператора =
    const Array& operator=(const Array& right)
    {
        if(this == &right) // присваивание объекта самому себе
            return right;
        this->set_data(right.data, right.size);
        return *this;        
    }

    void print_ar()
    {
        for(int i = 0; i < this->size; ++i)
            std::cout << this->data[i] << ' ';
        std::cout << std::endl;
    }

    void set_data(int* d, size_t length)
    {
        delete[] data;
        size = length;
        data = new int[size];

        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    int* get_data() { return data; }
    size_t get_size() const { return size; }
};

int main()
{
    int d1[5]{1,2,3,4,5};
    int d2[5]{6,7,8,9,10};
    int d3[5]{11,12,13,14,15};

    Array ar1(d1, sizeof(d1)/sizeof(*d1)), ar2(d2, sizeof(d2)/sizeof(*d2));
    Array ar3(d3, sizeof(d3)/sizeof(*d3)); // в массив data копируются данные из массива d; поле size = std::size(d)

    Array res_1;
    res_1 = ar1 + ar2;
    res_1.print_ar();
    //res_1 = ar1 + ar2; // объединение значений массивов data (по порядку) в единый массив; size - итоговая длина результирующего массива data
    
    Array res_2 = ar1 + ar2 + ar3;
    res_2.print_ar();

    return 0;
}