#include <iostream>

// здесь объявляйте классы
class Wallet {
    const std::string exception_msg{"Value is out of bounds."};   // сообщение при исключении
    enum {wallet_limit = 1000000};                          // лимит денег в кошельке
    long volume {0};                                        // количество денег в кошельке
public:
    Wallet(long v=0) : volume(v)    // конструктор преобразования (если не нужен, используем explicit)
    {
        if(v < 0 || v > wallet_limit)
            throw exception_msg;
    }

    long get_volume() const // возвращает значение поля volume
        { return volume; }
    const std::string& get_msg() const
        { return exception_msg; }
    int get_limit() const
        { return wallet_limit; }

    const Wallet& operator+=(int x)
    {
        if((this->volume + x) > wallet_limit)
            throw exception_msg;

        this->volume += x;
        return *this;
    }

    const Wallet& operator-=(int x)
    {
        if((this->volume - x) < 0)
            throw exception_msg;
            
        this->volume -= x;
        return *this;
    }

    Wallet operator+(const Wallet& right)
    {
        if((this->volume + right.volume) > wallet_limit)
            throw exception_msg;

        return Wallet(this->volume + right.volume);
    }

    Wallet operator+(const long right)
    {
        if((this->volume + right) > wallet_limit)
            throw exception_msg;

        return Wallet(this->volume + right);
    }

    friend Wallet operator+(const long left, const Wallet& right);

    const Wallet& operator=(const Wallet& right)
    {
        if(this == &right)
            return *this;

        this->volume = right.volume;
        return *this;
    }

    const Wallet& operator=(int x)
    {
        if(x < 0 || x > wallet_limit)
            throw exception_msg;

        this->volume = x;
        return *this;
    }    
};

Wallet operator+(const long left, const Wallet& right)
{
    if((left + right.get_volume()) > right.get_limit())
        throw right.get_msg();

    return Wallet(left + right.get_volume());
}

int main()
{
    // здесь продолжайте функцию main
    try {
        Wallet wl(500);
    }
    catch(const std::string& exc) {
        std::cout << exc << std::endl;
    }

    Wallet w;
    w = 500;
    w += 100; // volume = 600
    w -= 10; // volume = 590
    std::cout << w.get_volume() << std::endl;

    Wallet w2(100);

    Wallet res = w + w2;
    res = 10 + w;           // 600
    res = w2 + 5;           // 105
    res = 100 + 600;        // 700
    std::cout << res.get_volume() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}