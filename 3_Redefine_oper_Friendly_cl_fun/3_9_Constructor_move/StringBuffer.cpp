class StringBuffer {
    enum {max_size = 1024};
    char *buffer {nullptr};
    int size {0};
public:
    StringBuffer() = default;
    StringBuffer(const char* str)
    {
        size = 0;
        while(str[size] != '\0' && size < max_size-1)
            size++;

        buffer = new char[size+1];
        for(int i = 0;i < size; ++i)
            buffer[i] = str[i];

        buffer[size] = '\0';
    }
    StringBuffer(const StringBuffer& other) : size(other.size)
    {
        buffer = new char[size+1];
        for(int i = 0;i <= size; ++i)
            buffer[i] = other.buffer[i];
    }
    StringBuffer(StringBuffer&& move) noexcept : size(move.size)
    {
        size = move.size;
        buffer = move.buffer;
        move.buffer = nullptr;
    }
    ~StringBuffer() { delete[] buffer; }

    StringBuffer& operator=(StringBuffer& right) noexcept
    {
        if (this == &right) return *this;
        delete[] buffer;
        size = right.size;

        buffer = new char[size+1];
        for(int i = 0;i <= size; ++i)
            buffer[i] = right.buffer[i];

        return *this;
    }

    StringBuffer& operator=(StringBuffer&& right) noexcept 
    {
        if (this == &right) return *this;
        delete[] buffer;
        size = right.size;
        buffer = right.buffer;
        right.buffer = nullptr;
 
        return *this;
    }

    const char* get_data() { return buffer; }
    int get_size() { return size; }
};