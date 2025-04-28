#include <iostream>

class Distance {
    int dist {0};
public:
    Distance(int d) : dist(d)
        { }
    const Distance& operator+=(int x)
        { dist += x; return *this; }
    const Distance& operator-=(int x)
        { dist -= x; return *this; }
    const Distance& operator*=(int x)
        { dist *= x; return *this; }
    const Distance& operator/=(int x)
        { dist /= x; return *this; }
    operator int() const
        { return dist; }
};

int main()
{
    Distance d1 = 100;
    d1 += 50; // dist = 150
    Distance d2 = d1 += 10; // dist в d1 и d2 равны 150+10 = 160
    Distance res = d2 -= 100; // dist = 60
    Distance sp = d1 *= 5;
    Distance ep = d1 /= 7;
    int res1 = sp; // возвращает значение поля dist

    return 0;
}