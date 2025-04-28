#include <iostream>
#include <string>

class BankAccount {
    std::string fio; // владелец счета
    long volume_rub {0}; // объем средств в рублях
public:
    BankAccount() = delete;
    BankAccount(const std::string& n)
        { fio = n; }
    BankAccount(const std::string& n, long x)
        { fio = n; volume_rub = x; }
    BankAccount operator=(long x)
    {
        this->volume_rub = x;
        return *this;
    }
    const std::string& get_fio() const // возвращает значение поля fio
        { return fio; }
    long get_volume_rub() const // возвращает значение поля volume_rub
        { return volume_rub; }
};

int main()
{
    BankAccount a1("Balakirev"); // fio = "Balakirev"; volume_rub = 0
    BankAccount a2("Pushkin", 10000); //fio = "Pushkin"; volume_rub = 10000
    a1 = 512000; // volume_rub = 512000 (поле fio не меняется)

    return 0;
}