#include <iostream>
#include <fstream>

void load_data(const char* path, int& x)
{
    std::ifstream ifs;                      // Input file stream class
    ifs.exceptions( std::ios::failbit );    // для включения генерации исключений
 
    try {
        ifs.open(path);
        ifs >> x;
        ifs.close();
    }
    catch(...) {        // блок отлавливает любые виды исключений
        ifs.close();    // закрываем файл
        throw;          // пробрасываем дальше исключение по стеку вызовов
    }
}

int main()
{
    int data {0};
 
    try {
        load_data("123", data);
        std::cout << data << std::endl;
    }
    catch(const std::exception & ex) {  // обрабатывается исключение, которое выбрасывает файловый поток
        std::cout << "Error read data from file." << std::endl;
    }

    return 0;
}