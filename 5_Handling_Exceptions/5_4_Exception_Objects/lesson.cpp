/*
    Объект исключения. Вложенные блоки try/catch
    Если передавать объекты исключения копированием, их будет создаваться больше
    Лучше использовать ссылки

    Одиночный комментарий Ctrl + Fn + /
    Многострочный комментарий Shift + Alt + A
*/

#include <iostream>
#include <fstream>

class Exception {
public:
    static int count_create;    // число созданий объектов класса
    static int count_delete;    // число удалений объектов класса
 
    Exception() { count_create++; }
    Exception(const Exception& ) { count_create++; }    // конструктор копирования
    ~Exception() { count_delete++; }
};
 
int Exception::count_create {0};    // инициализация статических переменных за пределами класса
int Exception::count_delete {0};

class FileTry { // покажем, что при срабатывании исключения вызовется деструктор (только в стеке)
    std::ifstream& ifs;
public:
    FileTry(std::ifstream& ifs) : ifs(ifs)
        { }
    ~FileTry()
    {
        std::cout << "FileTry: destructor" << std::endl;
 
        if(ifs.is_open()) {
            ifs.close();
            std::cout << "Close file" << std::endl;
        }
    }
};


void load_data(const char* path, int& x)
{
    std::ifstream ifs;
 
    try {
        FileTry file(ifs);

        ifs.open(path);
        if(!ifs.is_open()) {
            throw Exception();  // выбрасываем пользовательский объект исключения (класс Exception)
        }                       // создается 1-ый объект (1 удаление)

        // Если исключение сработало, функция прерывает работу и вызываются деструкторы объектов, созданных в этой функции
        ifs >> x;
        //ifs.close();
    }
    catch(const Exception& e) {  // создается 2-ый объект (2 удаление)
        //ifs.close();
        throw;                // создается 3-ий объект. Если throw без параметров, то пробросит существующий объект
    }

    // Если исключений нет, то деструкторы вызовутся здесь
}

int perimetr_tr(int a, int b, int c)
{
    try {
        if(a < 0 || b < 0 || c < 0)
            throw -1;
    }
    catch(int x) {
        std::cout << x << std::endl;
        throw;
    }
 
    if(a > b+c || b > a+c || c > a+b)
        throw "Error: a, b, c are not triangle lengths";
 
    return a+b+c;
}

int main()
{
    int data {0};

    try {
        try {
            int res = perimetr_tr(5, 3, 1);
        }
        catch(int e) {
            std::cout << e << std::endl;
        }
    }
    catch(const char* e) {
        std::cout << e << std::endl;
    }

    try {
        load_data("123", data);
        std::cout << data << std::endl;
    }
    catch(const Exception& ex) {     // создается 4-ый объект
        std::cout << Exception::count_create << std::endl;
        std::cout << Exception::count_delete << std::endl;
    }
        // еще 2 удалятся здесь


    return 0;
}