class Queue {
    private:
        List *list;
    public:
        Queue() {
            list = new List();
        }
        void enqueue(int value){
            list->insert_end(value);
        }
        void dequeue(){
            list->delete_first();
        }
        void display(){
            list->display();
        }
};