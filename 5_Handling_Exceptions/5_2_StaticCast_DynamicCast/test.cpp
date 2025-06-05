#include <iostream>

class Base { };
class Derive : public Base { };
class Line { };

int main()
{
    Base base;
    int var {10};
    double price {0.0};
    double& lnk_d = price;

    char* buff = static_cast<char *>(price);
    
    Derive* ptr_drv = static_cast<Derive *>(&base);
    
    short data_1 = static_cast<short>(var);
    
    double var_d = static_cast<double>(lnk_d);
    
    long& data = static_cast<long& >(var);
    
    Line* ptr_ln = static_cast<Line *>(&base);
    
    const char data = static_cast<const char>(var);


    return 0;
}