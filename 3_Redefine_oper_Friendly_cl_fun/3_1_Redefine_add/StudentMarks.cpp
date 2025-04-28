#include <iostream>

class StudentMarks
{
    enum {max_length = 100};
    short marks[max_length] {0}; // массив оценок студента
    int count {0}; // количество оценок в массиве marks
public:
    StudentMarks(short* ms, int total)
    {
        count = (total > max_length) ? max_length : total;

        for(int i = 0; i < count; ++i)
            marks[i] = ms[i];
    }
    StudentMarks operator+(const StudentMarks& right) const
    {
        // Новые конструкторы в класс StudentMarks не добавлять; все реализовать путем добавления метода(ов) operator+.
        int total_count = this->count + right.count;
        short temp_marks[total_count]{0};
        for(int i = 0; i < this->count; ++i)
            temp_marks[i] = this->marks[i];
        int j=0;
        for(int i = this->count; i < total_count; ++i)
            temp_marks[i] = right.marks[j++];
        return StudentMarks(temp_marks, total_count);
    }
    StudentMarks operator+(short right)
    {
        int temp_count = this->count + 1;
        short temp_marks[temp_count]{0};
        for(int i = 0; i < this->count; ++i)
            temp_marks[i] = marks[i];

        temp_marks[temp_count-1] = right;
        return StudentMarks(temp_marks, temp_count);
    }
    const short* get_marks() const { return marks; }
    int get_count() const { return count; }
};

int main()
{
    short m[] = {2, 2, 3, 2, 3};
    short k[] = {5, 4, 2};
    StudentMarks marks_1(m, sizeof(m)/sizeof(*m));
    StudentMarks marks_2(k, sizeof(k)/sizeof(*k));
    /*
        StudentMarks res_1 = marks_1 + marks_2;
        StudentMarks res_1 = marks_1.operator+(marks_2);

        StudentMarks res_2 = marks_1 + 4;
        StudentMarks res_2 = marks_1.operator+(4);

    */
    StudentMarks res_1 = marks_1 + marks_2;     // res_1: marks = {2, 2, 3, 2, 3, 5, 4, 2}, count = 8
    StudentMarks res_2 = marks_1 + 4;
    const short* res_1_m = res_1.get_marks();
    std::cout << "res_1: ";
    for(int i = 0; i < res_1.get_count(); ++i)
        std::cout << res_1_m[i] << " ";
    std::cout << std::endl;
    std::cout << res_1.get_count() << std::endl;

    const short* res_2_m = res_2.get_marks();
    std::cout << "res_2: ";
    for(int i = 0; i < res_2.get_count(); ++i)
        std::cout << res_2_m[i] << " ";
    std::cout << std::endl;
    std::cout << res_2.get_count() << std::endl;

    //StudentMarks res_2 = marks_1 + 4;           // res_2: marks = {2, 2, 3, 2, 3, 4}, count = 6

    return 0;
}