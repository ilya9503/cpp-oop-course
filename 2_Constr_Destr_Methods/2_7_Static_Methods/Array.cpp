#include <iostream>

class Array {
    double* data {nullptr};
    size_t size {0};
    Array() = default;
public:
    Array(const Array&) = delete;
    ~Array()
        { delete [] data; }
    void set_data(double* d, size_t length)
    {
        delete[] data;
        size = length;
        data = new double[size];

        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }
    double* get_data() { return data; }
    size_t get_size() { return size; }
    // создает объект ar, содержащий массив (поле data) длиной length элементов с нулевыми значениями
    static Array* create(size_t length)             
    {
        double d[length]{0};
        Array* ar = new Array();
        ar->set_data(d, length);
        return ar;
    }
    // создает объект ar, содержащий массив со значениями массива data (тип double) и длиной переданного массива data
    static Array* create(double* d, size_t length)  
    {
        Array* ar = new Array();
        ar->set_data(d, length);
        return ar;
    }
};

int main()
{
    Array* ar = Array::create(100);
    double data[5]{1.1, 2.2, 3.3, 4.4, 5.5};
    Array* ar_1 = Array::create(data, std::size(data));

    delete ar;
    delete ar_1;
    
    return 0;
}