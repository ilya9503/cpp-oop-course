#include <iostream>
#include <string>

class Art {
protected:
    short stars {0}; // количество звезд (оценка)
public:
    Art(short st = 0) : stars(st)
        { }
    virtual ~Art()
        {   }
    virtual void set_stars(short vol) { stars = vol; }
    short get_stars() const { return stars; }
};

class Painting : public Art {
    std::string title, author;
public:
    Painting(std::string t, std::string a) : Art(), title(t), author(a)
        {   }
    const std::string& get_title() const // возвращает значение поля title
        { return title; }
    const std::string& get_author() const // возвращает значение поля author
        { return author; }
    virtual ~Painting()
        { printf("~Painting\n"); }
};

class Music : public Art {
    std::string title, composer;
    int max_stars {5}; // максимальное количество звезд
public:
    Music(std::string t, std::string c) : Art(), title(t), composer(c)
        {   }
    virtual ~Music()
        { printf("~Music\n"); }
    const std::string& get_title() const // возвращает значение поля title
        { return title; }
    const std::string& get_composer() const // возвращает значение поля composer
        { return composer; }
    virtual void set_stars(short vol) // задает количество звезд, не более max_stars (если vol больше max_stars, то ставится max_stars)    
        { stars = (vol > max_stars) ? max_stars : vol; }
};