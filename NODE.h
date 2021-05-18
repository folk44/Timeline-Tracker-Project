class NODE{
      NODE* next;
public:
        NODE();
        virtual void show_node();
        void insert(NODE*&);
        void deleteN(NODE*&);
        NODE* move_next();
        virtual ~NODE(); //ใส่virtualเพื่อให้ Destruct timeline
};