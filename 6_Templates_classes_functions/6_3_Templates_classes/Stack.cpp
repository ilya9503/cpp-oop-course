/*
    Шаблонный класс структуры данных Стек
*/

#include <iostream>
#include <memory>

template <typename T>
class Object {
    T data {0};
    std::shared_ptr<Object<T>> next {nullptr};
public:
    Object(T d) : data(d), next(nullptr)
        { }

    T get_data() const { return data; }
    std::shared_ptr<Object<T>>& get_next() { return next; }
};

template <typename T>
class Stack {
    using shared_obj_ptr = std::shared_ptr<Object<T>>;
    shared_obj_ptr top {nullptr};
public:
    shared_obj_ptr get_top() { return top; }

    void push(T data)
    {
        shared_obj_ptr node = std::make_shared<Object<T>>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr pop() {
        if (!top) return nullptr;
        shared_obj_ptr ptr = top;
        top = top->get_next();
        return ptr;
    }
};