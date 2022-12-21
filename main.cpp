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
#include"Decor.h"



int Add_Place(LL *);
void Personal(Personinformation*&);
void Showmenu(LL *);
int StrToInt(string );
int checkDate(int ,int ,int );
int checkLeapYear(int );
int checkTime(int ,int ,int );
void changeTimezone(tm *);

string sTouper(string x){
  int i;
   for (int i=0; i<x.length(); i++)
        x[i]=toupper(x[i]);
    return x;
}
void user_input(string text , string *input){
  cout<<" "<<text<<endl;
  cout<<" > ";
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
  head();//Decor
  cout<<"\t\t\t>>MENU<<"<<endl;
  cout<<"\t1) Add Place"<<endl;
  cout<<"\t2) Show Place"<<endl;
  cout<<"\t3) Personal Info"<<endl;
  cout<<"\t0) Exit"<<endl;
  PleIn();//Decor
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
  head();//Decor
  cout<<"\t\t  >> MENU <<"<<endl;
  cout<<"\t1) Show All Timeline" << endl;
  cout<<"\t2) Search Date "<<endl;
  cout<<"\t3) Search Store Name "<<endl;
  cout<<"\t0) Back to Main Menu"<<endl;
  PleIn();//Decore
  try{
    cin >> c;
    if (c!="1" && c!="2" && c!="3" && c!="0")
      throw inchoice;
     switch (c[0]){
        case '1':A->show_all();cout <<endl<<"--------------------------------"<<endl<<" Press Enter to Go Back...";cin.ignore();cin.ignore();break;
        case '2':A->search();cout <<endl<<"--------------------------------"<<endl<< " Press Enter to Go Back...";cin.ignore();cin.ignore();break;
        case '3':A->searchStname();cout<<endl<<"--------------------------------"<<endl<< " Press Enter to Go Back...";cin.ignore();cin.ignore();break;
        case '0':cout << " Back to Main Menu"<<endl;sleep(2);break;
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
    string name[2],gen,bt,pd,H_Num,prov,dis,sub_dis,phone,D,M,Y;
    int d,m,y,x=0;
    do{
    system("clear");
    head();
     cout << "\t  Identity Not Found!! " <<endl<<endl;
     cout << " Do You Want to Register Now ? (Y/N)"<<endl;
     cout << " > ";
    try{
     cin >> c;
     cout<<"--------------------------------"<<endl;
     c[0]=toupper(c[0]);
      if (c!="Y" && c!="N")
        throw inchoice;
     if (c == "Y"){
        cout <<endl<< "  >> Enter Your Information <<"<<endl<<endl;
        cout << " Name"<<endl<<" > ";
        cin >> name[0];
        name[0] = sTouper(name[0]);
        cout << " Surname"<<endl<<" > ";
        cin >> name[1];
        name[1] = sTouper(name[1]);
        cout << " Gender"<<endl<<" > " ;
        cin >> gen;
        gen = sTouper(gen);
        cout << " Blood Type"<<endl<<" > ";
        cin >> bt;
        bt = sTouper(bt);
        cout << " Date of birth (dd mm yyyy)"<<endl;
          do{
             cout << " > ";
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
        cout << " Underlying Disease"<<endl<<" > ";
        cin >> pd;
        pd = sTouper(pd);
        cout << " Phone Number"<<endl<<" > ";
        cin >> phone;
        cout<<" Input House Number"<<endl<<" > ";
        cin>>H_Num;
        cout<<" Input Province"<<endl<<" > ";
        cin>>prov;
        prov = sTouper(prov);
        cout<<" Input District"<<endl<<" > ";
        cin>>dis;
        dis = sTouper(dis);
        cout<<" Input Sub-Distict"<<endl<<" > ";
        cin>>sub_dis;
        sub_dis = sTouper(sub_dis);
        P=new Personinformation(name[0],name[1], d, m, y, phone, gen, bt, pd,H_Num,prov,dis,sub_dis);
        c="N";
       }
      }
      catch(exception& e){
         cout<<e.what()<<endl;
         cin.clear();// fflush(stdin)
        cin.ignore(100,'\n');
        sleep(2);
       }
     }while(c != "N");
     cout << " Back to Main Menu" <<endl; sleep(2);
  }
  else {
    string c;
    string chck;
    do{
    system("clear");
    head();
    P->show_perInfo();
    cout<<"--------------------------------"<<endl;
    cout<<"\t\t  >> MENU <<"<<endl<<endl;
    cout << "\t1) Edit Information "<<endl;
    cout << "\t2) Back to Menu"<<endl;
    PleIn();
    try{
    cin>>c;
    if (c!="1" && c!="2")
      throw inchoice;
    if (c[0] == '1'){
       do{
        system("clear");
      string hn,x,y,z,D,M,Y;
      int ddd,mm,yy,k;
      head();//Decor
      cout << " >>Edit Personal Information <<"<<endl<<endl;
      cout << " 1) Name"<<endl;
      cout << " 2) Surname"<<endl;
      cout << " 3) Gender"<<endl;
      cout << " 4) Blood Type"<<endl;
      cout << " 5) Date of Birth"<<endl;
      cout << " 6) Underlying Disease"<<endl;
      cout << " 7) Phone Number"<<endl;
      cout << " 8) Address"<<endl;
      cout << " 0) Exit"<<endl;
      cout<<"--------------------------------"<<endl;
      cout << " Which Information that You Want to Change?"<<endl;
      cout << " > ";
      try{
      cin >> chck;
      if(chck!="2"&&chck!="3"&&chck!="4"&&chck!="5"&&chck!="6"&&chck!="7"&&chck!="8" &&chck!="0"&&chck!="1")
        throw inchoice;
      switch (chck[0]){
        case '1' : {cout << " Change Name to -->"; cin>>x; 
                  x = sTouper(x);P->changeName(x) ;}
                  break;
        case '2' : {cout << " Change Surname to -->"; cin>>x; 
                  x = sTouper(x);P->changeSurName(x) ;}
                  break;
        case '3' : {cout << " Change Gender to -->"; cin>>x; 
                  x = sTouper(x);P->changeGender(x) ;}
                  break;
        case '4' : {cout << " Change Blood type to -->"; cin>>x; 
                  x = sTouper(x);P->changeBloodtype(x) ;}
                  break;
        case '5' :  {cout << " Change Date of birth to -->"<<endl;
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
        case '6' : {cout << " Change Underlying disease to -->"; cin>>x; 
                  x = sTouper(x);P->changeUdis(x) ;}
                  break;
        case '7' : {cout << " Change Phone Number to -->"; cin>>x; 
                  x = sTouper(x);P->changePhoneNo(x) ;}
                  break;
        case '8' : {
                  cout<<" Input house number : ";
                  cin>>hn;
                  hn = sTouper(hn);
                  cout<<" Input province : ";
                   cin>>z;
                  z = sTouper(z);
                  cout<<" Input district : ";
                  cin>>y;
                  y = sTouper(y);
                  cout<<" Input sub-distict : ";
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
  head();//Decor
  cout<<endl<<"    >> Place Information <<"<<endl<<endl;
  user_input("Input house number" ,&H_Num);
  user_input("Input store name" ,&s_name);
  user_input("Input province" ,&prov);
  user_input("Input district" ,&dis);
  user_input("Input sub-distict" ,&sub_dis);
  user_input("Input note" ,&note);
  cout<<"--------------------------------"<<endl;
  string exit;
  cout<<endl<<" Is the Place Information Correct? (Y/N)"<<endl;
  do{
  cout<<" > ";
  cin>>exit;
  exit=sTouper(exit);
  try{
    if (exit!="Y" && exit!="N") throw inchoice;
    switch(exit[0]){
      case 'Y':{ch=1;}break;
      case 'N':{ch=1;
      cout<<" Back to Menu...";
      return 1;}break;
    }
  }
  catch(exception& e){
      cout<<e.what()<<endl;
      ch=0;
    }
    cin.clear();
    cin.ignore(100,'\n');
  }while(ch==0);
  cout<<"--------------------------------"<<endl;

  time_t now = time(0);
  tm *ltm = localtime(&now);
  changeTimezone(ltm);
  cout<<endl<<" #Check In"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<ltm->tm_mday<<"/"<<setfill('0')<<setw(2)<<1 + ltm->tm_mon<<"/"<<setfill('0')<<setw(2)<<1900 + ltm->tm_year<<" (Y/N)"<<endl;
	do{
  cout<<" > ";
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
        cout<<" Input date (dd mm yyyy)"<<endl;
          do{
              cin.clear();
              cout<<" > ";
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
  
  cout << " Time : "<<setfill('0')<<setw(2)<<ltm->tm_hour<< ":" << setfill('0')<<setw(2)<<ltm->tm_min << ":"<<setfill('0')<<setw(2)<<ltm->tm_sec <<" (Y/N)"<<endl;
  do{
  cout<<" > ";
  cin>>check2;
  check2=sTouper(check2);
  try{
    if (check2!="Y" && check2!="N") throw inchoice;
    switch(check2[0]){
      case 'Y':{ch=1;
        ti[0]=ltm->tm_hour;
        ti[1]=ltm->tm_min;
        ti[2]=ltm->tm_sec;
      };break;
      case 'N':{ch=1;
      string H,M,S;
      int x=0;
      cout<<" Input time (hh mm ss)"<<endl;
      do{
      cin.clear();
      cout<<" > ";
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
  head();//Decor
  cout<<endl<<"    >> Place Information <<"<<endl<<endl;
  cout<<" House Number : "<<H_Num<<endl;
  cout<<" Store Name : "<<s_name<<endl;
  cout<<" Province : "<<prov<<endl;
  cout<<" District : "<<dis<<endl;
  cout<<" Sub-District : "<<sub_dis<<endl;  
  cout<<" Note : "<<note<<endl; 
  cout<<"--------------------------------"<<endl;
  cout<<endl<<" #Checked In"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<D<<'/'<<setfill('0')<<setw(2)<<M<<'/'<<Y<<endl; 
  cout<<" Time : "<<setfill('0')<<setw(2)<<ti[0]<<':'<<setfill('0')<<setw(2)<<ti[1]<<':'<<setfill('0')<<setw(2)<<ti[2]<<endl<<endl;
  cout<<"--------------------------------"<<endl; 
  sleep(2);

  cout << " Press Enter to Check out...";
  cin.get();

  time_t now1 = time(0);
  tm *ltm1 = localtime(&now1);
  changeTimezone(ltm1);
  system("clear");
  head();//Decor
  cout<<endl<<"    >> Place Information <<"<<endl<<endl;
  cout<<" House Number : "<<H_Num<<endl;
  cout<<" Store Name : "<<s_name<<endl;
  cout<<" Province : "<<prov<<endl;
  cout<<" District : "<<dis<<endl;
  cout<<" Sub-District : "<<sub_dis<<endl;  
  cout<<" Note : "<<note<<endl; 
  cout<<"--------------------------------"<<endl;
  cout<<endl<<" #Checked In"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<D<<'/'<<setfill('0')<<setw(2)<<M<<'/'<<Y<<endl; 
  cout<<" Time : "<<setfill('0')<<setw(2)<<ti[0]<<':'<<setfill('0')<<setw(2)<<ti[1]<<':'<<setfill('0')<<setw(2)<<ti[2]<<endl<<endl;
  cout<<"--------------------------------"<<endl; 
  cout<<endl<<" #Check Out"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<D<<"/"<<setfill('0')<<setw(2)<<M<<"/"<<Y<<" (Y/N)"<<endl;
	do{
  cout<<" > ";
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
        cout<<" Input date (dd mm yyyy)"<<endl;
          do{
              cin.clear();
              cout<<" > ";
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

  cout << " Time out is "<<setfill('0')<<setw(2)<<ltm1->tm_hour<< ":" << setfill('0')<<setw(2)<<ltm1->tm_min << ":"<<setfill('0')<<setw(2)<<ltm1->tm_sec <<" (Y/N)"<<endl;
  do{
  cout<<" > ";
  cin>>check4;
  check4=sTouper(check4);
  try{
  if (check4!="Y" && check4!="N") throw inchoice;
    switch(check4[0]){
      case 'Y':{ch=1;
        to[0]=ltm1->tm_hour;
        to[1]=ltm1->tm_min;
        to[2]=ltm1->tm_sec;
      };break;
      case 'N':{ch=1;
      string H,M,S;
      int x=0;
      cout<<" Input time (hh mm ss)"<<endl;
      do{
      cin.clear();
      cout<<" > ";
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
  system("clear");
  head();//Decor
  cout<<endl<<"    >> Place Information <<"<<endl<<endl;
  cout<<" House Number : "<<H_Num<<endl;
  cout<<" Store Name : "<<s_name<<endl;
  cout<<" Province : "<<prov<<endl;
  cout<<" District : "<<dis<<endl;
  cout<<" Sub-District : "<<sub_dis<<endl;  
  cout<<" Note : "<<note<<endl; 
  cout<<"--------------------------------"<<endl;
  cout<<endl<<" #Checked In"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<D<<'/'<<setfill('0')<<setw(2)<<M<<'/'<<Y<<endl; 
  cout<<" Time : "<<setfill('0')<<setw(2)<<ti[0]<<':'<<setfill('0')<<setw(2)<<ti[1]<<':'<<setfill('0')<<setw(2)<<ti[2]<<endl<<endl;
  cout<<"--------------------------------"<<endl; 
  cout<<endl<<" #Checked Out"<<endl<<endl;
  cout<<" Date : "<<setfill('0')<<setw(2)<<Do<<'/'<<setfill('0')<<setw(2)<<Mo<<'/'<<Yo<<endl; 
  cout<<" Time : "<<setfill('0')<<setw(2)<<to[0]<<':'<<setfill('0')<<setw(2)<<to[1]<<':'<<setfill('0')<<setw(2)<<to[2]<<endl<<endl;
  cout<<"--------------------------------"<<endl;

  cin.clear();
  sleep(2);
  cout <<endl<< "Press Enter to back to menu...";
  cin.ignore(10000,'\n');
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
        if (h>=24 || h<0 ||m>=60 || m<0 ||s>=60 || s<0 ) throw intime;
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

void changeTimezone(tm *T){
  int ly;
  ly = checkLeapYear(T->tm_year);
  if (T->tm_hour >= 17){
    T->tm_hour = (T->tm_hour + 7)-24;
    T->tm_mday = T->tm_mday+1;
      if (T->tm_mon==2 && T->tm_mday > 29 && ly == 1){ //ถ้าเป็นเดือน 2 ที่มี 29 วัน 
          T->tm_mday = T->tm_mday-29;
          T->tm_mon = T->tm_mon+1;
      }
      else if (T->tm_mon==2 && T->tm_mday > 28 && ly==0){ //ถ้าเป็นเดือน 2 ที่มี 28 วัน 
          T->tm_mday = T->tm_mday-28;
          T->tm_mon = T->tm_mon+1;
      }
      else if (T->tm_mday >= 31){ //ถ้าวันที่ > 30 และเป็นเดือนที่ลงท้ายด้วย ยน(30 วัน)
          if(T->tm_mon==4 ||T->tm_mon==6 ||T->tm_mon==9 ||T->tm_mon==11 ) {
             T->tm_mday = T->tm_mday-30;
             T->tm_mon = T->tm_mon+1;
          }
      else if (T->tm_mday > 31){ //ถ้าวันที่ > 31 และเป็นเดือนที่ลงท้ายด้วย คม(31 วัน)
          if(T->tm_mon==12){//ถ้าเป็นเดือน ธันวาคม(สิ้นปี)
            T->tm_year = T->tm_year +1;
            T->tm_mon = (T->tm_mon+1)-12;
            }
          else{
            T->tm_mon = T->tm_mon+1;
          }
      }
     }
  }
  else{
    T->tm_hour = T->tm_hour + 7;
  }
}

// Timeline Tracker Project | Mahidol Unibersity | EGCO 112 | 23 / 4 / 2021 - 19 / 5 / 2021
// Project team 
//  1)6313138 Yutthasat Phoncharoenpong
//  2)6313175 Thanaphat Sae-Be
//  3)6313210 Krittawat Thongnoppakao