#include <iostream>
#include<cstdlib>
#include <stdlib.h>
#include<exception>
#include<unistd.h>
#include<string>
#include <ctype.h>
#include <ctime>
#include <iomanip>
#include <limits>
#include <sstream>
#include"time.h"
using namespace std;
#include"NODE.h"
#include "class.h"
#include"LL.h"
#include <cstring>



int Add_Place(LL *);
void Personal(Personinformation*&);
void Showmenu(LL *);
int StrToInt(string );
int checkDate(int ,int ,int );
int checkLeapYear(int );
int checkTime(int ,int ,int );

string sTouper(string x){
  int i;
   for (int i=0; i<x.length(); i++)
        x[i]=toupper(x[i]);
    return x;
}
void user_input(string text , string *input){
  cout<<endl<<text<<endl;
  cout<<"> ";
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
  cout<<"Timeline Tracker"<<endl;
  cout<<"------------------"<<endl<<endl;
  cout<<"1. Add place"<<endl;
  cout<<"2. Show place"<<endl;
  cout<<"3. Personal info"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Please input your choice ...."<<endl;
  cin>>ch;
  try{
    if (ch!="1" && ch!="2" && ch!="3" && ch!="0")
      throw inchoice;
   switch (ch[0])
    {
     case '1':{Add_Place(&A);}break;
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
    cout<<"> ";
    cin >> c;
    if (c!="1" && c!="2" && c!="3" && c!="0")
      throw inchoice;
     switch (c[0]){
        case '1':A->show_all();cout <<endl<< "Press Enter to back to menu...";cin.ignore();cin.ignore();break;
        case '2':A->search();cout <<endl<< "Press Enter to back to menu...";cin.ignore();cin.ignore();break;
        case '3':A->searchStname();cout <<endl<< "Press Enter to back to menu...";cin.ignore();cin.ignore();break;
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
    string c;
    string name,gen,bt,pd,H_Num,prov,dis,sub_dis,phone,D,M,Y;
    int d,m,y,x=0;
    do{
    system("clear");
     cout << " Identity Not found " <<endl;
     cout << "Do u want to register now ? (Y/N)"<<endl;
     cout << "> ";
    try{
     cin >> c;
     c[0]=toupper(c[0]);
      if (c!="Y" && c!="N")
        throw inchoice;
     if (c == "Y"){
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
        cout << "Date of birth (dd mm yyyy): " ;
          do{
             cout << "> ";
              cin.clear();
              cin >> D ;
              cin.ignore();
              cin>> M;
              cin.ignore(); 
              cin>> Y;
              d=StrToInt(D);
              m=StrToInt(M);
              y=StrToInt(Y);
              x = checkDate(d,m,y);
          }while(x!=1);
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
        c="N";
       }
      }
      catch(exception& e){
         cout<<e.what()<<endl;
         cin.clear();// fflush(stdin)
        cin.ignore(100,'\n');
        sleep(1);
       }
     }while(c != "N");
     cout << "Back to main menu" <<endl; sleep(2);
  }
  else {
    string c;
    string chck;
    do{
    system("clear");
    P->show_perInfo();
    cout << "1)Edit information "<<endl;
    cout << "2)Back to menu"<<endl;
    cout << "> ";
    try{
    cin>>c;
    if (c!="1" && c!="2")
      throw inchoice;
    if (c[0] == '1'){
       do{
        system("clear");
      string hn,x,y,z,D,M,Y;
      int ddd,mm,yy,k;
      cout << "Which information that u want to change"<<endl;
      cout << "1) Name"<<endl;
      cout << "2) Gender"<<endl;
      cout << "3) Blood type"<<endl;
      cout << "4) Date of birth"<<endl;
      cout << "5) Underlying disease"<<endl;
      cout << "6) Phone Number"<<endl;
      cout << "7) Address"<<endl;
      cout << "0) Exit"<<endl;
      cout << "> ";
      try{
      cin >> chck;
      if(chck!="2"&&chck!="3"&&chck!="4"&&chck!="5"&&chck!="6"&&chck!="7"&&chck!="0"&&chck!="1")
        throw inchoice;
      switch (chck[0]){
        case '1' : {cout << "Change Name to "; cin>>x; 
                  x = sTouper(x);P->changeName(x) ;}
                  break;
        case '2' : {cout << "Change Gender to "; cin>>x; 
                  x = sTouper(x);P->changeGender(x) ;}
                  break;
        case '3' : {cout << "Change Blood type to "; cin>>x; 
                  x = sTouper(x);P->changeBloodtype(x) ;}
                  break;
        case '4' :  {cout << "Change Date of birth to "<<endl;
                     do{
                          cout << "> ";
                          cin.clear();
                          cin >> D ; 
                          cin.ignore();
                          cin>> M ;
                          cin.ignore(); 
                          cin>> Y ;
                          ddd=StrToInt(D);
                          mm=StrToInt(M);
                          yy=StrToInt(Y);
                          k = checkDate(ddd,mm,yy);
          }while(k != 1 );
                  P->changeDoB(ddd,mm,yy) ;}
                  break;
        case '5' : {cout << "Change Underlying disease to "; cin>>x; 
                  x = sTouper(x);P->changeUdis(x) ;}
                  break;
        case '6' : {cout << "Change Phone Number to "; cin>>x; 
                  x = sTouper(x);P->changePhoneNo(x) ;}
                  break;
        case '7' : {
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
        case '0' : break;
        default:{};
      }
     }catch(exception& e){
         cout<<e.what()<<endl;
         cin.clear();// fflush(stdin)
         cin.ignore(100,'\n');
         sleep(2);
       }
      } while(chck[0] !='0');
    }
    }
    catch(exception& e){
         cout<<e.what()<<endl;
         cin.clear();// fflush(stdin)
         cin.ignore(100,'\n');
         sleep(2);
       }
  }while (c[0] != '2');
 }
}


int Add_Place(LL *A){
  NODE *t;
  int ti[3],to[3], D, M, Y,Do,Mo,Yo;
  string s_name, note, H_Num, prov, dis, sub_dis;
  string check1,check2,check3,check4;
  int ch=0;
  system("clear");
  
  cout<<"Timeline Tracker"<<endl<<endl;
  user_input("Input house number : " ,&H_Num);
  user_input("Input store name : " ,&s_name);
  user_input("Input province : " ,&prov);
  user_input("Input district : " ,&dis);
  user_input("Input sub-distict : " ,&sub_dis);
  user_input("Input note : " ,&note);

  time_t now = time(0);
  tm *ltm = localtime(&now);
  cout<<endl<<"#Check in"<<endl;
  cout<<"Date is "<<setfill('0')<<setw(2)<<ltm->tm_mday<<"/"<<setfill('0')<<setw(2)<<1 + ltm->tm_mon<<"/"<<setfill('0')<<setw(2)<<1900 + ltm->tm_year<<" (Y/N)"<<endl;
	do{
  cout<<"> ";
  cin>>check1;
  check1=sTouper(check1);
  try{
  if (check1!="Y" && check1!="N") throw inchoice;
    switch (check1[0]){
      case 'Y':{ch=1;
        D=ltm->tm_mday;
        M=1 + ltm->tm_mon;
        Y=1900 + ltm->tm_year;
      };break;
      case 'N':{ch=1;
        int x=0;
        string d,m,y;
        cout<<endl<<"Input date (dd mm yyyy): ";
          do{
              cin.clear();

              cin >> d ;
              cin.ignore();
              cin>> m;
              cin.ignore(); 
              cin>> y;
              D=StrToInt(d);
              M=StrToInt(m);
              Y=StrToInt(y);
              x = checkDate(D,M,Y);
          }while(x!=1);
      };break;
    }
  }
    catch(exception& e){
      cout<<endl<<e.what()<<endl;
      sleep(1);
      ch=0;
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);
  
  cout <<endl<< "Time is "<<setfill('0')<<setw(2)<<7+ltm->tm_hour<< ":" << setfill('0')<<setw(2)<<ltm->tm_min << ":"<<setfill('0')<<setw(2)<<ltm->tm_sec <<" (Y/N)"<<endl;
  do{
  cout<<"> ";
  cin>>check2;
  check2=sTouper(check2);
  try{
    if (check2!="Y" && check2!="N") throw inchoice;
    switch(check2[0]){
      case 'Y':{ch=1;
        ti[0]=7+ltm->tm_hour;
        ti[1]=ltm->tm_min;
        ti[2]=ltm->tm_sec;
      };break;
      case 'N':{ch=1;
      string H,M,S;
      int x=0;
      cout<<endl<<"Input time (hh:mm:ss): ";
      do{
      cin.clear();
      
      cin>>H;
      cin.ignore();
      cin>>M;
      cin.ignore();
      cin>>S;
      ti[0]=StrToInt(H);
      ti[1]=StrToInt(M);
      ti[2]=StrToInt(S);
      x=checkTime(ti[0],ti[1],ti[2]);
      }while(x!=1);
      };break;
    }
  }
  catch(exception& e){
      cout<<endl<<e.what()<<endl;
      sleep(2);
      ch=0;
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);


  //show INFO
  system("clear");
  cout<<"House number : "<<H_Num<<endl;
  cout<<"Store name : "<<s_name<<endl;
  cout<<"Province : "<<prov<<endl;
  cout<<"District : "<<dis<<endl;
  cout<<"Sub-district : "<<sub_dis<<endl;  
  cout<<"note : "<<note<<endl; 
  cout<<"Date : "<<setfill('0')<<setw(2)<<D<<'/'<<setfill('0')<<setw(2)<<M<<'/'<<Y<<endl; 
  cout<<"Time : "<<setfill('0')<<setw(2)<<ti[0]<<':'<<setfill('0')<<setw(2)<<ti[1]<<':'<<ti[2]<<endl<<endl; 
  cout<<"*** Checked in ***"<<endl<<endl;
  sleep(2);

  cout << "Press Enter to Check out...";
  cin.get();

  time_t now1 = time(0);
  tm *ltm1 = localtime(&now1);
  cout<<endl<<"#Check out"<<endl;
  cout<<"Date is "<<setfill('0')<<setw(2)<<D<<"/"<<setfill('0')<<setw(2)<<M<<"/"<<setfill('0')<<setw(2)<<Y<<" (Y/N)"<<endl;
	do{
  cout<<"> ";
  cin>>check3;
  check3=sTouper(check3);
  try{
  if (check3!="Y" && check3!="N") throw inchoice;
    switch(check3[0]){
      case 'Y':{ch=1;
        Do=D;
        Mo=M;
        Yo=Y;
      };break;
      case 'N':{ch=1;
        int x=0;
        string d,m,y;
        cout<<endl<<"Input date (dd mm yyyy): ";
          do{
              cin.clear();

              cin >> d ;
              cin.ignore();
              cin>> m;
              cin.ignore(); 
              cin>> y;
              Do=StrToInt(d);
              Mo=StrToInt(m);
              Yo=StrToInt(y);
              x = checkDate(Do,Mo,Yo);
          }while(x!=1);
      };break;
      }
    }
    catch(exception& e){
      cout<<endl<<e.what()<<endl;
      sleep(1);
      ch=0;
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);

  cout << "Time out is "<<setfill('0')<<setw(2)<<7+ltm1->tm_hour<< ":" << setfill('0')<<setw(2)<<ltm1->tm_min << ":"<<setfill('0')<<setw(2)<<ltm1->tm_sec <<" (Y/N)"<<endl;
  do{
  cout<<"> ";
  cin>>check4;
  check4=sTouper(check4);
  try{
  if (check4!="Y" && check4!="N") throw inchoice;
    switch(check4[0]){
      case 'Y':{ch=1;
        to[0]=7+ltm1->tm_hour;
        to[1]=ltm1->tm_min;
        to[2]=ltm1->tm_sec;
      };break;
      case 'N':{ch=1;
      string H,M,S;
      int x=0;
      cout<<"Input time (hh:mm:ss): ";
      do{
      cin.clear();

      cin>>H;
      cin.ignore();
      cin>>M;
      cin.ignore();
      cin>>S;
      to[0]=StrToInt(H);
      to[1]=StrToInt(M);
      to[2]=StrToInt(S);
      x=checkTime(to[0],to[1],to[2]);
      }while(x!=1);
      };break;
    }
  }
    catch(exception& e){
      cout<<endl<<e.what()<<endl;
      sleep(1);
      ch=0;
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);

  t=new timeline(ti[0],ti[1],ti[2],to[0],to[1],to[2],D,M,Y,Do,Mo,Yo,s_name,note,H_Num,prov,dis,sub_dis);
  A->add_node(t);

  cin.clear();
  //cin.ignore(10000,'\n');
  cout<<"*** Checked out ***"<<endl;
  sleep(2);
  cout << "Press Enter to back to menu...";
  cin.ignore();
return 1;
}

int StrToInt(string x){
  int y;
  stringstream geek(x);
  geek >> y;
  return y;
}

int checkDate(int d,int m,int y){
  int x,ly;
  ly = checkLeapYear(y);
  try{
    if (d<=0||m<=0||y<=0 || m > 12 || d > 31 ) throw indate;
    else if (m==2 && d > 29) throw indate;
    else if (m==2 && ly==0 && d==29) throw indate;
    else if (d==31){
      if(m==4 ||m==6 ||m==9 ||m==11 ) throw indate;
     }
    x=1;
  }
  catch(exception& e){
      cout<<e.what()<<endl;
      cin.clear();// fflush(stdin)
      cin.ignore(100,'\n');
       sleep(1);
      x=0;
  }
  return (x);
}
int checkLeapYear(int year){
  int check;// = 1 LeapYear // = 0 not LeapYear
  if (year%4!=0) check=0;
  else if (year%100!=0) check=1;
  else if (year%400!=0) check=0;
  else check=1;
  return check;
}

int checkTime(int h ,int m,int s){
  int x;
  try{
        if (h>=24 || h<0 ||m>=60 || m<0 ||s>=60 || s<0 ) throw indate;
    x=1;
  }
  catch(exception& e){
      cout<<e.what()<<endl;
      cin.clear();// fflush(stdin)
      cin.ignore(100,'\n');
       sleep(1);
      x=0;
  }
  return (x);
}

// Timeline Tracker Project | Mahidol Unibersity | EGCO 112 | 23 / 4 / 2021 - 19 / 5 / 2021
// Project team 
//  1)6313138 Yutthasat Phoncharoenpong
//  2)6313175 Thanaphat Sae-Be
//  3)6313210 Krittawat Thongnoppakao