#include <iostream>
#include<cstdlib>
#include<exception>
using namespace std;
#include"NODE.h"
#include "class.h"
#include"LL.h"
#include"time.h"

int main() {
  LL A;
  NODE *t;
  int ti,to, D, M, Y;
  string s_name, note, H_Num, prov, dis, sub_dis;
  //try{
  
  t=new timeline(ti,to,D,M,Y,s_name,note,H_Num,prov,dis,sub_dis);
  A.add_node(t);

  cin.clear();
  cin.ignore(100,'\n');
  }
return 0;
}
