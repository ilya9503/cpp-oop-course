#include <iostream>

// здесь объявляйте класс
class DataThree {
    int data {0};
    static DataThree* instance_ptr;
    static int counter;
    DataThree() = default;
public:
    DataThree(const DataThree&) = delete;
    ~DataThree()
        { instance_ptr = nullptr; }

    static DataThree* get_instance()
    {
        if(instance_ptr == nullptr) {
            instance_ptr = new DataThree();
        }
        return instance_ptr;
    }

    static DataThree* get_new_data()
    {
        if(counter++ < 3) {
            instance_ptr = new DataThree();
        }
        return instance_ptr;
    }

    void set_data(int d) {data = d;}    // записываем данные
    int get_data() { return data; }     // читаем данные
};

DataThree* DataThree::instance_ptr = nullptr;   // класс не имеет ни одного объекта
int DataThree::counter = 0;

int main(void)
{
    // здесь продолжайте функцию main
    DataThree* ptr_dates[5]{nullptr};
    for(int i = 0; i < 5; ++i)
        ptr_dates[i] = DataThree::get_new_data();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    delete ptr_dates[0];
    delete ptr_dates[1];
    delete ptr_dates[2];


    return 0;
}