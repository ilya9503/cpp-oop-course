/*
    Крестики-нолики. Пример двумерного массива
    Все индексы должны пересчитываться для одномерного массива pole по формуле:
        indx=row⋅size_pole+col
    где row - индекс по строкам; col - индекс по столбцам. Если указываются неверные индексы, то их следует игнорировать
        (ничего не делать), либо возвращать значение 0.
*/

#include <iostream>

class TicTacToe {
    enum { size_pole = 3 };
    char pole[size_pole * size_pole] {0}; // игровое поле
    // Вложенный класс
    class RowData {
        int indx_row {0};               // индекс строки поля row
        TicTacToe* obj_this {nullptr};  // указатель на текущий объект класса TicTacToe
    public:
        RowData(TicTacToe* obj, int indx) : obj_this(obj), indx_row(indx) 
            { }
        char& operator[](int indx_col) // indx_col - индекс столбца поля col
        {
            return obj_this->pole[indx_row * size_pole + indx_col];
        }
    };

public:
    TicTacToe() = default;
    const char* get_pole() const { return pole; }
    int get_size() { return size_pole; }

    RowData operator[](int indx_row) // indx_row - индекс строки поля row
    {
        return RowData(this, indx_row);
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    TicTacToe* ptr_game = new TicTacToe();
    (*ptr_game)[0][0] = 'x';
    (*ptr_game)[1][1] = 'x';
    (*ptr_game)[2][2] = 'x';

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_game;

    return 0;
}