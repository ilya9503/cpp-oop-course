#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class RandomPassword {
    std::string psw_chars;          // строка из разрешенных в пароле символов
    int min_length{0};              // мин длина пароля
    int max_length{0};             // макс длина пароля
public:
    RandomPassword(std::string psw, int min, int max)
    : psw_chars(psw), min_length(min), max_length(max)
        {   }
    std::string operator()()
    {
        srand(time(NULL));
        int range = max_length - min_length + 1;
        int pass_length = rand() % range + min_length;
        int j{0};
        const char* temp = psw_chars.c_str();
        std::string password;           // сгененрированный пароль
        while(j <= pass_length) {
            password.push_back(temp[rand() % range + min_length]);
            j++;
        }
        return password;
    }
};



int main()
{
    
    RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);
    std::string psw_1 = rnd(); // psw_1: hqt5!v@gk
    std::string psw_2 = rnd(); // psw_2: vmdp&wgs*#qd
    std::cout << psw_1 << " " << psw_2 << std::endl;

    return 0;
}