/*
    Классы языка C++ содержат еще один специальный метод, называемый деструктор

*/

#include <iostream>

class PointND {                 // точка в многомерном пространстве
    unsigned total {0};         // кол-во измерений
    int *coords {nullptr};      // массив координат точек в пространстве
public:
    PointND() : total(0), coords(nullptr)
        { }
    PointND(unsigned sz) : total(sz)
    {
        coords = new int[total] {0};    // выделяем память в куче
    }
    PointND(int* cr, unsigned len) : total(len)
    {
        coords = new int[total];        // выделяем память в куче
        set_coords(cr, len);
    }
    ~PointND()
    {
        delete [] coords;   // освобождаем память в куче
    }
 
    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len)
    {
        for(unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
    }
};

int main()
{
    PointND pt(5);  // утечка памяти
 
    return 0;
}