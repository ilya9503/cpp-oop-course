/*
    2.6 Описание методов вне класса
    Вынесли реализацию функций в другое место, для лучшей читабельности
*/

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
 
    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
private:
    void set_coords(int* cr, unsigned len);
};

/*--------------------------------------------------------------------------------------------------*/
// Реализация методов класса PointND через раскрытие области видимости
// [тип данных] <имя класса>::<элемент класса>
// Таким образом можно выносить реализацию как публичных, так и ПРИВАТНЫХ методов !!
const PointND& PointND::operator=(const PointND& other)
{
        delete[] coords;
        total = other.total;
        coords = new int[total];
        set_coords(other.coords, total);
 
        return *this;
}

void PointND::set_coords(int* cr, unsigned len)     // описание, а не вызов
{
        for (unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
}

/*--------------------------------------------------------------------------------------------------*/

int main()
{
    // Обращаемся к элементам класса через раскрытие области видимости
    // [тип данных] <имя класса>::<элемент класса>
    return 0;
}