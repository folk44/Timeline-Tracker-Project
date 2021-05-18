#include <iostream>
#include<cstdlib>
#include <stdlib.h>
#include<exception>
#include<unistd.h>
#include<string>
#include <ctype.h>
#include <ctime>
#include"time.h"
using namespace std;
time_t now = time(0);
tm *ltm = localtime(&now);
#include"NODE.h"
#include "class.h"
#include"LL.h"
#include"time.h"
#include <cstring>
 


int Add_Place(LL *);
void Personal(Personinformation*&);

string sTouper(string x){
  int i;
   for (int i=0; i<x.length(); i++)
        x[i]=toupper(x[i]);
    return x;
}
void user_input(string text , string *input){
  cout<<text<<endl;
  cin>>*input;
  *input=sTouper(*input);
}

int main() {
  LL A;
  Personinformation *P=NULL;
  int ch;
  do{
  system("clear");
  cout<<"Timeline Tracker"<<endl<<endl;
  cout<<"1. Add place"<<endl;
  cout<<"2. Edit place"<<endl;
  cout<<"3. Personal info"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Please input your choice ...."<<endl;
  //do{
  cin>>ch;
  switch (ch)
  {
    case 1:{ch=Add_Place(&A);};break;
    case 2:{A.searchStname();ch=1;};break;
    case 3:{Personal(P);ch=1;}break;
    case 0:{ch=0;
      cout<<"Exit Program"<<endl;
      sleep(5);};break;
    default:{cout<<"Invalid choice!!"<<endl<<"Please input again..."; ch=0;};
  }
  //}while(ch!=0);
}while(ch!=0);


  /*LL A;
  NODE *t;
  Personinformation *P=NULL;
  t=new timeline(5,4,3,2,1);
  A.add_node(t);
  t=new timeline(10,9,8,7,6);
  A.add_node(t);
  int ch;
  do{
  system("clear");
  ch=0;
  cout<<"Timeline Tracker"<<endl<<endl;
  cout<<"1. Add place"<<endl;
  cout<<"2. Edit place"<<endl;
  cout<<"3. Personal info"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Please input your choice ...."<<endl;
  cin>>ch;
  switch (ch)
  {
    case 1:Add_Place();break;
    case 2:A.search();break;
    case 3:Personal(P) ;break;
    case 0:{
      cout<<"Exit Program"<<endl;
      sleep(5);};break;
    default:{};
  }
  }while(ch!=0);
  cout <<endl;
  
  LL A;
  NODE *t;
  
  t=new timeline(1,2,3,4,5);
  A.add_node(t);
  t=new timeline(5,4,3,2,1);
  A.add_node(t);
  t=new timeline(10,9,8,7,6);
  A.add_node(t);
  A.search();
  A.searchStname();*/
return 0;
}

void Personal(Personinformation *&P){
  if (P == NULL){
    system("clear");
     cout << " Identity Not found " <<endl;
     cout << "Do u want to register now ? (Y/N)"<<endl;
     char c;
     string name,gen,bt,pd,H_Num,prov,dis,sub_dis,phone;
     int d,m,y;
     cin >> c;
     c=toupper(c);
     if (c == 'Y'){
        cout << ">> Enter your Infomation <<"<<endl;
        cout << "Name : " ;
        cin >> name;
        name = sTouper(name);
        cout << "Gender : " ;
        cin >> gen;
        gen = sTouper(gen);
        cout << "Blood Type : ";
        cin >> bt;
        bt = sTouper(bt);
        cout << "Date of birth : " ;
        cin >> d >> m >> y;
        cout << "Underlying disease : ";
        cin >> pd;
        pd = sTouper(pd);
        cout << "Phone Number : ";
        cin >> phone;
        cout<<"Input house number : ";
        cin>>H_Num;
        cout<<"Input province : ";
        cin>>prov;
        prov = sTouper(prov);
        cout<<"Input district : ";
        cin>>dis;
        dis = sTouper(dis);
        cout<<"Input sub-distict : ";
        cin>>sub_dis;
        sub_dis = sTouper(sub_dis);
        P=new Personinformation(name, d, m, y, phone, gen, bt, pd,H_Num,prov,dis,sub_dis);
     }
  }
  else {
    char c;
    int chck;
    do{
    system("clear");
    P->show_perInfo();
    cout << "1)Edit information "<<endl;
    cout << "2)Return to menu"<<endl;
    cin>>c;
    if (c == '1'){
       do{
        system("clear");
      string hn,x,y,z;
      cout << "Which information that u want to change"<<endl;
      cout << "1) Name"<<endl;
      cout << "2) Gender"<<endl;
      cout << "3) Blood type"<<endl;
      cout << "4) Date of birth"<<endl;
      cout << "5) Underlying disease"<<endl;
      cout << "6) Phone Number"<<endl;
      cout << "7) Address"<<endl;
      cout << "0) Exit"<<endl;
     
      chck=0;
      cin >> chck;
      switch (chck){
        case 1 : {cout << "Change Name to "; cin>>x; 
                  x = sTouper(x);P->changeName(x) ;}
                  break;
        case 2 : {cout << "Change Gender to "; cin>>x; 
                  x = sTouper(x);P->changeGender(x) ;}
                  break;
        case 3 : {cout << "Change Blood type to "; cin>>x; 
                  x = sTouper(x);P->changeBloodtype(x) ;}
                  break;
        case 4 :  P->changeDoB() ;
                  break;
        case 5 : {cout << "Change Underlying disease to "; cin>>x; 
                  x = sTouper(x);P->changeUdis(x) ;}
                  break;
        case 6 : {cout << "Change Phone Number to "; cin>>x; 
                  x = sTouper(x);P->changePhoneNo(x) ;}
                  break;
        case 7 : {
                  cout<<"Input house number : ";
                  cin>>hn;
                  hn = sTouper(hn);
                  cout<<"Input province : ";
                   cin>>z;
                  z = sTouper(z);
                  cout<<"Input district : ";
                  cin>>y;
                  y = sTouper(y);
                  cout<<"Input sub-distict : ";
                  cin>>x;
                  x = sTouper(x);
                  P->changeAddress(hn,x,y,z) ;}
                  break;
        case 0 : break;
        default:{};
      }
      } while(chck !=0);
    }
  }while (c != 0);
}}


