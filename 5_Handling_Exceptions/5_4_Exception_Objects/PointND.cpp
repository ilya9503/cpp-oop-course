/*
    Если не добавить (правило 3, правило 5):
        Конструктор копирования
        Оператор перемещения
        Конструктор перемещения
    Возможны утечки памяти или двойное удаление
*/

#include <iostream>

class IndexError {
public:
    IndexError() = default;
};

class PointND {
    double* coords {nullptr}; // координаты точки
    size_t dims {0}; // число координат
public:
    PointND() = default;
    PointND(double* cds, size_t len) : dims(len)
    {
        coords = new double[dims];
        for(size_t i = 0;i < dims; ++i)
            coords[i] = cds[i];
    }
    ~PointND() { delete[] coords; }

    size_t get_dims() const { return dims; }

    double& operator[](size_t x)
    {
        if(x > dims-1 || x < 0)
            throw IndexError();

        return coords[x]; 
    }

    const PointND& operator=(const PointND& right)
    {
        if(coords != nullptr)   // Если память уже выделена, освобождаем
            delete [] coords;

        dims = right.dims;        
        coords = new double[right.dims];

        for(size_t i = 0; i < dims; ++i)
            coords[i] = right.coords[i];

        return *this;
    }

};

int main(void)
{
    // здесь продолжайте функцию main
    double coords[] = {0.1, 0.2, 0.5, -1.4};
    PointND pt(coords, sizeof(coords)/sizeof(*coords));

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}