#include <iostream>

// здесь объявляйте класс
class BoxDims {
    unsigned short dimension {0};   // размерность предмета (1 - одномерный; 2 - двумерный и т.д.)
    unsigned* dims {nullptr};       // габариты (значения) по каждой из координат
public:
    BoxDims(unsigned s1=0, unsigned s2=0, unsigned s3=0)
    {
        if(s1)
            dimension++;
        if(s2)
            dimension++;
        if(s3)
            dimension++;

        dims = new unsigned[dimension];
        dims[0] = s1;
        dims[1] = s2;
        dims[2] = s3;
    }
    BoxDims(unsigned* d, unsigned short dn) : dimension(dn)
    {
        dims = new unsigned[dimension];
        set_dims(d);
    }
    ~BoxDims()
        { delete [] dims; }
    void set_dims(unsigned* ds)        // задание значений габаритов (в массив dims); длина массива ds полагается не меньше длины массива dims (данные заносятся в ранее созданный массив dims, новый не создается; лишние значения отбрасываются)
    {
        for(int i = 0; i < dimension; ++i)
            dims[i] = ds[i];        
    }
    unsigned short get_dimension() const     // возвращает значение поля dimension
        { return dimension; }
    const unsigned* get_dims() const         // возвращает массив габаритов (поле dims)
        { std::cout << dims[0] << ' ' << dims[1] << ' ' << dims[2] << std::endl ; return dims; }
    unsigned get_volume() const              // возвращает объем предмета
    {
        unsigned res = 1;
        for(int i = 0; i < dimension; ++i)
            res *= dims[i];
        return res;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    BoxDims box(3, 10, 5);
    std::cout << box.get_dimension() << " " << box.get_volume();
    //unsigned* ar = new unsigned[3]{1, 2, 3};
    //BoxDims thing(1);                      // dimension = 1, dims = {size_1}
    //BoxDims thing1(1, 2);              // dimension = 2, dims = {size_1, size_2}
    //BoxDims thing2(1, 2, 3);      // dimension = 3, dims = {size_1, size_2, size_3}
    //BoxDims thing3(ar, sizeof(ar)/sizeof(*ar));                 // dimension = size_ds, dims = ds
    //delete ar; удаление nullptr запрещено
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}