#include <iostream>
using namespace std;

// Constructor Node
class Node{
    public:
        Node(const int& data = 0, Node* next=NULL): data(data), next(next) { }
        int data;
        Node* next;
};

// Constructor List
class list{
    Node* tail;
    Node* root;
    
    Node* findPrev(Node* pos){
        Node* tmp = root;
        Node* stop = end();

        while(tmp != stop && tmp->next != pos){
            tmp = tmp->next;
        }
        return tmp;
    }

    public:
        list(){
            root = new Node();
            tail = root;
            tail->next = new Node();
        }

        Node* begin()const{ return root->next; }

        Node* end()const{ return tail->next; }

        // bool isEmpty()const{return root == NULL; } or
        bool isEmpty()const { 
            return begin() == end(); 
        }

        void push_back(const int& value){
           insert(end(),value);
        }

        void push_front(const int& value){
            insert(begin(),value);
        }

        void insert(Node* pos, const int& value){
            if(pos == end()){
                tail->next = new Node (value,end());
                tail = tail->next;

            } else {
                Node* tmp = findPrev(pos);
                if (tmp == end())
                    throw "Error: list::insert() for pos in not list.";
                
                tmp->next = new Node(value,tmp->next);
            }
        }

        int front()const{
            if(isEmpty())
                throw "Error: list::front() for list is empty";

            return begin()->data;
        }

        int back()const{
            if(isEmpty())
                throw "Error: list::back() for list is empty";

            return tail->data;
        }

        void erase(Node* pos){
            if (isEmpty()){
                throw "Error: list::erase() for list is empty.";
            }

            Node* tmp = root;
            if (pos == end() || pos==tail){

                pos = tail;
                tmp = findPrev(pos);   

                tmp->next = pos->next;
                tail = tmp;

            }else{
                tmp = findPrev(pos);

                if (pos == end()){
                    throw "Error: list::erase() for pos is not list.";
                }        
                tmp->next = pos->next;
            }
            delete pos;
        }

        void pop_back(){
            erase(end());
        
        }

        void pop_front(){
           erase(begin());
        }

        void print(){
            Node* tmp = begin();

            while (tmp != end()){
                cout << tmp -> data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

int main(){
    list l;
    cout << l.isEmpty() << endl;

    l.push_front(5);
    l.push_back(2);
    l.push_front(10);

    l.insert(l.begin(),3);
    l.erase(l.begin());
    l.erase(l.end());

    l.print();

    return 0;
}