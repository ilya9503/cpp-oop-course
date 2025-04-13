#include <math.h>

class Point {
    public:
        int x {0}, y{0};
    public:
        Point(int x = 0, int y = 0) : x(x), y(y)
            { }
        int get_x() const { return x; }
        int get_y() const { return y; }
    
        void set_coords(int x, int y) { this->x = x; this->y = y; }
    };
    
    class Line {
        Point sp, ep;
    public:
        void set_coords(const Point& sp, const Point& ep)
        {
            this->sp = sp; this->ep = ep;
        }
        double get_length() const
        {
            double d = sqrt( (sp.get_x() - ep.get_x()) * (sp.get_x() - ep.get_x()) +
                             (sp.get_y() - ep.get_y()) * (sp.get_y() - ep.get_y()) );
            return d;
        }
    };

int main()
{
    return 0;
}