#include <iostream>
#include <string>

enum request_method { // обрабатываемые методы
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request { // объект запроса
    request_method method {method_get};
    std::string url;
    std::string data;
};

class GenericView { // базовый класс для обработки запросов
protected:
    enum {total_methods = 3}; // количество обрабатываемых методов
    request_method methods[total_methods] = {method_get, method_post, method_put}; // массив допустимых методов
public:
    virtual std::string get(const Request& request) 
    {
        return request.data;
    }
    virtual std::string post(const Request& request) 
    {
        return request.data;
    }
    virtual std::string put(const Request& request) 
    {
        return request.data;
    }
    virtual std::string del(const Request& request) 
    {
        return request.data;
    }
};

class DetailView : public GenericView {
    bool is_method_exists(request_method method) // возвращает true, если method есть в массиве methods; false - в противном случае
    {
        bool res{false};
        for(int i = 0; i < total_methods; ++i)
            res = (method == methods[i]) || res;
        return res;
    }
public:
/*
    Метод render_request имитирует выполнение поступившего на сервер запроса. Вначале нужно проверить, что поле method объекта request
        содержит номер разрешенного метода (в массиве methods). Если метод не разрешен, то возвращается пустая строка.
    Иначе вызывается метод в соответствии со значением поля request.method:
    method_get: метод get;
    method_post: метод post;
    method_put: метод put;
    method_delete: метод del.
*/
    virtual std::string get(const Request& request) // возвращает поле url объекта request
        { return request.url; }

    const std::string render_request(const Request& request)
    {
        std::string temp;
        if(!is_method_exists(request.method))
            return temp;
        switch (request.method) {
            case method_get:
                temp = GenericView::get(request);
                break;
            case method_post:
                temp = GenericView::post(request);
                break;
            case method_put:
                temp = GenericView::put(request);
                break;
            case 4:
                temp = GenericView::del(request);
                break;
        }
        return temp;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    DetailView dw;
    Request rq {method_get, "htpps://proproprogs.ru/cpp_oop/cpp-oop-virtualnye-virtual-metody-funkcii", "<h1>Заголовок</h1>"};
    std::string res = dw.render_request(rq);
    std::cout << res << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}