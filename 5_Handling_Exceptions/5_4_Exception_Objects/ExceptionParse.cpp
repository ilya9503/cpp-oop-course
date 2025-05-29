/*
    The term "parse" generally means to analyze a string of symbols (usually text) according to the rules of
        a formal grammar. It’s used in many areas of programming and computer science.
*/

#include <iostream>
#include <cstring>

class ExceptionParse {
public:
    ExceptionParse() { }
};

void parse_data(const char* buff, size_t size)
{
    int indx {0};
    while(indx < size && buff[indx] != 0)
    {
        if(buff[indx] == '@')
            throw ExceptionParse();

        indx++;
    }
}

void connect()
{
    try {
        const char* buff = "gfghfghf0@fggf";
        parse_data(buff, strlen(buff));
    }
    catch(ExceptionParse p) {
        std::cout << "Error" << std::endl;
        throw;
    }

}

int main()
{
    try {
        connect();
    }
    catch(ExceptionParse& e) {
    }
    catch(...) {
    }

    return 0;
}