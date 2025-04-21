#include "darray.h"

// увеличение размера массива data но не более max_length_array элементов
void DArray::_resize_array(int size_new)       
{
    // Логика создания динамического массива
    if(size_new <= capacity)
        return;
 
    while(capacity < size_new) {
        capacity *= resize_factor;          // увеличиваем в 2 раза до достижения capacity >= size_new
        if(capacity >= max_length_array) {  // проверка превышения макс размера
            capacity = max_length_array;
            break;
        }
    }
 
    int* p = new int[capacity];     // создаем новый увеличенный массив
 
    for(int i = 0;i < length; ++i)  // копируем содержимое предыдущего
        p[i] = data[i];
 
    delete[] data;                  // удаляем предыдущий
    data = p;                       // указатель data ссылается на новый увеличенный массив
}

// Переопределение операции присваивания для класса DArray (this = other)
const DArray& DArray::operator=(const DArray& other)
{
    if(this == &other) // присваивание объекта самому себе
        return other;
 
    length = other.length;
    capacity = other.capacity;
 
    delete[] data;                      // удаляем this->data
    data = new int[capacity];           // создаем новый this->data с длиной other.capacity
    for(int i = 0;i < length; ++i)      // копируем содержимое other.data в this->data
        data[i] = other.data[i];
 
    return *this;
}

// Добавление нового эл-та в конец динамического массива
void DArray::push_back(int value)
{
    // Физической длины массива недостаточно
    if(length >= capacity) {
        _resize_array(capacity * resize_factor);
    }
 
    if(length < capacity)
        data[length++] = value; // записываем зн-е в крайний эл-нт, далее увеличиваем на 1
}

// Удаление в возвращение последнего эл-та динамического массива
int DArray::pop_back()
{
    if(length > 0)
        return data[--length];
    return value_error;
}