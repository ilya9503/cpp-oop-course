/*
    Делегирование конструкторов
    Если мы внимательно посмотрим на полученный класс PointND, то увидим в нем некоторое дублирование кода в его конструкторах

    В списке инициализации (:) также допускается вызов конструкторов текущего класса.
    Такой подход получил название делегирование конструкторов, а сами конструкторы,
        которые в свою очередь вызывают другие, – делегирующими.
    Благодаря делегированию часто удается сократить дублирование кода при описании классов.
    Поэтому такой подход не редко используется на практике.

*/

#include <iostream>

class PointND {
    unsigned total {0};
    int *coords {nullptr};
public:
    PointND() : total(0), coords(nullptr)
        { }
    PointND(unsigned sz) : total(sz)
    {
        coords = new int[total] {0};
    }
    PointND(int* cr, unsigned len) : PointND(len)   // делегирование
    {
//        coords = new int[total];
        set_coords(cr, len);
    }
    PointND(const PointND& other) : PointND(other.coords, other.total)  // делегирование
    {
//        coords = new int[total];
//        set_coords(other.coords, total);
    }
    // методы класса 
    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len)
    {
        for(unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
    }
    // деструктор
    ~PointND()
    {
        delete[] coords;
    }
};