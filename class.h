#ifndef class_h
#define class_h
using namespace std;

class In_choice : public exception{
  virtual const char* what () const throw(){
    return "Invalid choice!! \nPlease input again...";
  }
}inchoice;

class In_Date : public exception{
  virtual const char* what () const throw(){
    return "Invalid Date!! \nPlease input again...";
  }
}indate;

class In_Time : public exception{
  virtual const char* what () const throw(){
    return "Invalid Time!! \nPlease input again...";
  }
}intime;



class Address{
  private:
  string H_Number;
  string province;
  string district;
  string sub_district;
  public:
  Address(string="999",string="Nakorn Pathom",string="Phutthamonth",string="Salaya");
  ~Address();
  void show_node(){
      cout <<H_Number<<" "<<sub_district<<" "<<district<<" "<<province<<endl;
    }
   virtual void changeAddress(string HNo,string x ,string y , string z){
      H_Number = HNo;
      sub_district = x;
      district =y;
      province = z;
      cout << "Change Successfully"<<endl;
      sleep(2);}
};
Address::Address(string H_Num,string prov,string dis,string sub_dis):H_Number(H_Num),province(prov),district(dis),sub_district(sub_dis){ 
}
Address::~Address(){
  }

class Personinformation:public Address{
  private :
  string name;
  string gender;
  string blood_type;
  string per_disease;
  string phone_number;
  int dd,mm,yy;
  public :
  Personinformation(string,int ,int ,int ,string,string = "Unknow",string = "Unknow",string = "---",string="999",string="Nakorn Pathom",string="Phutthamonth",string="Salaya");
  ~Personinformation();
  void show_perInfo();
  void changeName(string );
  void changeGender(string );
  void changeBloodtype(string );
  void changeDoB();
  void changeUdis(string);
  void changePhoneNo(string);
  void changeAddress(string,string,string,string);
};
Personinformation :: Personinformation(string n,int d,int m,int y,string phone,string gen,string bt,string pd,string H_Num,string prov,string dis,string sub_dis):Address (H_Num,prov,dis,sub_dis){
  name = n; 
  gender = gen; 
  blood_type = bt; 
  per_disease = pd; 
  phone_number = phone; 
  dd=d ; mm=m ; yy=y;
  cout << "Personal Information Constructer" <<endl;
}
  void Personinformation :: show_perInfo(){
    cout << "Name : " << name <<endl;
    cout << "Gender : " << gender <<"\t Blood Type : "<<blood_type<<endl;
    cout << "Date of birth : " << dd <<"/" << mm << "/"<< yy<< "   Age : " <<endl;
    cout << "Underlying disease : "<< per_disease <<endl;
    cout << "Phone Number : " << phone_number<<endl;
    Address :: show_node();
  }
  void Personinformation :: changeName(string x){
    cout << "Name " << name << "  --> "<<x << endl;
    name =x;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changeGender(string x){
    cout << "Gender " << gender << "  --> "<<x << endl;
    gender = x;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changeBloodtype(string x){
    cout << "Blood Type " << blood_type << "  --> " << x << endl;
    blood_type = x;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changeDoB(){
    int x,y,z;
    cout << "Date of birth " << dd <<"/" << mm << "/"<< yy  << "  --> ";
    cin >> x>>y>>z;
    dd=x; mm=y; yy=z;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changeUdis(string x){
    cout << "Underlying disease " << per_disease << "  --> " << x << endl;
    per_disease = x;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changePhoneNo(string x){
    cout << "PhoneNo. " << phone_number << "  --> " << x << endl;
    phone_number = x;
    cout << "Change Successfully"<<endl;
    sleep(2);
  }
  void Personinformation :: changeAddress(string hn,string x,string y,string z){
      Address::changeAddress(hn,x,y,z); 
  }






class timeline:public Address,public NODE{
  private:
    int timein[3];
    int timeout[3];
    int D,M,Y,Do,Mo,Yo;
    string storename;
    string note;

  public:
    timeline(int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,string="Unknow",string="---",string="999",string="Nakorn Pathom", string="Phutthamonth",string="Salaya");
    ~timeline();
    void show_node(){
      cout << "Date " << D <<"/"<< M <<"/"<< Y<<" Time "<<timein[0]<<":"<<timein[1]<<":"<<timein[2] << " - "<<timeout[0]<<":"<<timeout[1]<<":"<<timeout[2] << " ==> "; 
      Address ::show_node();
    }
    
    int returnD(){return D;}
    int returnM(){return M;}
    int returnY(){return Y;}
    int* returntime(){return timein;}


    string returnStname(){return storename;}
    void show_St(){
      cout << "Store name : "<< storename << endl;
    }

    
};

timeline::timeline(int tih,int tim,int tis,int toh,int tom,int tos,int x,int o,int z,int a,int b, int c,string sn,string no,string H_Num,string prov,string dis,string sub_dis):Address(H_Num,prov,dis,sub_dis){
  timein[0]=tih;
  timein[1]=tim;
  timein[2]=tis;

  timeout[0]=toh;
  timeout[1]=tom;
  timeout[2]=tos;

  D = x;
  M = o;
  Y = z;
  Do=a;
  Mo=b;
  Yo=c;
  storename= sn;
  note = no;
}
timeline::~timeline(){
  cout<<"Delete Timeline"<<endl;
}


#endif