
class LL{
      NODE* hol;
      int size;
public:
       void add_node(NODE*&);
       void rw_node();
       void show_all();
       void search();
       void searchStname();
       NODE* HOL(){return hol;}
       ~LL();
       LL();
      
};

class LL_Empty : public exception{
  virtual const char* what () const throw(){
    return "Timeline is empty!! \nPlease input timeline first...";
  }
}emptyT;