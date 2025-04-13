#include <iostream>

class StringBuffer {
    enum {max_size = 1024}; // р-р строки
    char *buffer {nullptr}; // массив символов
    int size {0};           // длина массива
public:
    // Конструктор
    StringBuffer(const char* str)   // передаем Си-строку
    {
        size = 0;
        while(str[size] != '\0' && size < max_size-1)
            size++; // считаем кол-во символов в строке

        buffer = new char[size+1];      // выделяем память для строки + \0
        for(int i = 0;i < size; ++i)
            buffer[i] = str[i];         // копируем содержимое

        buffer[size] = '\0';            // добавляем \0 для формирования корректной Си-строки
    }
    // Конструктор копирования + делегирования
    StringBuffer(const StringBuffer& other) : StringBuffer(other.buffer)
        { /*std::cout << this->buffer << std::endl;*/  }
    

    // Методы доступа к приватным полям
    const char* get_data() { return buffer; }
    int get_size() { return size; }

    // Деструктор
    ~StringBuffer()
    {
        delete [] buffer;
    }
};

int main()
{
    StringBuffer str("Hello");
    StringBuffer data {str};

    return 0;
}