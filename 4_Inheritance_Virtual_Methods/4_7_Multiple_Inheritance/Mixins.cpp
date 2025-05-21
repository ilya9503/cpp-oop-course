/*
    Mixin — это паттерн проектирования, при котором класс добавляет функциональность другим классам без использования наследования
        от общего предка.
    Он позволяет «смешивать» поведение из нескольких источников.

    Виртуальный деструктор в C++ нужен для правильного уничтожения объектов через указатель на базовый класс.
    🔹 Проблема без виртуального деструктора
    Если у вас есть наследование, и вы удаляете объект через указатель на базовый класс, деструктор производного класса не вызовется
        , если деструктор не объявлен как virtual.
    👉 Это приводит к утечке ресурсов и неполному уничтожению объекта.

    Всегда делайте деструктор виртуальным в базовых классах с виртуальными методами.
    В абстрактных классах (интерфейсах) деструктор должен быть виртуальным и часто = default или = 0.
*/

#include <iostream>
#include <string>

enum request_method { // обрабатываемые методы
    method_get = 1,     // получение ресурса с сервера
    method_post = 2,    // создание нового ресурса на сервере
    method_put = 3,     // обновление ресурса на сервере
    method_delete = 4   // удаление ресурса
};

struct Request { // объект запроса
    request_method method {method_get};
    std::string url;
    std::string data;
};

class RetriveMixin {
    request_method method{ method_get };
public:
    RetriveMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~RetriveMixin() { }
    std::string get(const Request& request) { return "GET: " + request.url; }
};

class CreateMixin {
    request_method method{ method_post };
protected:
    int test{0};
public:
    CreateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~CreateMixin() { }
    std::string post(const Request& request) { return "POST: " + request.url; }
};

class UpdateMixin {
    request_method method{ method_put };
public:
    UpdateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~UpdateMixin() { }
    std::string put(const Request& request) { return "PUT: " + request.url; }
};

// здесь объявляйте класс GeneralView
class GeneralView : public RetriveMixin, public CreateMixin {
private:
    enum { max_methods = 4 }; // максимальное число разрешенных методов
    int count_methods{ 0 }; // число разрешенных методов
    request_method allowed_methods[max_methods]{ method_get, method_post }; // массив из разрешенных методов
private:
    bool is_method_exists(request_method method) // возвращает true, если method присутствует в массиве allowed_methods, иначе false
    {
        bool res{false};
        for(int i=0; i < max_methods; ++i)
            if(allowed_methods[i] == method) res |= 1;
        return res;
    }
public:
    GeneralView(request_method* methods_ar) : RetriveMixin(methods_ar, 0), CreateMixin(methods_ar, 1), count_methods(2)
        {  }
    ~GeneralView() { }
    std::string render_request(const Request& request)
    {
        std::string res;
        if(is_method_exists(request.method)) {
            if(request.method == method_get)
                res = get(request);
            else
                res = post(request);
        }

        return res;   
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    request_method methods_ar[2];
    GeneralView gw(methods_ar);
    Request r { method_post,
                "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov",
                "<h1>Множественное наследование</h1>"
    };
    std::string res = gw.render_request(r);
    std::cout << res;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}