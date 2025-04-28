#include <iostream>
#include <string>
#include <utility>

// здесь объявляйте класс
class Distance {
    int dist {0}; // дистанция
public:
    Distance() = default;
    Distance(int x) : dist(x)
        {   }
    const Distance& operator+=(int x)
        { dist += x; return *this; }
    const Distance& operator-=(int x)
        { dist -= x; return *this; }
    const Distance& operator*=(int x)
        { dist *= x; return *this; }
    const Distance& operator/=(int x)
        { dist /= x; return *this; }
    const Distance& operator=(const Distance& other)
    {
        if(this == &other) return *this;
        dist = other.dist;
        return *this;
    }
    int operator ()()
        { return dist; }
};


int main()
{
    // здесь продолжайте функцию main
    Distance d = 547;
    Distance& lnk_d = d;
    Distance&& lnk_r_d = std::move(lnk_d);
    lnk_r_d += 100;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}