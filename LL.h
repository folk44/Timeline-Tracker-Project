class LL{
      NODE* hol;
      int size;
public:
       void add_node(NODE*&);
       void add_node_St(NODE*&);
       void rw_node();
       void show_all();
       void search();
       void searchStname();
       NODE* HOL(){return hol;}
       ~LL();
       LL();
};

