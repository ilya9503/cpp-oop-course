// здесь объявляйте класс
#include <iostream>

class CoordsND {
    enum {max_coords = 10};
    int *coords {nullptr}; // массив значений координат
    int size {0}; // количество координат (не более max_coords)
public:
    CoordsND() = default;
    CoordsND(int* lst, int sz)
    {
        size = (sz > max_coords) ? max_coords : sz;

        coords = new int[size];
        for(int i = 0;i < size; ++i)
            coords[i] = lst[i];
    }
    CoordsND(const CoordsND& other) : size(other.size)  // конструктор копирования
    {
        coords = new int[other.size];
        for(int i = 0; i < other.size; ++i)
            coords[i] = other.coords[i];        
    }
    CoordsND(CoordsND&& move) noexcept : size(move.size)    // конструктор перемещения
    {
        //std::cout << "CoordsND move constructor" << std::endl;
        coords = move.coords;
        move.coords = nullptr;
    }
    ~CoordsND() { delete[] coords; }

    int* get_coords() { return coords; }
    int get_size() const { return size; }
    CoordsND& operator=(CoordsND&& other)           // присваивание перемещением
    {
        if (this == &other) return *this;
        //std::cout << "CoordsND move assigment" << std::endl;
 
        size = other.size;
        coords = other.coords;
        other.coords = nullptr;

        return *this;
    }

    const CoordsND& operator=(const CoordsND& other)   // переопределение операции присваивания
    {
        if (this == &other) return *this;

        delete[] coords;
        coords = new int[other.size];
        size = other.size;

        for(int i = 0; i < other.size; ++i)
            coords[i] = other.coords[i];
 
        return *this;
    }

};


int main()
{
    // здесь продолжайте функцию main
    int ar[]{-4, 10, 0, 77, 14};
    CoordsND coords{ar, std::size(ar)};
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}