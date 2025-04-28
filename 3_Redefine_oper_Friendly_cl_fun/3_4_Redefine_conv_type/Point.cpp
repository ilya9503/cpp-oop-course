class Point
{
public:
    int x {0}, y {0};
public:
    Point operator + (const Point& right) const
    {
        Point pt {this->x + right.x, this->y + right.y};
        return pt;
    }
};

int main()
{
    Point pt1 {1, 2}, pt2 {10, 20};
    pt1 = pt1 + pt2;
    //pt1 += pt2;

    return 0;
}