#include <iostream>

class ColorRGB {
    unsigned char r{0}, g{0}, b{0};
public:
    ColorRGB() = default;
    ColorRGB(const ColorRGB& other) : r(other.r), g(other.g), b(other.b)
        {}
    ColorRGB(unsigned char c1, unsigned char c2, unsigned char c3) : r(c1), g(c2), b(c3)
        {}
    friend ColorRGB operator+(const ColorRGB& left, const ColorRGB& right);

    static unsigned char max_val_ctrl(unsigned char x1, unsigned char x2)
    {
        int res = (int)x1 + (int)x2;
        return res <= 255 ? (unsigned char)res : 255;
    }
    unsigned get_color() { return r + g*256 + b*65536; }
};

ColorRGB operator+(const ColorRGB& left, const ColorRGB& right)
{
    return ColorRGB(ColorRGB::max_val_ctrl(left.r, right.r),
                    ColorRGB::max_val_ctrl(left.g, right.g),
                    ColorRGB::max_val_ctrl(left.b, right.b)
                );
}

int main()
{
    ColorRGB rgb;
    ColorRGB rgb_w(255, 102, 0); // r = 255, g = 102, b = 0

    ColorRGB clr_1(100, 100, 100), clr_2(255, 0, 80);
    ColorRGB res = clr_1 + clr_2; // r = 255, g = 100, b = 180
    unsigned char x = 100;
    unsigned char x1 = 157;
    //unsigned char res1 = ColorRGB::max_val_ctrl(x, x1);

    return 0;
}