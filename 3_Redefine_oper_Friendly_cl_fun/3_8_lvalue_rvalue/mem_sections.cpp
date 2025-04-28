/*
    .text       --> код функций
    .rodata     --> константы, строковые литералы
    .data       --> инициализированные глобальные/статические переменные
    .bss        --> неинициализированные глобальные/статические переменные
    heap        --> динамически выделенная память (new, malloc)
    stack       --> локальные переменные и параметры функций
*/

#include <iostream>

int global_initialized = 1;             // .data
int global_uninitialized;               // .bss

const char* message = "Hi!";            // .rodata

int main() {
    int local_var = 5;                  // стек
    int* dynamic_var = new int(10);     // куча
    std::cout << message << std::endl;
    delete dynamic_var;
}