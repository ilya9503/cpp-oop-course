#include <iostream>
#include <string>

struct BankAccount {
    std::string fio; // ФИО счета
    long volume {0}; // объем средств на счете
    // Конструкторы
    BankAccount() = default;
    BankAccount(const std::string& fio, long vol) : fio(fio), volume(vol)
        { }
    // Переопределение операций структуры
    const BankAccount& operator+=(long x)
        { volume += x; return *this; }
    const BankAccount& operator-=(long x)
        { volume -= x; return *this; }
    const BankAccount& operator*=(double x)
        { volume *= x; return *this; }
    const BankAccount& operator/=(long x)
        { volume /= x; return *this; }
    const BankAccount& operator%=(long x)
        { volume %= x; return *this; }
};

class Bank {
    enum { max_accounts = 100 }; // максимальное количество счетов
    BankAccount* acs {nullptr}; // массив из счетов
    size_t count {0}; // текущее количество счетов
public:
    // Конструкторы
    Bank()
    {
        acs = new BankAccount[max_accounts];
    }
    Bank(BankAccount* lst, size_t size)
    {
        count = (size > max_accounts) ? max_accounts : size;

        acs = new BankAccount[max_accounts];
        for(int i = 0;i < count; ++i)
            acs[i] = lst[i];
    }
    ~Bank() { delete[] acs; }

    // Методы класса
    const BankAccount* get_accounts() const // возвращает массив acs
        { return acs; }
    size_t get_count() const // возвращает значение поля count
        { return count; }

    // Переопределение операций класса
    const Bank& operator+=(const BankAccount& other)
    {
        if(count >= max_accounts) return *this;
        acs[count++] = other;
        return *this;
    }
    const Bank& operator+(const BankAccount& other)
    {
        if(count >= max_accounts) return *this;
        acs[count++] = other;
        return *this;
    }
    const Bank& operator=(const Bank& other)
    {
        if(this == &other) return *this;
        delete[] acs;
        acs = new BankAccount[max_accounts];
        for(int i = 0;i < other.count; ++i)
            acs[i] = other.acs[i];

        count = other.count;
        return *this;        
    }    
};

int main(void)
{
    // здесь продолжайте функцию main
/*
    Bank balbank;
    BankAccount ac("Sergey", 4320405);
    balbank += ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    balbank = balbank + ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    ac += 1000; // добавление на счет средств: volume += 1000; fio остается без изменений
    ac -= 1000; // списание со счета средств: volume -= 1000; fio остается без изменений
    ac *= 1.5; // увеличение средств на счете в 1.5 раза с отбрасыванием дробной части: volume *= 1.5; fio остается без изменений
    ac /= 2; // уменьшение средств на счете в 2 раза с отбрасыванием дробной части: volume /= 2; fio остается без изменений
    ac %= 4; // вычисление целого остатка от деления: volume %= 4; fio остается без изменений
    Bank open_b;
    open_b = balbank; // копирование счетов

    В объекте open_b должен создаваться свой массив acs с поэлементным копированием в него значений из аналогичного массива объекта balbank.

    В функции main создайте объект класса Bank в виде переменной с именем my_bank. Добавьте в него следующие счета (по порядку):

    "А. Дзюба", 43056
    "П. Гагарина", 1335395
    "О. Бузова", 0
    "Тимати", -546

    P.S. На экран ничего выводить не нужно.
*/
    Bank my_bank;
    BankAccount ad("А. Дзюба", 43056);
    BankAccount pg("П. Гагарина", 1335395);
    BankAccount ob("О. Бузова", 0);
    BankAccount tm("Тимати", -546);
    my_bank += ad;
    my_bank += pg;
    my_bank += ob;
    my_bank += tm;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}