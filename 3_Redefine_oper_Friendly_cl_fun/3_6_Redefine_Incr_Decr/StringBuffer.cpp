#include <cstring>

class StringBuffer {
    enum {max_size = 1024};
    char *buffer {nullptr};
    int size {0};
public:
    StringBuffer(const char* str)
    {
        size = 0;
        while(str[size] != '\0' && size < max_size-1)
            size++;     // определение кол-ва символов в строке без \0, аналог strlen() <cstring>

        buffer = new char[size+1];
        for(int i = 0;i < size; ++i)
            buffer[i] = str[i];

        buffer[size] = '\0';
    }

    StringBuffer(const StringBuffer& other) // Конструктор копирования
    {
        size = other.size;
        buffer = new char[size + 1];
        for(int i = 0; i < size; ++i)
            buffer[i] = other.buffer[i];
        buffer[size] = '\0';
    }

    ~StringBuffer() { delete[] buffer; }

    const char* get_data() const { return buffer; }
    int get_size() const { return size; }

    friend StringBuffer operator+(const char* str, const StringBuffer& other);
    const StringBuffer& operator+=(const char* str)
    {
        size_t str_len = strlen(str);
        size_t new_size = size + str_len;
    
        if (new_size >= max_size)
            new_size = max_size - 1;
        // нужно увеличить длину буфера, тк добавляются новые символы
        char* new_buffer = new char[new_size + 1];
        strcpy(new_buffer, buffer);
        strncat(new_buffer, str, new_size - size);
    
        delete[] buffer;
        buffer = new_buffer;
        size = (int)new_size;
    
        return *this;
    }

};

// Внешняя дружественная функция, а не метод (дает доступ к приватным полям)
StringBuffer operator+(const char* str, const StringBuffer& other)
{
    size_t res_len = strlen(str) + strlen(other.buffer);
    char* res = new char[res_len + 1]{0};
    res = strcat(res, str);
    res = strncat(res, other.buffer, res_len);
    StringBuffer temp(res);
    delete[] res;
    return temp;
}

int main()
{
    StringBuffer str("Hello");
    StringBuffer str2 {str};

    StringBuffer s1 = "World";
    StringBuffer s2 = "Hello, " + s1; // s2: "Hello, World"
    s2 += "!"; // s2: "Hello, World!"


    return 0;
}