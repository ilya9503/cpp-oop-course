#include <iostream>
#include <string>

// здесь объявляйте класс
class BankAccount {
  std::string fio; // владелец счета
  long volume_rub {0}; // объем средств в рублях
public:
    BankAccount(std::string fn, long vr=0) : fio(fn), volume_rub(vr)
    {  }// fio = "Balakirev"; volume_rub = 0
  const std::string& get_fio() const
    { return fio; }// возвращает значение поля fio
  long get_volume_rub()
    { return volume_rub; }// возвращает значение поля volume_rub
  const BankAccount& operator=(long vr)
  {
      this->volume_rub = vr;
      return *this;
  }
    
  const BankAccount& operator+=(long vr)
  {
     this->volume_rub += vr;
     return *this;
  }
    
  const BankAccount& operator+=(const BankAccount& right)
  {
     this->volume_rub += right.volume_rub;
      return *this;
  }
    
  const BankAccount& operator-=(long vr)
  {
     this->volume_rub -= vr;
     return *this;
  }
    
  const BankAccount& operator-=(const BankAccount& right)
  {
     this->volume_rub -= right.volume_rub;
     return *this;
  }

};