#ifndef class_h
#define class_h

class Address{
  private:
  string H_Number;
  string province;
  string district;
  string sub_district;
  public:
  Address(string="999",string="Nakorn Pathom",string="Phutthamonth",string="Salaya");
  ~Address();
};
Address::Address(string H_Num,string prov,string dis,string sub_dis):H_Number(H_Num),province(prov),district(dis),sub_district(sub_dis){ 
}
Address::~Address(){
  
};

class Personinformation:public Address{
  private :
  string name;
  string gender;
  string blood_type;
  string per_disease;
  int phone_number;
  int dd,mm,yy;
  public :
  Personinformation(string,int ,int ,int ,int,string = "Unknow",string = "Unknow",string = "---",string="999",string="Nakorn Pathom",string="Phutthamonth",string="Salaya");
  ~Personinformation();
};
Personinformation :: Personinformation(string n,int d,int m,int y,int phone,string gen,string bt,string pd,string H_Num,string prov,string dis,string sub_dis):Address (H_Num,prov,dis,sub_dis){
  name = n; 
  gender = gen; 
  blood_type = bt; 
  per_disease = pd; 
  phone_number = phone; 
  dd=d ; mm=m ; yy=y;
  cout << "Personal Information Constructer" <<endl;
}

class timeline:public Address,public NODE{
  private:
    int timein;
    int timeout;
    int D,M,Y;
    string storename;
    string note;

  public:
    timeline(int,int,int,int,int,string="Unknow",string="---",string="999",string="Nakorn Pathom", string="Phutthamonth",string="Salaya");
    ~timeline();
    virtual void show_node();
    void insert(timeline*&);
    void deleteN(timeline*&);
    timeline* move_next();
  
};

timeline::timeline(int ti,int to,int x,int o,int z,string sn,string no,string H_Num,string prov,string dis,string sub_dis):Address(H_Num,prov,dis,sub_dis){
  timein=ti;
  timeout=to;
  D = x;
  M = o;
  Y = z;
  storename= sn;
  note = no;

}
#endif