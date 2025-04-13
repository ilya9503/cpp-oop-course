#include <iostream>

// здесь объявляйте класс
class CellItem {
    int row {0}, col {0};
    double data {0.0};
public:
    CellItem(int r, int c, double d=0) : row(r), col(c), data(d)
        {   }
    double get_data() const          // возвращает значение поля data
        { return data; }
    int get_row() const              // возвращает значение поля row
        { return row; }
    int get_col() const              // возвращает значение поля col
        { return col; }
    void set_data(double d)          // заносит в поле data значение d
        { data = d; }
};

int main(void)
{
    // здесь продолжайте функцию main
    CellItem cell(5, 7, 0.79);
    CellItem cell1(5, 7);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}