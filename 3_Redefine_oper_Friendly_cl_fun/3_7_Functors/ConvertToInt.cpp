#include <iostream>
#include <string>
#include <cstring>

// здесь объявляйте класс
class ConvertToInt {
    const char* str{nullptr};   // строка (массив символов)
    int number{0};              // результат преобразования в int
public:
    ConvertToInt() = default;
    bool is_error() const
    {
        char temp_ar[strlen(str)+1]{0};
        char* temp = temp_ar;
        strcpy(temp, str);
        // 0-47, 58-255 48-57
        //char key[] = "123456789-+";
        bool flag{false};
        while(*temp != '\0' && !flag) {
            if(!(*temp >= 48 && *temp <= 57 || *temp == 43 || *temp == 45 || *temp == 46))
                    flag = true;
            temp++;
        }
        // int atoi (const char * str);
        // int isdigit ( int c ); ctype.h
        // isdigit is used to check if the first character in str is a digit and therefore a valid candidate to be converted by atoi 
        // into an integer value.
        return flag;
    }
    int operator()(const char* x)
    {
        str = x;
        number = atoi(x);
        return is_error() ? 0 : number;
    }
    const char* get_str() const
        { return str; }
};


int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    // здесь продолжайте функцию main
    ConvertToInt str_to_int;
    int res = str_to_int(str);
    std::cout << res << std::endl;


/*
    ConvertToInt conv_int;

    int res_1 = conv_int("123"); // res_1 = 123
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
    int res_2 = conv_int("a123"); // res_2 = 0 (ошибка конвертации)
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
    int res_3 = conv_int("-123"); // res_3 = -123
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
    int res_4 = conv_int("13b"); // res_4 = 0 (ошибка конвертации)
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
    int res_5 = conv_int("+17"); // res_5 = 17
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
    int res_6 = conv_int("1.7"); // res_6 = 1
    std::cout << conv_int.get_str() << " " << conv_int.is_error() << std::endl;
*/
    

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}