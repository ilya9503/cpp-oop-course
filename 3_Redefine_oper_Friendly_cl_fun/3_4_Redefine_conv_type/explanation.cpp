class Point {
    int x {0}, y {0};
    int error_index;
public:
    int& operator[](int indx)
    {
        if(indx == 0) return x;
        if(indx == 1) return y;

        return error_index; // ошибка индексации
    }

    operator int() const
    {
        return x + y;
    }
};

int main()
{
    Point pt;
    pt[0] = -1;     // pt[0] возвращает ссылку на поле int x. затем происходит x=-1;
    pt[1] = 10;
   
    int a = pt[0];  // pt[0] возвращает ссылку на поле int x. int b = x;
    int b = pt[1];

    int s = pt;     // вызывается operator int() const
    //double s = pt;

    return 0;
}