#include <iostream>

// здесь объявляйте классы и функцию
class ValueError : public std::exception {
    std::string msg;
public:
    ValueError(const char* error) : msg(error)
        { }
    ValueError(const ValueError& other) : msg(other.msg)
        { }
    const char * what() const noexcept override { return msg.c_str(); }  // noexcept указывает компилятору, что функция не выбрасывает исключений
};

class Window {
    int width, height;
public:
    Window(int w, int h) : width(w), height(h)
    {
        if(w <= 0 || h <= 0)
            throw ValueError("The value must be positive");
    }

    void get_data(int& w, int& h) const
        { w = this->width; h = this->height; }
};

class Rect {
    double width, height;
public:
    Rect(double w, double h) : width(w), height(h)
    {
        if(w <= 0 || h <= 0)
            throw ValueError("The value must be positive");
    }

    void get_data(double& w, double& h) const
        { w = this->width; h = this->height; }
};

template <typename T1=Window, typename T2=int>
auto get_square(const T1 &x)
{
    T2 w, h;
    x.get_data(w, h);
    return w * h;
}


int main()
{
    // здесь продолжайте функцию main
    try {
        Window w(100, -5);
        int res_sq = get_square(w);
    }
    catch(const ValueError &err)
    {
        std::cout << err.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}