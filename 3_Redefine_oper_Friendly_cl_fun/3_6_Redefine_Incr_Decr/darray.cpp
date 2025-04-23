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

// Переопределение операции присваивания для класса DArray (this = &other)
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

/*===================================================   Переопределение операции индексации [ ]    ==================================================================================*/
// Определение функции для вложенного класса Item
int DArray::Item::operator=(int right)
{
    if(index >= max_length_array || index < 0)
        return right; // размер массива data не может превышать max_length_array элементов
 
    if(index >= current->capacity) {
        current->_resize_array(index+1);    // увеличим размер динамического массива
    }
 
    for(int i = current->length; i < index; ++i)
        current->data[i] = 0;   // зануляем все новые добавленные значения
 
    if(index >= current->length)
        current->length = index + 1; // новый размер записанных данных
 
    current->data[index] = right;
    return right;
}

DArray::Item::operator int() const 
{
    if(index >= current->length || index < 0)
        return value_error;
 
    return current->data[index];
}

/*===================================================   Переопределение расширенных операций присваивания    ==================================================================================*/
// Метод для избежания дублирования кода
int DArray::Item::_assign_operator(int right, type_assign t)
{
    if(index >= current->length || index < 0)
        return right; // операции +=, -=, *=, /= и т.п. можно выполнять только с записанными элементами массива
 
    switch(t) {
        case iadd_operator: 
            current->data[index] += right;
            break;
        case imul_operator: 
            current->data[index] *= right;
            break;
        case iddiv_operator: 
            current->data[index] %= right;
            break;
        case incr_operator: 
            current->data[index]++;
            break;
        case decr_operator: 
            current->data[index]--;
            break;
    }
    return current->data[index];
}

// Перегрузка _assign_operator() для ++ и --
int DArray::Item::_assign_operator(type_assign t)
{
    if(index >= current->length || index < 0)
        return value_error; // операции +=, -=, *=, /= и т.п. можно выполнять только с записанными элементами массива
 
    switch(t) {
        case incr_operator: 
            current->data[index]++;
            break;
        case decr_operator: 
            current->data[index]--;
            break;
        case incr_p_operator: 
            return current->data[index]++;
        /*
            int value = current->data[index];   // int a = x++; Сначала а=х, затем х=х+1
            current->data[index]++;
            return value;
        */
        case decr_p_operator: 
            return current->data[index]--;
    }
    return current->data[index];
}

// Переопределение оператора +=
int DArray::Item::operator+=(int right)
{
    return _assign_operator(right, iadd_operator);
}

// Переопределение оператора *=
int DArray::Item::operator*=(int right)
{
    return _assign_operator(right, imul_operator);
}

// Переопределение оператора %=
int DArray::Item::operator%=(int right)
{
    return _assign_operator(right, iddiv_operator);
}

// Переопределение оператора ++ префикс
int DArray::Item::operator++()
{
    return _assign_operator(incr_operator);
}

// Переопределение оператора -- префикс
int DArray::Item::operator--()
{
    return _assign_operator(decr_operator);
}

// Переопределение оператора ++ постфикс
int DArray::Item::operator++(int)
{
    return _assign_operator(incr_p_operator);
}

// Переопределение оператора -- постфикс
int DArray::Item::operator--(int)
{
    return _assign_operator(decr_p_operator);
}

// Переопределение оператора += для класса DArray
const DArray& DArray::operator+=(const DArray& other)
{
    int size_new = length + other.length;
    if(size_new > max_length_array)
        size_new = max_length_array;
 
    _resize_array(size_new);
 
    for(int i = length, j = 0; i < size_new; ++i, ++j)
        data[i] = other.data[j];
 
    length = size_new;
    return *this; 
}

// Переопределение оператора + для класса DArray
DArray DArray::operator+(const DArray& other)
{
    int size_new = length + other.length;
    if(size_new > max_length_array)
        size_new = max_length_array;
    DArray temp = *this;
    return temp;   
}

