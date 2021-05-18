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

          hol->insert(A);
          hol=A;
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
  int i;
  string st;
  for(i=0;i<size;i++){
       cout<<i+1<<") ";
             t->show_St();
	      t=t->move_next();    
     }
  cout<<"Enter Store Name: "<<endl;
  cin>>st;
  
  while(t!=NULL){
    if(st==t->returnStname()){
      //cout<<i<<") ";
      t->show_node();
    }
    t=t->move_next();
  }
}
