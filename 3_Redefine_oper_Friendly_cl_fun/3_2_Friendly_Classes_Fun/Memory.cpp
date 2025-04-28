#include <iostream>

enum type_memory {mem_none = -1, mem_corsair = 1, mem_adata = 2, mem_kingston = 3};

class Memory {
    type_memory type {mem_none}; // тип (производитель) ОЗУ
    unsigned volume; // объем ОЗУ в Мб
public:
    Memory() = default;
    Memory(unsigned v) : volume(v), type(mem_none)
        {}
    Memory(unsigned v, type_memory t) : volume(v), type(t)
        {}
    friend void set_memory_data(Memory& mem, unsigned vol, type_memory tp);         // заносит в поля volume и type объекта mem переданные значения
    friend void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp); // возвращает значение полей volume и type объекта mem
    friend Memory operator+(const Memory& left, const Memory& right);
};

// Дружественные функции для класса Memory
void set_memory_data(Memory& mem, unsigned vol, type_memory tp)
{
    mem.volume = vol;
    mem.type = tp;
}
void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp)
{
    vol = mem.volume;
    tp = mem.type;
}

Memory operator+(const Memory& left, const Memory& right)
{
    if(left.type != right.type)
        return left;
    else
        return Memory(left.volume + right.volume, left.type);
}


int main(void)
{
    // здесь продолжайте функцию main
    Memory mem_1(8000, mem_adata), mem_2(4000, mem_adata);
    Memory res = mem_1 + mem_2;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}