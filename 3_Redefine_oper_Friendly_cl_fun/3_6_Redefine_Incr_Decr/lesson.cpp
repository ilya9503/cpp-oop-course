/*
    3.6. Переопределение операций инкремента и декремента в префиксной и постфиксной формах
    ++x, --x, x++, x--
*/

#include <iostream>
#include "darray.h"
 
int main()
{
    DArray ar1, ar2;

    ar1[10] = 10;
    ar1[3] = 5;

    int v1 = ar1[3]--;  // при операции [] возвращается класс DArray::Item
    int v2 = --ar1[10];

    std::cout << v1 << " " << v2 << std::endl;
 
    //std::cout << ar1.size() << " " << ar1.capacity_ar() << std::endl;
    
    for(int i = 0;i < ar1.size(); ++i)
        std::cout << ar1.get_data()[i] << " ";
 
    return 0;
}