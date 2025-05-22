#include <iostream>
#include <string>

class Thing {
protected:
    std::string name;
    int price {0};
public:
    void set_base_info(const std::string& name, int& price)
    {
        this->name = name; this->price = price;
    }
    void get_base_info(std::string& name, int& price)
    {
        name = this->name; price = this->price;
    }
};

class TV : public Thing {
    int size {0}; double weight {0.0};
public:
    TV(std::string n, int pr, int s, double w) : size(s), weight(w)
        { Thing::name = n; Thing::price = pr; }
    void get_data(std::string& name, int& price, int& size, double& weight)
    {
        name = this->name;
        price = this->price;
        size = this->size;
        weight = this->weight;
    }
};

class Book : public Thing {
    std::string author; int pages {0};
public:
    Book(std::string n, int pr, std::string a, int pg) : author(a), pages(pg)
        { Thing::name = n; Thing::price = pr; }
    void get_data(std::string& name, int& price, std::string& author, int& pages)
    {
        name = this->name;
        price = this->price;
        author = this->author;
        pages = this->pages;        
    }
};

class Store {
    enum {max_total = 100}; // максимальное количество товаров
    Thing* things[max_total] { nullptr }; // товары магазина
    int total {0}; // текущее количество товаров
public:
    //~Store()    // деструктор
    //    { delete[] things; }
    void append(Thing* th); // добавление товара th в конец массива things (хранится указатель на объект)
    Thing* operator[](int index); // возвращает указатель на товар массива things по индексу index; если index неверный, возвращается nullptr
    int get_total() const; // возвращает значение поля total
};

// Внешние реализации методов Store
void Store::append(Thing* th)
{
    things[total++] = th;
}

Thing* Store::operator[](int index)
{
    return (index >= 0 && index <= 100) ? things[index] : nullptr; 
}

int Store::get_total() const
{
    return total;
}

int main(void)
{
    // здесь продолжайте функцию main
    Store st;
    TV t1("Samsung", 54300, 43, 5.4);
    TV t2("Sony", 97000, 80, 7.5);
    Book b("C++", 2000, "Balakirev", 543);
    // Создаем указатели на объекты
    //TV* ptr_t1 = &t1;
    //TV* ptr_t2 = &t2;
    //Book* ptr_b = &b;
    // Добавляем
    st.append(&t1);
    st.append(&b);
    st.append(&t2);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}