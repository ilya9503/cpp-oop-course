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
        data = new int[length]{0};
        size = length;
        for(int i=0; i < length; ++i)
            data[i] = d[i];
    }

    int* get_data()                        // возвращает массив data
        { return data; }
    size_t get_size() const                // возвращает значение поля size
        { return size; }

    int& operator[](int x)
    {
        try {
            if(x >= size)
                throw "Incorrect index.";
        }
        catch(const char* ex) {
            std::cout << ex << std::endl;
        }
        
        return data[x];
    }

};

int main(void)
{
    int d[] = {-5, 3, 10, 11};
    ArrayInt ar1; // пустой массив data
    ArrayInt ar2(d, 4);

    size_t sz = ar1.get_size();
    int* lst = ar1.get_data();
    int _a1 = sz == 0 && lst == nullptr;
    assert(("Объект ArrayInt ar1 содержит неверные данные и/или неверно отработали методы get_size, get_data.", _a1));

    sz = ar2.get_size();
    lst = ar2.get_data();
    _a1 = sz == 4 && lst[0] == -5 && lst[1] == 3 && lst[2] == 10 && lst[3] == 11;
    assert(("Объект ArrayInt ar2(d, 4) содержит неверные данные и/или неверно отработали методы get_size, get_data.", _a1));
    
    int dd[] = {6, 4};
    ar1.set_data(dd, 2);
    
    sz = ar1.get_size();
    lst = ar1.get_data();
    _a1 = sz == 2 && lst[0] == 6 && lst[1] == 4;
    assert(("Неверно отработал метод set_data.", _a1));
    
    int val;
    
    try {
        val = ar1[0];
        assert(("Команда val = ar1[0] вернула неверное значение.", val == 6));

        val = ar1[1];
        assert(("Команда val = ar1[1] вернула неверное значение.", val == 4));
        
        ar2[2] = -5;
        assert(("Неверно отработала команда ar2[2] = -5.", ar2[2] == -5));
    }
    catch(const char* e) {
        assert(("Неверно сгенерировалось исключение при доступе к существующему элементу массива.", 0));
    }
    
    try {
        ar1[-1];
        assert(("Не сгенерировалось исключение при доступе к несуществующему элементу массива ar1[-1].", 0));
    }
    catch(const char* e) {
    }

    try {
        ar2[5];
        assert(("Не сгенерировалось исключение при доступе к несуществующему элементу массива ar2[5].", 0));
    }
    catch(const char* e) {
    }
    
    return 0;
}