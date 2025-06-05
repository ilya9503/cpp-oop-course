#include <iostream>
#include <string>

using uint8 = unsigned char;    // пользовательский тип данных

class ClockError : public std::exception {
protected:
    std::string msg; // сообщение об ошибке
public:
    ClockError(const std::string& m) noexcept : msg(m)
        {   }
    virtual ~ClockError()
        {   }
    const char * what() const noexcept override { return msg.c_str(); }
};

class ClockValueError : public ClockError {
public:
    ClockValueError(const std::string& m) noexcept : ClockError(m)
        {   }
};

class ClockIndexError : public ClockError {
public:
    ClockIndexError(const std::string& m) noexcept : ClockError(m)
        {   }
};

class Clock {
    uint8 hours {0};
    uint8 mins {0};
    uint8 secs {0};

    class Item {
        Clock* current {nullptr};
        int index {-1};

    public:
        Item(Clock* obj, int indx) : current{obj}, index{indx}
            { }

        uint8 operator=(uint8 right)
        {
            switch(index) {
                case 0:
                    if(right < 0 || right > 11)
                        throw ClockValueError("Clock: out of range");
                    current->hours = right;
                    break;
                case 1:
                    if(right < 0 || right > 59)
                        throw ClockValueError("Clock: out of range");
                    current->mins = right;
                    break;
                case 2:
                    if(right < 0 || right > 59)
                        throw ClockValueError("Clock: out of range");
                    current->secs = right;
                    break;
            }
            return right;
        }
        operator uint8() const  // оператор приведения к типу uint8
        {
            switch(index) {
                case 0: return current->hours;
                case 1: return current->mins;
                case 2: return current->secs;
            }
            return 0;
        }
    };

public:
    Clock(uint8 hs = 0, uint8 ms = 0, uint8 sc = 0)
    {
        if(hs < 0 || hs > 11)
            throw ClockValueError("Clock: out of range");
        else if(ms < 0 || ms > 59)
            throw ClockValueError("Clock: out of range");
        else if(sc < 0 || sc > 59)
            throw ClockValueError("Clock: out of range");
        else
            this->hours = hs; this->mins = ms; this->secs = sc;
    }

    unsigned get_time() const { return hours * 3600 + mins * 60 + secs; }

    void get_time(uint8& hours, uint8& mins, uint8& secs) const
    {
        hours = this->hours; mins = this->mins; secs = this->secs;
    }

    void set_time(uint8 hours, uint8 mins, uint8 secs)
    {
        if(hours < 0 || hours > 11)
            throw ClockValueError("Clock: out of range");
        else if(mins < 0 || mins > 59)
            throw ClockValueError("Clock: out of range");
        else if(secs < 0 || secs > 59)
            throw ClockValueError("Clock: out of range");
        else
            this->hours = hours; this->mins = mins; this->secs = secs;
    }

    Item operator[](int indx) 
    {
        if(indx < 0 || indx > 2)
            throw ClockIndexError("Clock: index error");

        return Item(this, indx);
    }
};

int main()
{
    // здесь продолжайте функцию main
    try {
        Clock cl(10, 19, 24);
        //cl[0] = 13;
    }
    catch(const ClockIndexError& ce) {
        std::cout << ce.what() << std::endl;
    }
    catch(const ClockValueError& ce) {
        std::cout << ce.what() << std::endl;
    }
    catch(const ClockError& ce) {
        std::cout << ce.what() << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}