#include <iostream>
using namespace std;
#include"NODE.h"
#include "LL.h"

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
     int i;
     for(i=0;i<size;i++){
             t->show_node();
	      t=t->move_next();    
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
            //cout <<"Vom"<<endl;
            if(AP==NULL&&check!=1){
              cout << "SAWADEE"<<endl;
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
/*void LL::add_node(NODE *&A){

          hol->insert(A);
          hol=A;
       size++;
 }*/

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
  int i,d;
  string st;
  
  for(i=0;i<size;i++){
       cout<<i+1<<") ";
             t->show_St();
	      t=t->move_next();    
     }
  while(d>0&&d<=i+1){
  cout<<"Enter NO. : "<<endl;
  cin>>d;
  }
  t=hol;

  for(i=0;i<d;i++) t=t->move_next();
  st=t->returnStname();
  t=hol;
  
  while(t!=NULL){
    if(st==t->returnStname()){
      t->show_node();
    }
    t=t->move_next();
  }
}
