#include <iostream>

struct Point
{
    short x, y;
};

class PolyLine {
    enum { max_coords = 10 };
    Point coords[max_coords]; // координаты точек полилинии
    int total {0};            // количество точек полилинии
public:
    // конструктор по-умолчанию
    PolyLine() : total(0)
    {
        for (int i = 0; i < max_coords; ++i) {
            coords[i].x = 0;
            coords[i].y = 0;
        } 
    }
    // перегруженный конструктор
    PolyLine(const Point* ar, int size)
    {
        if(size > max_coords)
            total = max_coords;
        else
            total = size;

        for (int i = 0; i < total; ++i)
            coords[i] = ar[i]; 
    }    
    // передача массива координат размером size элементов
    void set_coords(const Point* ar, int size)     
    {
        if(size > max_coords)
            total = max_coords;
        else
            total = size;

        for (int i = 0; i < total; ++i)
            coords[i] = ar[i];
    }
    // добавление в конец массива coords переданной координаты pt
    void append_coord(Point pt)                    
    {
        if(total < max_coords) {
            coords[total] = pt;
            ++total;
        }
    }
    // получение списка координат
    const Point* get_coords()
    {
        return coords;
    }
    // получение значения поля total                     
    int get_total()
    {
        return total;
    }                                
};

// здесь объявляйте класс PolyLine

int main(void)
{
    Point coords[20];
    for(int i = 0;i < 20; ++i) {
        coords[i].x = i+1;
        coords[i].y = i+2;
    }

    // здесь создавайте объекты класса PolyLine
    PolyLine poly(coords, 20);
    PolyLine pl;
    pl.append_coord(coords[19]);
    std::cout << pl.get_coords()->x << " " << pl.get_coords()->y << std::endl;
    std::cout << poly.get_coords()->x << " " << poly.get_coords()->y << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}