/*
    Конструктор копирования. Делегирующие конструкторы
*/

#include <iostream>

class PointND {
    unsigned total {0};
    int *coords {nullptr};
public:
    PointND() : total(0), coords(nullptr)
        { }

    PointND(unsigned sz) : total(sz)
    {
        coords = new int[total] {0};
    }

    PointND(int* cr, unsigned len) : total(len)
    {
        coords = new int[total];
        set_coords(cr, len);
    }
    // конструктор копирования
    PointND(const PointND& other) : total {other.total}      
    {
        // проинициализировани переменную total текущего объекта, переменной total из объекта other
        // !!! создаем отдельный указатель для массива coords текущего объекта (отличный от coords объекта other)
        // копируем значения массива coords объекта other в текущий объект
        coords = new int[total];    // новая ячейка памяти, остальное инициализируем как у объекта other
        set_coords(other.coords, total);
        std::cout << "Copy constructor" << std::endl;
    }
    // Переопределение оператора присваивания = для объектов PointND
    const PointND& operator=(const PointND& other)
    {
        if(this == &other) return *this; // не присваиваем объект самому себе
 
        delete[] coords;
        total = other.total;
        coords = new int[total];
        set_coords(other.coords, total);
 
        return *this;
    }
    // методы класса 
    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len)
    {
        for(unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
    }
    // деструктор
    ~PointND()
    {
        delete[] coords;
    }
};

int main()
{
    PointND pt(5);
    /*
        Проблема:
            Создается новый объект PointND на основе ранее созданного.
            Объект pt2 будет составлять точную копию объекта pt, т.к. данные из области памяти pt побайтно копируются в область памяти pt2.
            В результате указатель coords этих двух разных объектов будет ссылаться на одну и ту же область памяти
        При уничтожении этих объектов, выделенная память освобождается дважды, что приводит к аварийному завершению программы.

        Для исправления этой ситуации необходимо при копировании объектов дополнительно выделять память для координат нового объекта
        Но где этот алгоритм копирования прописать в классе PointND?
        Как раз для этого предназначен еще один конструктор, который называется конструктор копирования
    */
    PointND pt2{ pt };

    PointND pt3;
    
    pt3 = pt2;      // будет та же ошибка, с двойным освобождением одной и той же области памяти
                    // т.к. конструкторы срабатывают только в момент создания объекта
                    // = скопирует все параметры pt2 в pt3, за исключением выделения памяти
 
    return 0;
}