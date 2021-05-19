#include <iostream>
using namespace std;
#include"NODE.h"
#include "LL.h"
#include <ctime>
#include<exception>

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
  try{
     NODE* t=hol;
     if (t!=NULL){
     int i;
     for(i=0;i<size;i++){
             t->show_node();
	      t=t->move_next();    
     }
     }
     else throw emptyT;
  }
  catch(exception& e){
    cout<<e.what()<<endl;
    cin.clear();// fflush(stdin)
    cin.ignore(100,'\n');
  }
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

void LL::search(){
  NODE * t=hol;
  int i=0,d,m,y;
  cout<<"Enter DD MM YY : "<<endl;
  cin>>d>>m>>y;
  
  while(t!=NULL){
    if(d==t->returnD() && m==t->returnM() && y==t->returnY() ){
      i++;
      cout<<i<<")";
      t->show_node();
    }
    t=t->move_next();
  }
}

void LL::searchStname(){
  NODE * t=hol;
  NODE * check=hol;
  int i,d,j,n=1,c;
  string st;
 // if (t!=NULL){
  for(i=0;i<size;i++){
    c=0;
    if(i != 0){
      st=t->returnStname();
      for (j=0;j<i;j++){
          if(st==check->returnStname()){
            c=1; break;
          }
          check->move_next();
        }
      }
    if(c==0){
        cout<<n<<") ";
        t->show_St();
        n++;
    }
	    t=t->move_next();  
     }cout <<"Done"<<endl;
  do{
  cout<<"Enter NO. : "<<endl;
  cin>>d;
  }while(d<0||d>i);
  t=hol;

  for(i=0;i<d-1;i++) t=t->move_next();
  st=t->returnStname();
  t=hol;
  
  while(t!=NULL){
    if(st==t->returnStname()){
      t->show_node();
    }
    t=t->move_next();
  }
  //}
  /*else{
      cout<<"Timeline is Empty"<<endl;
  }*/
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
        diff=((ltm->tm_year*12)+ltm->tm_mon)-((pre->returnY()*12)+pre->returnM());
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
