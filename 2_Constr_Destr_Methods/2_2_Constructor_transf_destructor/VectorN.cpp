#include <iostream>

class VectorN {
    int dims {0};                       // размерность вектора (число координат)
    short* coords {nullptr};            // массив с координатами
public:
    VectorN(int d) : dims(d)
    {
        coords = new short[d]{0};          // выделяем память под массив и инициализируем 0
    }

    VectorN(short c1, short c2)
    {
        dims = 2;
        coords = new short[dims] {c1, c2};          // выделяем память под массив
    }

    VectorN(short* ar, int ar_sz)
    {
        coords = new short[ar_sz];              // выделяем память под массив
        dims = ar_sz;
        for(int i = 0; i < ar_sz; ++i)
            coords[i] = ar[i];
    }

    ~VectorN()
    {
        if(coords) {
            std::cout << "delete coords: ";
            for(int i = 0; i < dims-1; ++i) {
                std::cout << coords[i] << " ";
            }
            std::cout << coords[dims-1] << std::endl;
            delete [] coords;
        }  
    }

    const short* get_coords() // возвращает координаты (массив coords)
    {
        return coords;
    }

    int get_dims() // возвращает значение поля dims
    {
        return dims;
    }
};

int main()
{
    short data[] = {4, 2, 10, 0, -5};
    VectorN v1 = 5; // формирование вектора с пятью нулевыми координатами: 0 0 0 0 0
    VectorN v2(1, 2); // формирование вектора с двумя координатами: 1 2
    VectorN v3(data, std::size(data)); // формирование вектора с переданными координатами data

    return 0;
}