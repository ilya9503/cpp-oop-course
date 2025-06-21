#include <iostream>

template <typename T1, typename T2>
int max2(T1 a, T2 b) { puts("1"); return (a > b) ? a : b; }

template <typename T = double>
auto max2(T a, T b) { puts("2"); return (a > b) ? a : b; }

template <typename A = int, typename D = double>
A max2(D* a, D* b) { puts("3"); return (*a > *b) ? *a : *b; }

char max2(char a, char b) { puts("4"); return (a > b) ? a : b; }

int main()
{
    double x = 65, y = -10;

    int r_1 = max2(x, y);
    double r_2 = max2(1, y);
    long r_3 = max2('a', 'b');
    auto r_4 = max2(&x, &y);
    double r_5 = max2(-0.5, 1.0);

    return 0;
}