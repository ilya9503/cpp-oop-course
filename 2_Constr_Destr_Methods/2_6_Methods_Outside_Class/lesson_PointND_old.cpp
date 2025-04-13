/*
    2.6 Описание методов вне класса
    Исходный класс - большой объем кода, если будет разрастаться дальше, то станет нечитабельным
*/

class PointND {
    unsigned total{ 0 };
    int* coords{ nullptr };
public:
    PointND() : total(0), coords(nullptr)
    { }
    PointND(unsigned sz) : total(sz)
    {
        coords = new int[total] {0};
    }
    PointND(int* cr, unsigned len) : PointND(len)
    {
        set_coords(cr, len);
    }
    PointND(const PointND& other) : PointND(other.coords, other.total)
    { }
 
    const PointND& operator=(const PointND& other)
    {
        delete[] coords;
        total = other.total;
        coords = new int[total];
        set_coords(other.coords, total);
 
        return *this;
    }
 
    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len)
    {
        for (unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
    }
 
    ~PointND()
    {
        delete[] coords;
    }
};