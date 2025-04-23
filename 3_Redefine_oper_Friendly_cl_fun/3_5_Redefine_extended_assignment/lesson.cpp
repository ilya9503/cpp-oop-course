/*
    3.5. Переопределение расширенных операций присваивания
    += -= *= /= %= и тп
*/

#include <iostream>
#include "darray.h"
 
int main()
{
    DArray ar1, ar2;
 
    for(int i = 0; i < 10; ++i)
        ar1.push_back(i+1);

    for(int i = 0; i < 5; ++i)
        ar2.push_back(i+15);

    ar1 += ar2;
    ar1 + ar2;

    // Переопределили операцию индексирования класса DArray с помощью вложенного класса Item
    ar1[25] = 7;
    // Переопределяем операции расширенного присваивания
    ar1[0] += 2;
    ar1[2] = 7;
    ar1[2] *= 3;
    ar1[3] = 11;
    ar1[3] %= 4;
    int v = ar1[9];    // отработает DArray::Item::operator int();

    std::cout << v << std::endl;

    ar2 = ar1;
 
    std::cout << ar2.size() << " " << ar2.capacity_ar() << std::endl;
    
    for(int i = 0;i < ar2.size(); ++i)
        std::cout << ar2.get_data()[i] << " ";
 
    return 0;
}