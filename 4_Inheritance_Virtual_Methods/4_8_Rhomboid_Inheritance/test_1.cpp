#include <iostream>

class Root {
public:
    int id {0};
    int get_id() const { return id; }
};

class Derive_1 : public Root { };
class Derive_2 : public Root { };

class Derive_12 : public Derive_1, public Derive_2 { };

int main()
{
    Derive_12 d;
    int res_1 = d.Derive_1::get_id();
    int res_2 = d.Derive_1::id;

    return 0;
}