#include <iostream>
#include <string>

struct PhoneBookItem {
    std::string fio; // ФИО контакта
    std::string phone_number; // номер телефона

    PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number)
        : fio(fio), phone_number(phone_number)
        { }
};

class PhoneBook {
    enum { max_phone_book = 100 }; // максимальная емкость телефонной книжки
    PhoneBookItem* phone_book {nullptr}; // массив из записей
    size_t count {0}; // количество записей в телефонной книжке
public:
    // Конструкторы
    PhoneBook()
    {
        phone_book = new PhoneBookItem[max_phone_book];
    }
    PhoneBook(PhoneBookItem* lst, size_t size)
    {
        count = (size > max_phone_book) ? max_phone_book : size;

        phone_book = new PhoneBookItem[max_phone_book];
        for(int i = 0;i < count; ++i)
            phone_book[i] = lst[i];
    }
    ~PhoneBook() { delete[] phone_book; }
    // Методы
    const PhoneBookItem* get_phone_book() const // возвращает массив phone_book
        { return phone_book; }
    size_t get_count() const // возвращает значение поля count
        { return count; }
    /*
        который бы добавлял в конец записной книжки (массив phone_book) переданный контакт item.
        Если контакт добавляется успешно, то метод append должен возвращать булево значение true, а иначе - false.
        При успешном добавлении не забудьте увеличить счетчик count на единицу.
    */
    bool append(const PhoneBookItem& item)
    {
        if(count > max_phone_book)
            return false;
        phone_book[count] = item;
        ++count;
        return true;
    }
    PhoneBook operator+(const PhoneBookItem& right)
    {
        PhoneBook temp(this->phone_book, this->count);
        temp.append(right);
        return temp;
    }
    const PhoneBook& operator=(const PhoneBook& right)
    {
        if(this == &right) // присваивание объекта самому себе
            return right;

        count = right.count;
        delete[] phone_book;
        count = (right.count > max_phone_book) ? max_phone_book : right.count;

        phone_book = new PhoneBookItem[max_phone_book];
        for(int i = 0;i < count; ++i)
            phone_book[i] = right.phone_book[i];

        return *this;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    /*
        Переопределите в классе PhoneBook операции присваивания и сложения для реализации следующей логики команд
        В объекте ph2 должен создаваться свой массив phone_book с поэлементным копированием в него значений из аналогичного массива объекта ph.
    */
    //PhoneBook ph;   // справочник
    //PhoneBookItem it("Sergey", "+79041704034"); // запись
    //ph = ph + it; // добавляет в конец записной книжки контакт it, если не превышено максимальное значение записей max_phone_book
    //PhoneBook ph2;
    //ph2 = ph; // копирование телефонной книжки
    PhoneBook phone_lst;
    PhoneBookItem it_1("А. Дзюба", "+71237694401");
    PhoneBookItem it_2("П. Гагарина", "+79234694105");
    PhoneBookItem it_3("О. Бузова", "+79041563055");
    PhoneBookItem it_4("Тимати", "+79121000000");
    phone_lst.append(it_1);
    phone_lst.append(it_2);
    phone_lst.append(it_3);
    phone_lst.append(it_4);

    const PhoneBookItem* list = phone_lst.get_phone_book();
    std::cout << phone_lst.get_count() << " 4-ая запись: " << list[3].fio << " " << list[3].phone_number << std::endl;
    

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память

    return 0;
}