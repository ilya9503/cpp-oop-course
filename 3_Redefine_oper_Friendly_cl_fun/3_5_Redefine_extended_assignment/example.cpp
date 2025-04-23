// Пример переопределения +=, *=
struct Point {
    int x {0}, y {0};

    void operator+=(int right) { x += right; y += right; }
    void operator+=(const Point& pt) { x += pt.x; y += pt.y; }

    void operator*=(int right) { x *= right; y *= right; }
    void operator*=(const Point& pt) { x *= pt.x; y *= pt.y; }
};

int main()
{
    Point pt1 {2, 4};
    Point pt2;

    pt2 += pt1;
    pt2 *= 5;
    
    return 0;
}