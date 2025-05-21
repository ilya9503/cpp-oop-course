#include <iostream>
#include <string>

class Person {
protected:
    std::string fio;
    short old {0};
public:
    Person(const std::string& fio, short old) : fio(fio), old(old)
        { }
    virtual ~Person() { }
    const std::string& get_fio() const { return fio; }
    short get_old() const { return old; }       
};

class IntegerArray {
public:
    enum {max_array_size = 100};
protected:
    int data_array [max_array_size] {0}; // массив целых чисел
    int length_array {0}; // длина массива
public:
    IntegerArray() = default;
    IntegerArray(int* d, int size)
    {
        length_array = (size > max_array_size) ? max_array_size : size;
        for(int i = 0;i < length_array; ++i)
            data_array[i] = d[i];
    }
    virtual ~IntegerArray() { }

    int* get_data() { return data_array; }
    int get_length() const { return length_array; }
};

class Student : public Person, public IntegerArray {
  std::string group;
public:
  Student(std::string name, short age) : Person(name, age), IntegerArray()
  {  }
  Student(std::string name, short age, int* ar, size_t ar_sz) : Person(name, age), IntegerArray(ar, ar_sz)
  {  }
  void set_group(const std::string& group)
  { this->group = group; }  // задает значение поля group
  const std::string& get_group() const
  { return group; }// возвращает значение поля group
};

int main(void)
{
    // здесь продолжайте функцию main
    int ar[] {5, 4, 3, 4, 5};
    Student* ptr_st = new Student("Евстигнеев А.Б.", 23, ar, std::size(ar));
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_st;

    return 0;
}