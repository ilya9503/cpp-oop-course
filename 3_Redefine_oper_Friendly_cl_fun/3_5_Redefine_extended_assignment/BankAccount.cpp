#include <iostream>
#include <string>
//#include <windows.h>

//HWND hWnd = GetConsoleWindow();
//HDC hDC = GetDC(hWnd);

// здесь объявляйте класс
class BankAccount {
    std::string fio;        // владелец счета
    long volume_rub {0};    // объем средств в рублях
public:
    BankAccount(const std::string& x) : fio(x)
        {   }
    BankAccount(const std::string& x, long v) : fio(x), volume_rub(v)
        {   }
    const std::string& get_fio() const   // возвращает значение поля fio
        { return fio; }
    long get_volume_rub() const          // возвращает значение поля volume_rub
        { return volume_rub; }

    const BankAccount& operator=(long v)
    {
        volume_rub = v;
        return *this;
    }

    const BankAccount& operator+=(long v)
    {
        volume_rub += v;
        return *this;
    }
    const BankAccount& operator+=(const BankAccount& other)
    {
        volume_rub += other.volume_rub;
        return *this;
    }
    const BankAccount& operator-=(long v)
    {
        volume_rub -= v;
        return *this;
    }
    const BankAccount& operator-=(const BankAccount& other)
    {
        volume_rub -= other.volume_rub;
        return *this;
    }    
};

int main()
{
    BankAccount a1("Balakirev");        // fio = "Balakirev"; volume_rub = 0
    BankAccount a2("Pushkin", 10000);   // fio = "Pushkin"; volume_rub = 10000

    BankAccount a("Старостин"), b("Балакирев"), c("Царев");
    a = 123000; // volume_rub = 123000 (поле fio не меняется)
    b = 12000;
    b += 8000; // volume_rub = 20000 (поле fio не меняется)
    c = 54000;
    c -= 11000; // volume_rub = 43000 (поле fio не меняется)
    a += b; // volume_rub = 123000 + 20000 = 143000 (поле fio не меняется)
    a -= c; // volume_rub = 143000 - 43000 = 100000 (поле fio не меняется)

    return 0;
}