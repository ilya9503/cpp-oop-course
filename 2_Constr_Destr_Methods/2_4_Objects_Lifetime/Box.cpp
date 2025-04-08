class Box {
    double width {-1}, height {-1}, depth {-1};
public:
    Box(double a=0, double b=0, double c=0)
        : width(a), height(b), depth(c)
        { }
    Box(const Box& other) 
        : width(other.width), height(other.height), depth(other.depth)
        { }
};

int main()
{
    Box b, toy_b(b);

    return 0;
}