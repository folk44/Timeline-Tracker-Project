#include <iostream>
using namespace std;
#include"NODE.h"
#include "LL.h"
#include <ctime>
#include <sstream>
#include <iomanip>

int StrToIntt(string x){
  int y;
  stringstream geek(x);
  geek >> y;
  return y;
}

int LLcheckLeapYear(int year){
  int check;// = 1 LeapYear // = 0 not LeapYear
  if (year%4!=0) check=0;
  else if (year%100!=0) check=1;
  else if (year%400!=0) check=0;
  else check=1;
  return check;
}

int LLcheckDate(int d,int m,int y){
  int x,ly;
  ly = LLcheckLeapYear(y);
    if (d<=0||m<=0||y<=0 || m > 12 || d > 31 ) x=0;
    else if (m==2 && d > 29) x=0;
    else if (m==2 && ly==0 && d==29) x=0;
    else if (d==31){
      if(m==4 ||m==6 ||m==9 ||m==11 ) x=0;
    }
    else x=1;
    if (x==0){
      cout << "\n Invalid Date!!\n **************\n Please Input Again..."<<endl;
    } 
  return (x);
}



LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
       int i;
	NODE *t;
	for(i=0;i<size;i++){
		t=hol;
		hol=hol->move_next();
		delete t;
	}
}

void LL::show_all(){
     NODE* t=hol;
     if (t!=NULL){
     int i;
     cout<<endl;
     for(i=0;i<size;i++){
             t->show_node();
	      t=t->move_next();    
      }
     }
     else  cout <<endl<< " Timeline Is Empty!!\n *******************\n Please Input Timeline First..." <<endl;
  }
  


void LL::add_node(NODE *&A){
        if(hol!=NULL){
        int *t= A->returntime();
        int d[3];
        d[0]=A->returnD();
        d[1]=A->returnM();
        d[2]=A->returnY();
        NODE *PP=NULL,*AP=hol;
        int check=0;

          while(AP && check==0){
            int *APt=AP->returntime();
            if(d[2]!=AP->returnY()){
              if(d[2]>AP->returnY()){
                check=1;
                AP->insert(A);
                if(PP==NULL) hol=A;
                else A->insert(PP);
              }
            } 
            else {
              if(d[1]!=AP->returnM()){
                if(d[1]>AP->returnM()){
                  check=1;
                  AP->insert(A);
                  if(PP==NULL) hol=A;
                  else A->insert(PP);
                }
              }
              else{
                if(d[0]!=AP->returnD()){
                  if(d[0]>AP->returnD()){
                    check=1;
                    AP->insert(A);
                    if(PP==NULL) hol=A;
                    else A->insert(PP);
                  }
                }
                else{
                  if(t[0]!=APt[0]){
                    if(t[0]>APt[0]){
                      check=1;
                      AP->insert(A);
                      if(PP==NULL) hol=A;
                      else A->insert(PP);
                    }
                  }
                  else{
                    if(t[1]!=APt[1]){
                      if(t[1]>APt[1]){
                        check=1;
                        AP->insert(A);
                        if(PP==NULL) hol=A;
                        else A->insert(PP);
                      }
                    }
                    else{
                      if(t[2]>=APt[2]){
                        check=1;
                        AP->insert(A);
                        if(PP==NULL) hol=A;
                        else A->insert(PP);
                      }
                    }
                  }
                }
              }
            }
            PP=AP;
            AP=AP->move_next();
            if(AP==NULL&&check!=1){
              A->insert(PP);
              check=1;
            }
          }
        }
        else{
            hol->insert(A);
            hol=A;
        }
        size++;
}
void LL::add_node_St(NODE *&A){
  hol->insert(A);
          hol=A;
       size++;
}

void LL::search(){
  NODE * t=hol;
  if(t!=NULL){
  int i=0,d,m,y,x=0,c=0;
  string D,M,Y;
  cout<<" Input Date (dd mm yyyy)"<<endl;
    do{
        cin.clear();
        cout<<" > ";
        cin >> D ;
        cin.ignore();
        cin>> M;
        cin.ignore(); 
        cin>> Y;
        d=StrToIntt(D);
        m=StrToIntt(M);
        y=StrToIntt(Y);
        x = LLcheckDate(d,m,y);
          }while(x!=1);
        cout<<endl;
  while(t!=NULL){
    if(d==t->returnD() && m==t->returnM() && y==t->returnY() ){
      i++;
      cout<<" "<<i<<")";
      t->show_node();
      c=1;
    }
    t=t->move_next();
  }
  if(c==0){
    cout <<" --> "<<setfill('0')<<setw(2)<<d << "/"<<setfill('0')<<setw(2)<< m << "/"<<setfill('0')<<setw(2)<< y <<" no Timeline"<<endl;
  }
  }else  cout << " Timeline Is Empty!!\n *******************\n Please Input Timeline First..." <<endl;
  
 }

void LL::searchStname(){
  LL S;
  NODE * t=hol;
  NODE * s;
  NODE * check=hol;
  int i,j,d,n=1,c;
  string st,temp,D;
  cout<<endl;
  if (t!=NULL){
  for(i=0;i<size;i++){
    check=hol;
    c=0;
    if(i != 0){
      st=t->returnStname();
      for (j=0;j<i;j++){
          if(st==check->returnStname()){
            c=1;
          }
          check=check->move_next();
        }
      }
    if(c==0){
        cout<<" "<<n<<") ";
        t->show_St();
        temp=t->returnStname();
        s=new TotalStoreN(temp);
        S.add_node_St(s);
        n++;
    }
	    t=t->move_next();  
     }
  cout<<"--------------------------------"<<endl;
  cout<<endl<<" Choose a Store & Input number..."<<endl;
  do{
    c=0;
  cout<<" > ";
  cin>>D;
    d=StrToIntt(D);
    if (d > 0 && d <n ) c=1;
    else cout << "\n Invalid Choice!!\n ****************\n Please Input Again..." <<endl;
  }while (c==0);
  d = S.size-d;
  t=hol;
  s=S.hol;
  for (i=0; i<d ;i++ ) s=s->move_next();
  st = s->returnStname();
  
  while(t!=NULL){
    if(st==t->returnStname()){
      t->show_node();
    }
    t=t->move_next();
  }
  }else  cout << " Timeline Is Empty!!\n *******************\n Please Input Timeline First..." <<endl;
}
void LL::rw_node(){
    NODE *t=NULL,*pre=hol,*pos=NULL;
    int i;
    int d[2],diff;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    while(pre){
        d[0]=pre->returnM();
        d[1]=pre->returnY();
        diff=(((1900 + ltm->tm_year)*12)+(1 + ltm->tm_mon))-((pre->returnY()*12)+pre->returnM());
      if(diff>3){
        if(pos!=NULL){
          t=pre;
          pre=pre->move_next();
          pre->insert(pos);
        }
        else{
          t=pre;
          pre=pre->move_next();
          hol=pre;
        }
        delete t;
        size--;
      }
      else{
        pos=pre;
        pre=pre->move_next();
      }
    }
}  

