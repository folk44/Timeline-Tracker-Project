#include <iostream>
using namespace std;
#include"NODE.h"


NODE::NODE(){
      next=NULL;
}
NODE:: ~NODE(){ 
}

NODE* NODE::move_next(){
      return next;
}
void  NODE:: show_node(){
         cout<<"Node data:"<<endl;
 }
void NODE::insert(NODE*& x){
     x->next=this;

     }
void NODE::deleteN(NODE*& t){
  delete t;
}
void NODE:: show_St(){
  cout<<"St";
}
