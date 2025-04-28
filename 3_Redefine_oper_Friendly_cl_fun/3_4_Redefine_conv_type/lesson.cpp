/*
    3.4. Переопределение операции преобразования типа и [ ]. Вложенные классы
*/

#include <iostream>
#include "darray.h"
 
int main()
{
    DArray ar1, ar2;
 
    for(int i = 0;i < 10; ++i)
        ar1.push_back(i+1);
 
    // Переопределили операцию индексирования класса DArray с помощью вложенного класса Item
    /*
        1. В классе DArray отрабатывает Item operator[](int index); Возвращаем объект вложенного класса Item. 
        2. Отрабатывает int operator=(int left);
    */
    ar1[25] = 7;
    int v = ar1[25];    // отработает DArray::Item::operator int();

    std::cout << v << std::endl;

    ar2 = ar1;
 
    std::cout << ar2.size() << " " << ar2.capacity_ar() << std::endl;
    
    for(int i = 0;i < ar2.size(); ++i)
        std::cout << ar2.get_data()[i] << " ";
 
    return 0;
}