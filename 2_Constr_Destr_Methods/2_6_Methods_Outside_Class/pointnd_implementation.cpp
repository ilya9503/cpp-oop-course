#include "pointnd_def.h"    // заголовочный файл с объявлением класса PointND

// Реализация методов класса PointND
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