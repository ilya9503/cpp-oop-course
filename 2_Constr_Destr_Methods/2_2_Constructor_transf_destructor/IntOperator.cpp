#include <iostream>
#include <iterator> // для std::size (до C++20)

class IntOperator {
    int* data {nullptr};    // массив целочисленных значений
    int size {0};           // длина массива (число элементов)
public:
    IntOperator() : data(nullptr), size(0)
        {   }
    IntOperator(int* ar, int sz)
    {
       this->data = ar;
        this->size = sz;
    }

    ~IntOperator()
    {
        for (int i = 0; i < size; ++i)
            data[i] = 0;
    }

    double average()        // вычисление среднего арифметического по массиву data
    {
        return (double)sum() / size;
    }

    int sum()              // вычисление суммы значений массива data
    {
        int sum = 0;
        for(int i = 0; i < size; ++i)
            sum += data[i];

        return sum;
    }

    int max()              // нахождение максимального значения в массиве data
    {
        int max = *data;
        for (int i = 1; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;    
    }

    int min()              // нахождение минимального значения в массиве data
    {
        int min = *data;
        for (int i = 1; i < size; ++i) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;        
    }
};

int main()
{
    int dt[] = {0, -5, 2, 10, 7, 22};

    IntOperator op_1;
    //std::cout << "__cplusplus = " << __cplusplus << std::endl;
    IntOperator op2(dt, std::size()); // std::size() возвращает число элементов массива data (C++17) std::size(dt)

    return 0;
}