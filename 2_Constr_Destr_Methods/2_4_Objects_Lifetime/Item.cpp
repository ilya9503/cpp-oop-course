#include <iostream>
#include <string>

class Item {
    std::string name;           // название программы
    unsigned short duration;    // длительность в минутах
public:
    Item(std::string n="", unsigned short d=0)
    {
        this->name = n;
        this->duration = d;
    }
    std::string& get_name()        // возвращает значение поля name
        { return name; }
    unsigned short get_duration()  // возвращает значение поля duration
        { return duration; }
};

class TVProg {
    enum {max_length = 100};
    Item items[max_length];     // программы 
    int count {0};              // число программ
public:
    // Конструкторы
    TVProg() : count(0)
        {   }
    TVProg(Item* its, int c) : count(c)
    {
        if(c > max_length) return;
        for(int i = 0; i < count; ++i)
            items[i] = its[i];
    }

    // Методы
    void append(const Item& it)                // добавляет программу it в массив items следующей по списку (в конец списка)
    {
        if((count > max_length) || ((max_length-count) <= 0)) return;
        items[count++] = it;
    }
    void append(const Item* lst, int length)   // добавляет несколько программ в конец из массива lst в массив items
    {
        if((count > max_length) || (max_length-(count+length)) <= 0) return;
        for(int i = 0; i < length; ++i)
            items[(count++)] = lst[i]; 
    }
    Item* get_list()                           // возвращает массив items
        { return items; }
    int get_count()                            // возвращает значение поля count
        { return count; }
};

int main(void)
{
    // здесь продолжайте функцию main
    Item lst[] = {
        {"Новости", 20},
        {"Модный приговор", 50},
        {"Жить здорово!", 60},
        {"Информационный канал", 15},
        {"Новости", 15},
        {"Давай поженимся!", 70}
    };

    TVProg tv;
    tv.append(lst, sizeof(lst) / sizeof(*lst));
    std::cout << tv.get_count() << std::endl;

    //TVProg pr;
    //Item lst1[3] = {{"Доброе утро", 40}, {"Новости", 15}, {"Модный приговор", 60}};
    //TVProg pr1(lst1, 3);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}