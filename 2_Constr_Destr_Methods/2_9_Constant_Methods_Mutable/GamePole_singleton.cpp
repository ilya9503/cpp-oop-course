#include <iostream>

// здесь объявляйте класс
class GamePole {
    int rows {0}, cols {0};     // число строк и столбцов игрового поля
    char* pole {nullptr};       // массив длиной rows * cols элементов
    static GamePole* instance_ptr;
public:
    GamePole(const GamePole&) = delete;
    GamePole(int r, int c) : rows(r), cols(c)
    { pole = new char[r*c]{0}; }    
    static GamePole* init(int r, int c)
    {
        // Если статическое поле instance_ptr равно nullptr, значит, ни одного объекта класса не существует, и он создается
        if(instance_ptr == nullptr) {
            instance_ptr = new GamePole(r,c);
        }
        return instance_ptr;
    }
    ~GamePole()
    {
        delete [] pole;
    }
    void set_item(int row, int col, char value)    // заносит в позицию (row, col) игрового поля pole значение value
        { pole[row * cols + col] = value; }
    char get_item(int row, int col) const          // возвращает значение клетки игрового поля pole позиции (row, col)
        { return pole[row * cols + col]; }
    const char* get_pole() const                   // возвращает массив pole
        { return pole; }
    void get_size(int& rows, int& cols) const      // возвращает значения полей rows и cols
    { rows = this->rows; cols = this->cols; }
};

GamePole* GamePole::instance_ptr{nullptr};

int main(void)
{
    // здесь продолжайте функцию main
    GamePole* ptr_pl = GamePole::init(5, 10); // rows = height, cols = width, pole - значения всех элементов равны нулю (число 0)
    ptr_pl->set_item(1, 1, '@');
    ptr_pl->set_item(4, 9, '#');
    ptr_pl->set_item(3, 2, '*');

    //std::cout << ptr_pl->get_item(1, 1);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)    
    delete ptr_pl;

    return 0;
}