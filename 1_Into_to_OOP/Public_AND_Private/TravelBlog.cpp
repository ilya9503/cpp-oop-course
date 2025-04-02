#include <iostream>
#include <string>

// здесь объявляйте класс
class TravelBlog {
    std::string country;    // страна пребывания
    short days;             // число дней пребывания
public:
    void set_info(const std::string &country, short days) // заносит в соответствующие поля переданные значения
    {
        this->country = country;
        this->days = days;
    }
    void set_info(const TravelBlog& blog) // заносит в соответствующие поля значения из переданного объекта blog
    {
        this->country = blog.country;
        this->days = blog.days;
    }
    const std::string& get_country() // возвращает ссылку на поле country
    {
        return country;
    }
    short get_days() // возвращает значение поля days
    {
        return days;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    TravelBlog blog1, blog2;
    blog1.set_info("ОАЭ", 10);
    blog2.set_info(blog1);  // используется обычная переменная

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    return 0;
}