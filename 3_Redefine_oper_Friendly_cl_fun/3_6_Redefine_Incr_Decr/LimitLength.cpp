#include <iostream>

class LimitLength
{
    enum {min_length = -10, max_length = 10}; // границы допустимых значений
    int length {0}; // текущее значение
public:
    LimitLength(int len = 0) : length(len)
    {
        length = (len < min_length) ? min_length : len;
        length = (len > max_length) ? max_length : len;
    }

    int get_length() const { return length; }

    int operator++(int)
        { return length++; }
    int operator++()
        { return ++length; }
    int operator--(int)
        { return length--; }
    int operator--()
        { return --length; }
    int operator+=(int x)
        { return length += x; }
    int operator-=(int x)
        { return length -= x; }
    int operator*=(int x)
        { return length *= x; }
    int operator/=(int x)
        { return length /= x; }
};

int main()
{
    LimitLength lm1 = -5;
    int a = lm1++;
    int b = ++lm1;
    int c = lm1--;
    int d = --lm1;
    int res_1 = lm1 += 5;
    int res_2 = lm1 -= 15;
    int res_3 = lm1 *= 2;
    int res_4 = lm1 /= 3;

    return 0;
}