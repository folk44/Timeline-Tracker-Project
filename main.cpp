#include <iostream>
#include<cstdlib>
using namespace std;
#include"NODE.h"
#include "class.h"
#include"LL.h"


int main() {
  LL A;
  NODE *t;
  int ti,to, D, M, Y;
  string s_name, note, H_Num, prov, dis, sub_dis;
  cin>>ti>>to>>D>>M>>Y>>s_name>>note>>H_Num>>prov>>dis>>sub_dis;
  t=new timeline(ti,to,D,M,Y,s_name,note,H_Num,prov,dis,sub_dis);
  A.add_node(t);
  //Personinformation("P",10,1,12,2001);
  
return 0;
}
