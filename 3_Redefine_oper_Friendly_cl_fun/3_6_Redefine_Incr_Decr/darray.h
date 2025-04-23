#ifndef _DARRAY_H   // защита от повторного включения заголовка #include
#define _DARRAY_H

class DArray {
    enum {
        start_length_array = 8,     // начальная длина массива
        resize_factor = 2,          // множитель для увеличения длины массива
        max_length_array = 30,      // максимальная длина массива
        value_error = 2123456789,   // специальное значение для обозначения ошибки данных
    };

    // Вложенный класс, для реализации операции индексирования динамического массива
    class Item {
        enum type_assign {
            // константы для выбора операции: +=, *=, /=, ++x, --x, х++, х--
            iadd_operator, imul_operator, iddiv_operator, incr_operator, decr_operator, incr_p_operator, decr_p_operator   
        };
        DArray* current {nullptr};  // указатель на объект динамического массива
        int index {-1};             // индекс элемента

        int _assign_operator(int right, type_assign t);
        int _assign_operator(type_assign t);
    public:
        Item(DArray* obj, int idx) : current(obj), index(idx)   // конструктор
            { }
        operator int() const;
        int operator=(int right);
        int operator +=(int right);
        int operator *=(int right);
        int operator %=(int right);
        int operator ++();      // префиксная форма
        int operator --();      // префиксная форма
        int operator ++(int);   // постфиксная форма
        int operator --(int);   // постфиксная форма
    };
 
    int* data {nullptr};                    // сам массив
    int length {0};                         // число записанных в массив значений
    int capacity {0};                       // физический размер массива
 
    void _resize_array(int size_new);       // увеличение размера массива data но не более max_length_array элементов
public:
    // конструктор по-умолчанию
    DArray() : length(0), capacity(start_length_array)
    {
        data = new int[start_length_array];
        capacity = start_length_array;
    }
    // конструктор копирования
    DArray(const DArray& other) : length(other.length), capacity(other.capacity)
    {
        data = new int[capacity];
        for(int i = 0; i < length;++i)
            data[i] = other.data[i];
    }
    // деструктор
    ~DArray() { delete[] data; }    // освобождаем память под массив
 
    int size() const { return length; }
    int capacity_ar() const { return capacity; }
    const int* get_data() const { return data; }
    // переопределение операции присваивания
    const DArray& operator=(const DArray& other);
    // переопределение операции индексирования
    Item operator[](int index)
    {
        return Item(this, index);
    }
    // ar1 += ar2
    const DArray& operator+=(const DArray& other);  // ссылки для того, чтобы избежать копирования массива
    DArray operator+(const DArray& other);  // Тк метод, может принимать только 1 аргумент и this c = a.operator+(b);
    void push_back(int value);
    int pop_back();
};

#endif