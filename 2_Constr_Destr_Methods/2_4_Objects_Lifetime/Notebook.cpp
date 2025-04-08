#include <iostream>

// здесь объявляйте класс
class Notebook {
    std::string model;          // модель ноутбука
    std::string cpu_model;      // модель CPU
    unsigned memory {0};        // объем оперативной памяти (в Мб)
    unsigned disk_volume {0};   // объем дискового пространства (в ГГб)
public:
    // Конструкторы
//    Notebook(std::string model)
//    : model(""), cpu_model(""), memory(0), disk_volume(0)
//        {   }
    Notebook(std::string m="", std::string cpu_m="", unsigned mem=0, unsigned disk_v=0)
    {
        this->model = m;
        this->cpu_model = cpu_m;
        this->memory = mem;
        this->disk_volume = disk_v;
    }
    Notebook(const char* m)
    : model(""), cpu_model(""), memory(0), disk_volume(0)
    {
        model = m;
    }

    // Методы
    void set_data(const std::string& model, const std::string& cpu, unsigned memory, unsigned disk) // сохранение в соответствующих полях переданных значений
    {
        this->model = model;
        this->cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk;
    }
    std::string& get_model() // возврат значения поля model
        { return model; }
    std::string& get_cpu() // возврат значения поля cpu_model
        { return cpu_model; }
    void get_info(unsigned& memory, unsigned& disk_volume) // получение данных полей memory и disk_volume
    {
        memory = this->memory;
        disk_volume = this->disk_volume;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
//    Notebook note("HP", "Core i7", 16000, 512);
    Notebook note = "HP";
    std::cout << note.get_cpu() << " " << " " << note.get_model() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}