#include <iostream>
#include <memory>

// Элемент стека
class Object {
    int data {0};   // данные
    std::shared_ptr<Object> next {nullptr}; // указатель на предыдущий объект
public:
    Object(int d) : data(d), next(nullptr)
        { }

    int get_data() const { return data; }
    std::shared_ptr<Object>& get_next() { return next; }    // возвращает указатель на предыдующий объект
};

using shared_obj_ptr = std::shared_ptr<Object>;

// Стек
class Stack {
    shared_obj_ptr top {nullptr};   // указатель на вершину стека типа Object. Указывает на самый крайний объект класса Object
public:
    shared_obj_ptr get_top() { return top; }

    void push(int data)
    {
        shared_obj_ptr node = std::make_shared<Object>(data);   // выделяем область памяти для класса Object, помещаем туда данные int
        node->get_next() = top; // node.data = data; node.next = top; 
        top = node;             // обновляем вершину
    }

    shared_obj_ptr pop() {
        if (!top) return nullptr;   // если в стек пуст
        shared_obj_ptr ptr = top;
        top = top->get_next();      // записываем на вершину стека предыдущий объект
        return ptr;
    }

    const Stack& operator=(const Stack& other)
    {
        if(this == &other) return *this;
        top = other.top;
        return *this;
    }

    const Stack& operator+=(int x)
    {
        this->push(x);
        return *this;
    }

    const Stack& operator--()    // префикс
    {
        this->pop();
        return *this;
    }

    Stack operator--(int)    // постфикс
    {
        Stack temp = *this;
        this->pop();
        return temp;
    }

};

int main()
{
    Stack s;
    s.push(1); // добавление 1-го элемента (объекта) в стек
    s.push(2); // добавление 2-го элемента
    s.push(3); // добавление 3-го элемента
    s.push(4); // добавление 4-го элемента
    s.pop(); // удаление верхнего объекта (4-го)

    shared_obj_ptr p {s.get_top()};
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }

    Stack s1, s2;
    s1.push(10); s1.push(-5);
    
    s2 = s1;    // копирование стека s1 в стек s2 (стеки должны быть независимы, полная копия)
 
    s2 += 7;    // добавление наверх стека нового элемента со значением 7 (поле data)
    s2--;       // удаление верхнего объекта из стека (аналог метода pop)
    --s2;       // удаление верхнего объекта из стека (аналог метода pop)

    return 0;
}