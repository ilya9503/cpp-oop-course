#include <iostream>
#include "pointnd_def.h"    // заголовочный файл с объявлением класса PointND
// для линковщика нужно прописать в settings.json $fileName pointnd_implementation.cpp

// Основная логика программы
int main()
{
    int c[] = {1, 2, 3};
    PointND pt(c, 3);
    
    return 0;
}