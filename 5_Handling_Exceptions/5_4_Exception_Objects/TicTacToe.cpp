#include <iostream>

class ExceptionIndexError {     // класс исключения
    int row{0}, col{0};         // индексы (ошибочные)
public:
    ExceptionIndexError(int r, int c) : row(r), col(c)
        {   }
    int get_row() const { return row; } // возвращает значение поля row
    int get_col() const { return col; } // возвращает значение поля col     
};

class TicTacToe {
    enum { size_pole = 3 };                 // размер поля
    char pole[size_pole * size_pole] {0};   // игровое поле

    class RowData {                     // вложенный класс, для реализации второго индекса [][] 
        int indx_row {0};               // индекс строки игрового поля
        TicTacToe* obj_this {nullptr};  // указатель на текущий объект класса TicTacToe (для получения доступа к внешнему классу)
    public:
        RowData(TicTacToe* obj, int indx) : obj_this(obj), indx_row(indx)
            {   }
        char& operator[](int indx_col) // indx_col - индекс столбца игрового поля
        {
            if(indx_row < 0 || indx_col < 0 || indx_row > size_pole-1 || indx_col > size_pole-1)
                throw ExceptionIndexError(indx_row, indx_col);

            return obj_this->pole[indx_row * obj_this->size_pole + indx_col];
            // indx = row * size_pole + col; row - индекс по строкам, col - индекс по столбцам
        }
    
    void print_pole()
    {
        for(int i = 0; i < size_pole; ++i){
            for(int j = 0; j < size_pole; ++j)
                std::cout << obj_this->pole[i*size_pole + j] << ' ';
            std::cout << std::endl;
        }
    }
    };
public:
    TicTacToe() = default;
    ~TicTacToe() = default;

    const char* get_pole() const { return pole; }
    int get_size() const { return size_pole; }

    RowData operator[](int indx_row) // indx_row - индекс строки поля
    {
        return RowData(this, indx_row);
    }

};

int main()
{
    // здесь продолжайте функцию main
    TicTacToe game;

    try {
        game[0][1] = 'o';
        game[1][1] = 'x';
        game[4][2] = 'x';
    }
    catch(const ExceptionIndexError& exc) {
        std::cout << "Incorrect index: " << exc.get_row() << ", " << exc.get_col() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}