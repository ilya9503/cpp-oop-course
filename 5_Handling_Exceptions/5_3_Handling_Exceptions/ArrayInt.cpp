/*
    После throw выполнение текущей функции прерывается.
    Если исключение не перехвачено (catch отсутствует), программа завершится с ошибкой.
    Никогда не бросайте const char* — используйте std::exception и его наследников.
*/

#include <iostream>
#include <string>

// здесь объявляйте класс
class ArrayInt {
    int* data {nullptr};                    // массив целых чисел
    size_t size {0};                        // длина массива (число элементов)
public:
    ArrayInt() = default;
    ArrayInt(int* d, size_t length)
    {
        set_data(d, length);
    }
    ~ArrayInt()
        { delete[] data; }

    void set_data(int* d, size_t length)   // создает новый массив data с переданными значениями d в количестве length
    {
        delete[] data;              // освобождаем старую память до выделения новой
        data = new int[length]{0};
        size = length;
        for(int i=0; i < length; ++i)
            data[i] = d[i];
    }

    int* get_data()                        // возвращает массив data
        { return data; }
    size_t get_size() const                // возвращает значение поля size
        { return size; }

    int& operator[](size_t x)                  // проверяем корректность индекса массива
    {
        if(x >= size || x < 0)
            throw "Incorrect index.";       // на этом моменте функция прерывается, не доходя до return
        
        return data[x];
    }

};

int main()
{
    int test_ar[]{1, 2, 3, 4, 5};
    ArrayInt ar(test_ar, sizeof(test_ar)/sizeof(*test_ar));
    int val{0}, val_1{0};
    val = ar[8];
    ar[0] = 22;
    val_1 = ar[0];

    std::cout << val << " " << val_1 << std::endl; 

    return 0;
}

