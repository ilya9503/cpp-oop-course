#include <iostream>

enum type_filter_water {flt_none = 0, flt_mechanical = 1, flt_aragon = 2, flt_calcium = 3};

class FilterWater {
protected:
    unsigned date {0}; // дата установки фильтра (начало работы)
    type_filter_water type {flt_none}; // тип фильтра
public:
    unsigned get_date() const // возвращает значение поля date
        { return date; }
    type_filter_water get_type() const // возвращает значение поля type
        { return type; }
};

class Mechanical : public FilterWater {
public:
    Mechanical(unsigned d)
    {
        date = d;
        type = flt_mechanical;
    }
};

class Aragon : public FilterWater {
public:
    Aragon(unsigned d)
    {
        date = d;
        type = flt_aragon;
    }
};

class Calcium : public FilterWater {
public:
    Calcium(unsigned d)
    {
        date = d;
        type = flt_calcium;
    }
};

class GeyserClassic {
public:
    enum { total_slots = 3 };
private:
    FilterWater* slots[total_slots] {nullptr}; // слоты с фильтрами для воды
public:
    GeyserClassic() = default;
    GeyserClassic(FilterWater* filter)
    {
        add_filter(1, filter);
    }
    GeyserClassic(FilterWater* filter_1, FilterWater* filter_2)
    {
        add_filter(1, filter_1);
        add_filter(2, filter_2);
    }
    GeyserClassic(FilterWater* filter_1, FilterWater* filter_2, FilterWater* filter_3)
    {
        add_filter(1, filter_1);
        add_filter(2, filter_2);
        add_filter(3, filter_3);
    }
    const FilterWater* operator[](int index) const;     // получение фильтра (из массива slots) по индексу index; если index неверный, то возвращается nullptr; если фильтр в текущем слоте отсутствует, то возвращается nullptr
    void add_filter(int slot_num, FilterWater* filter); // добавление filter в слот с номером slot_num (нумерация: 1, 2, 3)
};

// Внешняя реализация функций для GeyserClassic
const FilterWater* GeyserClassic::operator[](int index) const
{
    if(index >= 0 && index < 3 && slots[index] != nullptr && slots[index]->get_date() != 0) 
        return slots[index];
    else
        return nullptr;
}

void GeyserClassic::add_filter(int slot_num, FilterWater* filter)
{
    if((slot_num >= 1 && slot_num <= 3) && slots[slot_num-1] == nullptr){
        switch (slot_num)
        {
            case 1:
                if(filter->get_type() == flt_mechanical) slots[slot_num-1] = filter;
                break;
            case 2:
                if(filter->get_type() == flt_aragon) slots[slot_num-1] = filter;
                break;
            case 3:
                if(filter->get_type() == flt_calcium) slots[slot_num-1] = filter;
                break;   
        }
    }  
}

int main()
{
    Mechanical filter_1(100);
    Aragon filter_2(100);
    Calcium filter_3(100);
    
    GeyserClassic gc_1;
    GeyserClassic gc_2(&filter_1); // filter_1 для 1-го слота (два остальных nullptr)
    GeyserClassic gc_3(&filter_1, &filter_2); // filter_1 для 1-го слота; filter_2 для 2-го слота
    GeyserClassic gc_4(&filter_1, &filter_2, &filter_3); // каждый фильтр в свой слот (по порядку)

    return 0;
}