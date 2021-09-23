#include <iostream>
using namespace std;

// Constructor Node
class Node{
    public:
        Node(const int& data = 0,Node* next=NULL): data(data), next(next) { }
        int data;
        Node* next;
};

// Constructor List
class list{
    Node* root;
    public:
        list(): root(NULL){}

        Node* begin()const{ return root; }

        Node* end()const{ return NULL; }

        // bool isEmpty()const{return root == NULL; } or
        bool isEmpty()const { 
            return begin() == end(); 
        }

        void push_back(const int& value){
            if(isEmpty()){
                root = new Node(value);
            }
            else{
                Node* tmp = begin();

                while(tmp->next != end()){
                    tmp = tmp->next;
                }
                tmp->next = new Node(value);
            }
        }

        void push_front(const int& value){
            Node* tmp = new Node(value);
            tmp-> next = root;
            root = tmp;
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

    l.push_back(5);
    l.push_back(10);
    l.print();

    l.push_front(3);
    l.print();

    return 0;
}