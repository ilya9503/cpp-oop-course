#include <iostream>

class PointND {
    short* coords {nullptr};    // координаты точки
    size_t dims {0};            // число координат
    short error_index{0};
public:
	PointND() = default;
    PointND(short* cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for(size_t i = 0;i < dims; ++i)
            coords[i] = cds[i];
    }
    ~PointND() { delete[] coords; }

    short& operator[](int x)
    {
        if(x >= dims) return error_index;
        return coords[x];
    }

    const PointND& operator=(const PointND& right)
    {
        if(this == &right) return right;
        //PointND temp(right.coords, right.dims);
        delete [] this->coords;
        this->coords = new short[right.dims];
        this->dims = right.dims;
        for(int i = 0; i < this->dims; ++i)
            this->coords[i] = right.coords[i];
        return *this;
    }
};

int main()
{
    short coords[] = {1, 2, 3, 4, 5};
    short coords_1[] = {6, 7, 8, 9, 10};
    int indx{4};
    PointND pt(coords, std::size(coords));
    PointND pt1(coords_1, std::size(coords_1));

    int val = pt[indx]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
    pt[indx] = val;     // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
    PointND pt2;
    pt2 = pt1;          // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)

    return 0;
}