#include <iostream>
#include <string>

// здесь объявляйте классы
class Employee {
public:
  virtual const std::string& get_fname() const = 0; // для получения имени сотрудника
  virtual const std::string& get_lname() const = 0; // для получения фамилии сотрудника
  virtual short get_old() const = 0; // для получения возраста сотрудника
  virtual ~Employee() = default;
};

class Lector : public Employee {
  std::string first_name, last_name;   short old {0}; int salary {0};
public:
  Lector(std::string fn, std::string ln, short age) : first_name(fn), last_name(ln), old(age)
  {  }
  Lector(std::string fn, std::string ln, short age, int sal) : first_name(fn), last_name(ln), old(age), salary(sal)
  {  }
  const std::string& get_fname() const { return first_name; } // для получения имени сотрудника
  const std::string& get_lname() const { return last_name; } // для получения фамилии сотрудника
  short get_old() const { return old; } // для получения возраста сотрудника
  void set_salary(int salary)
  {
     if(salary > 0)
         this->salary = salary;
  }// задает значение поля salary с проверкой на положительность параметра salary (если не так, то поле не менять)
  int get_salary() const
    { return salary; }// возвращает значение поля salary (зарплата)
};
    
class Laborant : public Employee {
  std::string first_name, last_name;   short old {0}; std::string job_title; 
public:
  Laborant(std::string fn, std::string ln, short age) : first_name(fn), last_name(ln), old(age)
  {  }
    
  Laborant(std::string fn, std::string ln, short age, std::string jt) : first_name(fn), last_name(ln), old(age), job_title(jt)
  {  }

 const std::string& get_fname() const { return first_name; } // для получения имени сотрудника
  const std::string& get_lname() const { return last_name; } // для получения фамилии сотрудника
  short get_old() const { return old; } // для получения возраста сотрудника
    
void set_job_title(const std::string& job_title)
  { this->job_title = job_title; }// задает значение поля job_title (должность)
const std::string& get_job_title() const { return job_title; } // возвращает значение поля job_title
};

enum{max_persons=255};

int main(void)
{
    // здесь продолжайте функцию main

  Employee* staff[max_persons] {nullptr};
  staff[0] = new Lector("Sergey", "Balakirev", 33, 85000);
  staff[1] = new Laborant("Elena", "Pozdnjakova", 27, "Programmer");
  staff[2] = new Lector("Olga", "Levkina", 38, 120000);

  for(int i=0; i<3; ++i)
      std::cout << staff[i]->get_fname() << " ";
  
  std::cout << std::endl;
  

  //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
  for(int i=0; i<3; ++i)
      delete staff[i];

    return 0;
}