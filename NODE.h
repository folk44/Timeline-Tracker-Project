class NODE{
      //string x;
      NODE* next;
public:
        NODE();
        virtual void show_node();
        void insert(NODE*&);
        void deleteN(NODE*&);
        NODE* move_next();
        virtual ~NODE(); //ใส่virtualเพื่อให้ Destruct timeline
        virtual int returnD(){return 0;}        
        virtual int returnM(){return 0;}
        virtual int returnY(){return 0;}
        virtual string returnStname(){return "ff";}
        virtual void show_St();
        virtual int* returntime(){return 0;}
};

class TotalStoreN : public NODE {
  public:
    string storeList;
    TotalStoreN(string x){
      storeList = x;
      //cout <<"Adding storeList " << x <<endl;
    }
    ~TotalStoreN(){
      //cout << "Destruter"<<endl;
    }
    void show_node(){
      //cout << "CCC " << storeList<<endl;
    }
    string returnStname(){return storeList;}
};