/*
    🔁 Идиома копирования и обмена (Copy-and-Swap Idiom) в C++
    Это безопасный и простой способ реализовать оператор присваивания (operator=) для классов, которые управляют ресурсами
        (например, динамической памятью).
    💡 Идея: скопировать, потом обменять
    Ты создаёшь временную копию объекта, потом меняешь содержимое текущего объекта с временным, и всё!
        Если что-то пойдёт не так при копировании — твой оригинальный объект не тронут.
*/
#include <iostream>

class PointND {
    short* coords {nullptr}; // координаты точки
    size_t dims {0}; // число координат
    short error{0};
public:
    // Конструкторы
    PointND() = default;
    PointND(short* cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for(size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND(const PointND& other) : PointND(other.coords, other.dims)   // конструктор копирования
        { }
    ~PointND() { delete[] coords; }

    // Методы
    size_t get_dims() const { return dims; }
    short& operator[](int x)
        { return (x < 0 || x > dims-1) ? error : coords[x]; }
    const PointND& operator=(const PointND& other)
    {
        if(this == &other) return *this;

        short* temp = new short[other.dims];
        for(size_t i = 0; i < other.dims; ++i)
            temp[i] = other.coords[i];

        delete[] coords;
        coords = temp;
        dims = other.dims;
        return *this;        
    }
    const PointND& operator++()
    {
        for(size_t i = 0; i < dims; ++i)
            ++coords[i];
        return *this;
    }
    const PointND& operator--()
    {
        for(size_t i = 0; i < dims; ++i)
            --coords[i];
        return *this;
    }
    PointND operator++(int)
    {
        PointND temp = *this;   // нельзя вернуть ссылку на локальную переменную, только через копирование
        for(size_t i = 0; i < dims; ++i)
            ++coords[i];
        return temp;
    }
    PointND operator--(int)
    {
        PointND temp = *this;   // нельзя вернуть ссылку на локальную переменную, только через копирование
        for(size_t i = 0; i < dims; ++i)
            --coords[i];
        return temp;
    }
    const PointND& operator+=(const PointND& other)
    {
        if(dims != other.dims) return *this;
        for(size_t i = 0; i < dims; ++i)
            coords[i] += other.coords[i];
        return *this;
    }
    const PointND& operator-=(const PointND& other)
    {
        if(dims != other.dims) return *this;
        for(int i = 0; i < dims; ++i)
            coords[i] -= other.coords[i];
        return *this;
    }

};

int main()
{
    short coords[] = {1, 2, 3, 4, 5};
    PointND pt(coords, 5);
    int indx{2};
    // Сложение и вычитание координат += и -= выполнять только в том случае, если длины массивов coords объектов равны между собой. 

    int val = pt[indx]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
    pt[indx] = val; // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
    PointND pt2, pt1;
    pt2 = pt1; // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)
    pt2++; // увеличение каждой координаты на 1
    ++pt2; // увеличение каждой координаты на 1
    pt1--; // уменьшение каждой координаты на 1
    --pt1; // уменьшение каждой координаты на 1
    pt += pt2; // к координатам coords объекта pt прибавляются соответствующие координаты объекта pt2
    pt -= pt2; // из координат coords объекта pt вычитаются соответствующие координаты объекта pt2

    return 0;
}