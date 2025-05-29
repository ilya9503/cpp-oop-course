/*
    Реализация операции [][] через вложенный класс
*/

#include <iostream>

class ImageData {
    unsigned short width {0}, height {0}; // размер изображения width x height
    unsigned char* pixels {nullptr}; // данные (пиксели) изображения в количестве width * height

    class RowData {
        unsigned short indx_row {0}; // индекс строки изображения
        ImageData* obj_this {nullptr}; // указатель на текущий объект класса ImageData
    public:
        RowData(ImageData* obj, unsigned short indx) : obj_this(obj), indx_row(indx) 
            { }
        unsigned char& operator[](unsigned short indx_col) // indx_col - индекс столбца изображения
        {
            return obj_this->pixels[indx_row * obj_this->width + indx_col];
        }
    };
public:
    ImageData(unsigned short w, unsigned short h) : width(w), height(h)
    {
        pixels = new unsigned char[width * height] {0};
    }
    ~ImageData() { delete[] pixels; }

    unsigned char* get_pixles() { return pixels; }
    unsigned short get_width() const { return width; }
    unsigned short get_height() const { return height; }

    RowData operator[](unsigned short indx_row) // indx_row - индекс строки изображения
    {
        return RowData(this, indx_row);
    }
};

int main()
{
    ImageData image(10, 20);
    //image[1] = 10;
    unsigned char pixel = image[5][7];
    image[1][2] = 10;

    return 0;
}
