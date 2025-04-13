#include <iostream>

// здесь объявляйте класс
class Wallet {
    int volume {0};             // объем хранимых средств
    bool check_volume(int x);   // возвращает true, если x >= 0 и false в противном случае
    Wallet() = default;
public:
    Wallet(int v)   :   volume(v)
        {   }
    void add(int vol);          // добавляет к переменной volume значение vol если метод check_volume(vol) вернул true
    int get_volume();           // возвращает значение поля volume
};

// Внешняя реализация методов
bool Wallet::check_volume(int x)
    { return x >= 0; }
void Wallet::add(int vol)
    { if(check_volume(vol)) volume += vol; }
int Wallet::get_volume()
    { return volume; }



int main(void)
{
    // здесь продолжайте функцию main
    Wallet wallet(544653);
    int vl = wallet.get_volume();

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}