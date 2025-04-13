/*
    В памяти устройства 2-мерные массивы представляются как 1-мерные:
              i  j
    char pole[3][3]
    N = 3
    char pole_1[N*N]
    char x = pole_1[i*N+j]
*/
#include <iostream>

// здесь объявляйте класс
class GamePole {
    int rows {0}, cols {0};     // число строк и столбцов игрового поля
    char* pole {nullptr};       // массив длиной rows * cols элементов
public:
    GamePole(int r, int c) : rows(r), cols(c)
    {
        pole = new char[r*c]{0};
    }
    GamePole(const GamePole& other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
        //int sz = other.rows * other.cols;
        this->pole = new char[other.rows * other.cols]{0};
    }
    ~GamePole()
    {
        delete [] pole;
    }
    void set_item(int row, int col, char value)    // заносит в позицию (row, col) игрового поля pole значение value
    {
        // index=row⋅cols+col
        int index = row * cols + col;
        pole[index] = value;
    }
    char get_item(int row, int col) const                // возвращает значение клетки игрового поля pole позиции (row, col)
        { return pole[row * cols + col]; }
    const char* get_pole() const                         // возвращает массив pole
        { return pole; }
    void get_size(int& rows, int& cols) const            // возвращает значения полей rows и cols
    {
        rows = this->rows;
        cols = this->cols;
    }
};


int main(void)
{
    // здесь продолжайте функцию main
    //GamePole p(5, 10); // rows = height, cols = width, pole - значения всех элементов равны нулю (число 0)
    //GamePole p_cp = p;
    GamePole gp(10, 7);
    gp.set_item(3, 5, '#');
    gp.set_item(4, 2, '*');
    gp.set_item(4, 4, '*');
    //std::cout << gp.get_item(4, 2);
    /*
        позиция (3, 5): '#'
        позиция (4, 2): '*'
        позиция (4, 4): '*'
    */
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}