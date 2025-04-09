/*
    2.6 Описание методов вне класса
    В этот файл вынесено объявление класса PointND
*/
#ifndef _POINTND_H_     // защита от повторного подключения к одному и тому же модулю
#define _POINTND_H_

class PointND {
    unsigned total{ 0 };
    int* coords{ nullptr };
public:
    PointND() : total(0), coords(nullptr)
        { }
    PointND(unsigned sz) : total(sz)
        { coords = new int[total] {0}; }
    PointND(int* cr, unsigned len) : PointND(len)
        { set_coords(cr, len); }
    PointND(const PointND& other) : PointND(other.coords, other.total)
        { }
    const PointND& operator=(const PointND& other);
 
    ~PointND()
        { delete[] coords; }
 
    unsigned get_total() { return total; }      // inline-функция. Вместо вызова функции подставляется ее тело
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len);
};

#endif