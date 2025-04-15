class Box3D
{
    int a{0}, b{0}, c{0}; // габаритные размеры
public:
    Box3D(int width = 0, int height = 0, int depth = 0) : a(width), b(height), c(depth)
        { }
    const Box3D& operator + (const Box3D& right) const
    {
        Box3D b(this->a + right.a, this->b + right.b, this->c + right.c);
        return b;
    }
};

int main()
{
    Box3D b1(1, 2, 3), b2(10, 20, 30);
    Box3D res = b1 + b2;

    return 0;
}