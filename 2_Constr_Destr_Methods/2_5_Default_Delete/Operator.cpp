#include <iostream>

class Operator {
    long a {0}, b {0}, c {0};
    Operator(const Operator& op) = default;     // переносим встроенный конструктор копирования в приватную зону
public:
    Operator() = default;                       // используем встроенный конструктор по-умолчанию
    // Методы
    Operator* create_copy() 
    {
        Operator * ptr_obj = new Operator(*this);
        return ptr_obj;
    }
};

int main()
{
    Operator op;
    Operator *ptr_op = new Operator();

    //Operator op2(op);
    //Operator *ptr_op2 = new Operator(op);
    Operator *op2 = op.create_copy();



    delete ptr_op;
    delete op2;
    //delete ptr_op2;

    return 0;
}