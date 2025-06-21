class Base { };
class Derive : public Base { };
class Line { };

Base base;
int var {10};
double price {0.0};
double& lnk_d = price;

Derive* ptr_drv = static_cast<Derive *>(&base);

char* buff = static_cast<char * >(price);   // reinterpret_cast / void*

long& data = static_cast<long& >(var);      // нельзя привести int к long

double var_d = static_cast<double>(lnk_d);

const char data = static_cast<const char>(var);

short data_1 = static_cast<short>(var);

Line* ptr_ln = static_cast<Line * >(&base);