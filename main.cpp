#include <iostream>
#include<cstdlib>
using namespace std;
#include"NODE.h"
#include"LL.h"


class Address{
  private:
  string H_Number;
  string province;
  string district;
  string sub_district;
  public:
  Address();
  ~Address();
  
};

class Personinformation:public Address{
  private :
  string name;
  string gender;
  string blood_type;
  string per_disease;
  int phone_number;
  int d,m,y;
  public :
  Personinformation();
  ~Personinformation();
};

class timeline:public Address{
  private:
  int timein;
  int timeout;
  int date;
  string storename;
  string note;
  
  public:
  timeline();
  ~timeline();
  
};

int main() {

}