int Add_Place(LL *A){
  NODE *t;
  int ti[3],to[3], D, M, Y;
  string s_name, note, H_Num, prov, dis, sub_dis;
  char check1,check2,check3;
  int ch=0;
  system("clear");
  
  cout<<"Timeline Tracker"<<endl<<endl;
  user_input("Input house number : " ,&H_Num);
  cout<<"Input store name : "<<endl;
  cin>>s_name;
  cout<<"Input province : "<<endl;
  cin>>prov;
  cout<<"Input district : "<<endl;
  cin>>dis;
  cout<<"Input sub-distict : "<<endl;
  cin>>sub_dis;
  cout<<"Input note : "<<endl;
  cin>>note;
  cout<<"Date is "<<ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<<1900 + ltm->tm_year<<" (Y/N)"<<endl;
	cin>>check1;
  check1=toupper(check1);
  do{
    switch(check1){
      case 'Y':{ch=1;
        D=ltm->tm_mday;
        M=1 + ltm->tm_mon;
        Y=1900 + ltm->tm_year;
      };break;
      case 'N':{ch=1;
      cout<<"Input date (dd/mm/yyyy): ";
      cin>>D;
      cin.ignore();
      cin>>M;
      cin.ignore();
      cin>>Y;
      };break;
      default:{ch=0;
      cout<<"Invalid choice!!"<<endl<<"Please input again...";
      }
    }
  }while(ch==0);
  cout << "Time in is "<<5+ltm->tm_hour << ":" << 30+ltm->tm_min << ":"<<ltm->tm_sec <<" (Y/N)"<<endl;
  cin>>check2;
  check2=toupper(check2);
  do{
    switch(check2){
      case 'Y':{ch=1;
        ti[0]=5+ltm->tm_hour;
        ti[1]=30+ltm->tm_min;
        ti[2]=ltm->tm_sec;
      };break;
      case 'N':{ch=1;
      cout<<"Input time (hh:mm:ss): ";
      cin>>ti[0];
      cin.ignore();
      cin>>ti[1];
      cin.ignore();
      cin>>ti[2];
      };break;
      default:{ch=0;
      cout<<"Invalid choice!!"<<endl<<"Please input again...";
      }
    }
  }while(ch==0);


  //show INFO
  system("clear");
  cout<<"House number : "<<H_Num<<endl;
  cout<<"Store name : "<<s_name<<endl;
  cout<<"Province : "<<prov<<endl;
  cout<<"District : "<<dis<<endl;
  cout<<"Sub-district : "<<sub_dis<<endl;  
  cout<<"note : "<<note<<endl; 
  cout<<"Date : "<<D<<'/'<<M<<'/'<<Y<<endl; 
  cout<<"Time : "<<ti[0]<<':'<<ti[1]<<':'<<ti[2]<<endl; 
  
  cout << "Press Enter to Check out...";
  cin.ignore();
  cout << "Time out is "<<5+ltm->tm_hour << ":" << 30+ltm->tm_min << ":"<<ltm->tm_sec <<" (Y/N)"<<endl;
  cin>>check3;
  check3=toupper(check3);
  do{
    switch(check3){
      case 'Y':{ch=1;
        to[0]=5+ltm->tm_hour;
        to[1]=30+ltm->tm_min;
        to[2]=ltm->tm_sec;
      };break;
      case 'N':{ch=1;
      cout<<"Input time (hh:mm:ss): ";
      cin>>ti[0];
      cin.ignore();
      cin>>ti[1];
      cin.ignore();
      cin>>ti[2];
      };break;
      default:{ch=0;
      cout<<"Invalid choice!!"<<endl<<"Please input again...";
      }
    }
  }while(ch==0);

  t=new timeline(ti[0],ti[1],ti[2],to[0],to[1],to[2],D,M,Y,s_name,note,H_Num,prov,dis,sub_dis);
  A->add_node(t);

  cin.clear();
  cin.ignore(100,'\n');

  cout<<"Checked out"<<endl;
  cout << "Press Enter to back to menu..."<<endl;
  cin.ignore();
return 1;
}

