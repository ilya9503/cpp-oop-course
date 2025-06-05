/*
    Операторы преобразования типов языка С++
    
    5.2 Операторы static_cast и dynamic_cast

    static_cast - преобразование типов с учетом цепочки наследования классов или структур

    преобразование от дочернего к базовому классу делается автоматически
    преобразование типов от базового к дочернему нужно делать с помощью static_cast

    Статические операторы преобразования типов (отрабатывают на этапе компиляции)
        const_cast
        reinterpret_cast
        static_cast
    Динамический оператор преобразования типов (отрабатывает в процессе работы программы)
        dynamic_cast
*/

#include <iostream>

int main()
{
    char ch {0};
    short sh {0};
    int i {0};
    double d {0};
 
    char* ptr_ch {&ch};
    short* ptr_sh {&sh};
    int* ptr_i {&i};
    double* ptr_d {&d};
 
    ch = static_cast<char>(sh);
    ch = reinterpret_cast<char>(sh); // ошибка
 
    d = static_cast<double>(i);
    d = reinterpret_cast<double>(i); // ошибка
 
    sh = static_cast<short>(ptr_i);  // ошибка 
    sh = reinterpret_cast<short>(ptr_i);
 
    ptr_d = static_cast<double *>(ptr_ch); // ошибка 
    ptr_d = reinterpret_cast<double *>(ptr_ch);
 
    return 0;
}