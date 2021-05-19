#include <iostream>
#include<cstdlib>
#include <stdlib.h>
#include<exception>
#include<unistd.h>
#include<string>
#include <ctype.h>
#include <ctime>
#include <limits>
#include"time.h"
using namespace std;

#include"NODE.h"
#include "class.h"
#include"LL.h"
#include <cstring>
 


int Add_Place(LL *);
void Personal(Personinformation*&);
void Showmenu(LL *);

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
  //int ch;
  string ch;
  do{
  A.rw_node();
  system("clear");
  cout<<"Timeline Tracker"<<endl<<endl;
  cout<<"1. Add place"<<endl;
  cout<<"2. Show place"<<endl;
  cout<<"3. Personal info"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Please input your choice ...."<<endl;
  try{
  cin>>ch;
    if (ch!="1" && ch!="2" && ch!="3" && ch!="0")
      throw inchoice;
   switch (ch[0])
    {
     //case '1':{Add_Place(&A);}break;
     case '2':{Showmenu(&A);}break;
     case '3':{Personal(P);}break;
     case '0':{
       cout<<"Exit Program"<<endl;
       sleep(5);};break;
     default:{};
    }
  }
  catch(exception& e){
    cout<<e.what()<<endl;
    cin.clear();// fflush(stdin)
    cin.ignore(100,'\n');
    sleep(1);
  }
 /* catch(const char *error){
    cerr<<error;
    cout<<endl;
    cin.clear();// fflush(stdin)
    cin.ignore(100,'\n');
    sleep(1);
   }*/
}while(ch!="0");
return 0;
}
void Showmenu(LL *A){
  string c;
  string temp;
  do{
  system("clear");
  cout<<"Timeline Tracker"<<endl<<endl;
  cout<<"1. Show All Timeline" << endl;
  cout<<"2. Search Date "<<endl;
  cout<<"3. Search Store Name "<<endl;
  cout<<"0. Back to main menu"<<endl;
  cout<<"Please input your choice ...."<<endl;
  try{
    cin >> c;
    if (c!="1" && c!="2" && c!="3" && c!="0")
      throw inchoice;
     switch (c[0]){
        case '1':A->show_all();cin.ignore();cin.ignore();break;
        case '2':A->search();cin.ignore();cin.ignore();break;
        case '3':A->searchStname();cin.ignore();cin.ignore();break;
        case '0':cout << "Back to main menu"<<endl;sleep(2);break;
    }
  }
  catch(exception& e){
    cout<<e.what()<<endl;
    cin.clear();// fflush(stdin)
    cin.ignore(100,'\n');
    sleep(1);
  }
  }while(c!="0");
}
void Personal(Personinformation *&P){
  if (P == NULL){
    char c;
    string name,gen,bt,pd,H_Num,prov,dis,sub_dis,phone;
    int d,m,y;
    do{
    system("clear");
     cout << " Identity Not found " <<endl;
     cout << "Do u want to register now ? (Y/N)"<<endl;
    try{
     cin >> c;
     c=toupper(c);
      if (c!='Y' && c!='N')
        throw "Invalid choice!! \n Please input again...";
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
      catch(exception& e){
         cout<<e.what()<<endl;
       }
      catch(const char *error){
        cerr<<error;
        cout<<endl;
        cin.clear();// fflush(stdin)
        cin.ignore(100,'\n');
        
      } 
     }while(c != 'N');
     cout << "Back to main menu" <<endl; sleep(2);
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
   //  try{
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
     //}
      } while(chck !=0);
    }
  }while (c != 0);
 }
}

/*
int Add_Place(LL *A){
  NODE *t;
  int ti[3],to[3], D, M, Y,Do,Mo,Yo;
  string s_name, note, H_Num, prov, dis, sub_dis;
  string check1,check2,check3,check4;
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
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int HT;
  if(7+ltm->tm_hour>24) HT=7+ltm->tm_hour-24;
  else HT=7+ltm->tm_hour;
  cout<<"Date is "<<ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<<1900 + ltm->tm_year<<" (Y/N)"<<endl;
	do{
  cin.clear();
  cin.ignore(100,'\n');
  cin>>check1;
  check1=sTouper(check1);
  if(check1.compare("Y")==0){

  }

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
      cout<<"Invalid choice!!"<<endl<<"Please input again..."<<endl;
      }
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);
  cout << "Time in is "<<HT<< ":" << ltm->tm_min << ":"<<ltm->tm_sec <<" (Y/N)"<<endl;
  do{
  cin>>check2;
  check2=toupper(check2);
    switch(check2){
      case 'Y':{ch=1;
        ti[0]=HT;
        ti[1]=ltm->tm_min;
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
      cout<<"Invalid choice!!"<<endl<<"Please input again..."<<endl;
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
  sleep(2);

  cout << "Press Enter to Check out..."<<endl;
  cin.get();
  time_t now1 = time(0);
  tm *ltm1 = localtime(&now1);
  if(7+ltm1->tm_hour>24) HT=7+ltm1->tm_hour-24;
  else HT=7+ltm1->tm_hour;
  cout<<"Date is "<<Do<<"/"<<Mo<<"/"<<Yo<<" (Y/N)"<<endl;
	do{
  cin>>check3;
  check3=toupper(check3);
    switch(check3){
      case 'Y':{ch=1;
        Do=ltm1->tm_mday;
        Mo=1 + ltm1->tm_mon;
        Yo=1900 + ltm1->tm_year;
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
      cout<<"Invalid choice!!"<<endl<<"Please input again..."<<endl;
      }
    }
  }while(ch==0);
  cout << "Time out is "<<HT<< ":" << ltm1->tm_min << ":"<<ltm1->tm_sec <<" (Y/N)"<<endl;
  do{
  cin>>check4;
  check4=toupper(check4);
    switch(check4){
      case 'Y':{ch=1;
        to[0]=HT;
        to[1]=ltm1->tm_min;
        to[2]=ltm1->tm_sec;
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
      cout<<"Invalid choice!!"<<endl<<"Please input again..."<<endl;
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
*/
