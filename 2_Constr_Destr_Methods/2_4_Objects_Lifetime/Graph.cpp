#include <iostream>

// здесь объявляйте класс
class Graph {
    double* data {nullptr};     // массив вещественных значений
    int length {0};             // длина массива (число элементов)
public:
    // Конструктор
    Graph(double* d=nullptr, int l=0)
    {
        length = l;
        data = new double [length]; // выделяем память для нового массива data
    }
    // Деструктор
    ~Graph()    
        { delete [] data; }
        
    // Методы
    void set_data(const double* ar, int size)      // передача в массив data значений ar в количестве size (при этом происходит создание нового массива data; прежний data освобождается)
    {
        length = size;                  // обновляем размер массива
        delete [] data;                 // освобождаем предыдущий массив data
        data = new double[length];      // выделяем память для нового массива data
        for(int i = 0; i < length; ++i) // копируем данные в новый массив
            data[i] = ar[i];
    }
    double* get_data()                             // возврат указателя на массив data
        { return data; }
    int get_length()                               // возврат значения переменной length
        { return length; }
};


int main(void)
{
    // здесь продолжайте функцию main
    //Graph* gr = new Graph; // data=nullptr, length=0
    //double d[] = {0.5, 0.7, 0.6, 0.9, 1.2};
    //Graph gr1(d, sizeof(d)/sizeof(*d));
    Graph gr;
    double coords[] = {5, 0.4, 2.7, -3.2};
    gr.set_data(coords, sizeof(coords)/sizeof(*coords));

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}