#include <iostream>
#include <string>

struct CPU {
    std::string model;  // модель CPU
    double fr;          // тактовая частота (в ГГц)
    CPU(std::string m="", double f=0) : model(m), fr(f)
        {   }
};

struct Memory {
    std::string name;           // наименование
    unsigned long long volume;  // размер памяти (в байтах)
    Memory(std::string n="", unsigned long long v=0) : name(n), volume(v)
        {   }
};

class MotherBoard {
    CPU cpu;
    Memory mems[2];
public:
    MotherBoard(const CPU& cpu, const Memory& mem_1, const Memory& mem_2)
     : cpu(cpu), mems {mem_1, mem_2}
        { }
    CPU& get_cpu() { return cpu; }
    Memory* get_mems() { return mems; }
};

int main(void)
{
    // здесь продолжайте функцию main
    CPU cp("CORE i5", 1.7);
    Memory m1("Samsung", 4000000000);
    Memory m2("Kingston", 8000000000);

    MotherBoard* ptr_mb = new MotherBoard(cp, m1, m2);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_mb;

    return 0;
}