#include <iostream>

class CoordsND {
    enum {max_coords = 10};
    int *coords {nullptr}; // массив значений координат
    int size {0}; // количество координат (не более max_coords)
public:
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
        for(int i = 0; i < size; ++i)
            coords[i] = other.coords[i];
 
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
    int coords[]{1,2,3,4,5};
    int coords_2[]{6,7,8,9,10};
    CoordsND test(coords, std::size(coords));
    CoordsND test_2 = std::move(test);
    test = test_2;
    //CoordsND test_2(coords_2, std::size(coords_2));
    //test_2 = std::move(test);



    return 0;
}