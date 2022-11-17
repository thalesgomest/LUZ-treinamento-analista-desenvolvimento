class Stack {
    private:
        List *list;
    public:
    Stack() {
        list = new List();
    }
    void push(int value){
        list->insert_start(value);
    }
    void pop(){
        list->delete_first();
    }
    void display(){
        list->display();
    }
};
    