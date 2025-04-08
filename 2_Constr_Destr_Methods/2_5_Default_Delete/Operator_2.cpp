#include <iostream>

class Operator {
    long a {0}, b {0}, c {0};
    Operator() = default;
public:
    static Operator* create_obj() 
    {
        Operator * ptr_obj = new Operator();
        return ptr_obj;
    }
};

int main()
{
    Operator *op2 = Operator::create_obj();     // можно использовать без привязки к объекту, потому что static
    Operator op1(*op2);

//    Operator op;
//    Operator *ptr_op = new Operator();

    delete op2;
    return 0;
}