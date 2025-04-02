#include <iostream>
#include <string>

// здесь объявляйте класс
class Notes {
    std::string title;      // название
    std::string author;     // автор
    int pages;              // число страниц
public:
    void set_data(const std::string& title, const std::string& author, int pages) // заносит в соответствующие поля переданные значения
    {
        this->title = title;
        this->author = author;
        this->pages = pages;
    }
    void set_data(const Notes& note) // заносит в соответствующие поля значения из переданного объекта note
    {
        title = note.title;
        author = note.author;
        pages = note.pages;
    }
    const std::string& get_title()  // возвращает ссылку на поле title
        { return title; }
    const std::string& get_author() // возвращает ссылку на поле author
        { return author; }
    int get_pages()                 // возвращает значение поля pages
        { return pages; }
};


int main(void)
{
    // здесь продолжайте функцию main
    Notes* ptr_note1 = new Notes;
    Notes* ptr_note2 = new Notes;

    ptr_note1->set_data("Фантазия экспромт", "Ф. Шопен", 5);

    ptr_note2->set_data(*ptr_note1);    // используется указатель

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_note1;
    delete ptr_note2;

    return 0;
}