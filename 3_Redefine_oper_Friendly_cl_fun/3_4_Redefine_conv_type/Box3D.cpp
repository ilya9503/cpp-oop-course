/*
    Если указывается неверный индекс (за пределами [0; 2]), то либо ничего не делается, либо возвращается число 0.
        Также игнорировать присваивание отрицательных чисел (габариты могут быть только положительными).
    Все методы класса, которые не меняют состояние объекта, сделать константными.
*/

#include <iostream>

class Box3D {
 private:
  short a{0}, b{0}, c{0};

  class Inner {
   private:
    Box3D* current{nullptr};
    int index = -1;

   public:
    Inner(Box3D* current, int index) : current(current), index(index) {}
    int operator=(int right) {
      if (right > 0) {
        switch (index) {
          case 0:
            current->a = right;
            break;
          case 1:
            current->b = right;
            break;
          case 2:
            current->c = right;
            break;
        }
      }
      return right;
    }

    operator short() const {
      switch (index) {
        case 0:
          return current->a;
        case 1:
          return current->b;
        case 2:
          return current->c;
        default:
          return 0;
      }
    }
  };

 public:
  void get_dims(short& a, short& b, short& c) {
    a = this->a;
    b = this->b;
    c = this->c;
  }

  void set_dims(short a, short b, short c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }

  Box3D(short x = 0, short y = 0, short z = 0) : a(x), b(y), c(z) {}
  ~Box3D() = default;

  Inner operator[](int index) { return Inner(this, index); }

  operator int() { return a * b * c; }
};

int main()
{
    Box3D b1;
    Box3D b2(1, 2, 3);      // a = 1, b = 2, c = 3

    Box3D b;
    b[0] = 10;              // a = 10
    b[1] = 20;              // b = 20
    b[2] = 30;              // c = 30
    int volume = b;         // возвращается объем: a * b * c
    short dim = b[1];       // получение значения габарита по индексу indx


    return 0;
}