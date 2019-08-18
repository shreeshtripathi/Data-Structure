#include<iostream>
using namespace std;

class LinkedList{
    private:
        class Node{
            private:
            
            public:
            int data;
            Node* next;

        };
        int size;
        Node* tail;
        Node* head;
       
        void handleAddwhen0(int data){
            Node* nn = new Node();
            nn -> data = data;
            head = tail = nn;
            size = 1;
        }

        Node* getNodeAt(int indx) {
		    Node* temp = head;
		    for(int i = 0; i < indx; i++) {
		    	temp = temp -> next;
		    }
		    return temp;
	    }
        int handleRemWhenSize1() {
            int temp = head -> data;
            delete head;
            head = tail = NULL;
            size = 0;
            return temp;
        }

    public:
        //Constructor
        LinkedList(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        //Destructor
        ~LinkedList(){
            Node* t = head;
            for(int i = 0; i < size; i++){
                Node* r = t;
                t = t -> next;
                delete r;
            }
        }
        void display(){
            Node* temp = head;
            for(int i = 0; i < size; i++){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        void addFirst(int data){
            Node* n = new Node();
            if(size == 0){
                handleAddwhen0(data);
            } else{
                //Space
                Node* nn = new Node();
                //Data and next
                nn -> data = data;
                nn -> next = head;
                //connect
                nn -> next = head;
                //Summary
                head = nn;
                size++;
            }
        }
        void addLast(int data){
            if(size == 0){
                handleAddwhen0(data);
            } else{
                //Space
                Node* nn = new Node();
                //Data and next
                nn -> data = data;
                tail -> next = nn;
                //connect
                nn -> next = NULL;
                //Summary
                tail = nn;
                size++;
            }
        }
        void addAt(int data, int indx){
            if(indx < 0 || indx >= size) {
                return;
            } else if(indx == 0){
                addFirst(data);
            } else if(indx == size) {
                addLast(data);
            } else {
                Node* nm1 = getNodeAt(indx - 1);
                Node* np1 = nm1 -> next;
                Node* n = new Node();
                n -> data = data;
                nm1 -> next = n;
                n -> next = np1;
                size++;
            }
        }
        int getFirst(){
            if(size == 0){
                return -1;
            } else{
                return head -> data;
            }
        }
        int getLast(){
            if(size == 0){
                return -1;
            } else {
                return tail -> data;
            }
        }
        int getAt(int indx){
            if(indx < 0 || indx >= size) {
                return -1;
            } else {
                Node* temp = getNodeAt(indx);
                return temp -> data;
            }
            
        }
        int removeFirst(){
            if(size == 0) {
                return -1;
            } else if(size == 1) {
                return handleRemWhenSize1();
            } else {
                Node* oh = head;
                head = head -> next;
                size--;
                int temp = oh -> data;
                delete oh;
                return temp;
            }
        }
        int removeLast(){
            if(size == 1) {
                return handleRemWhenSize1();
            } else {
                Node* s1 = getNodeAt(size - 2);
                s1 -> next = NULL;
                int temp = tail -> data;
                delete tail;
                tail = s1;
                size--;
                return temp;
            }
        }
        int removeAT(int indx){
            if(indx < 0 || indx >= size) {
                return -1;
            } else if(indx == 0) {
                return removeFirst();
            } else if(indx == size - 1) {
                return removeLast();
            } else {
                Node* nm1 = getNodeAt(indx - 1);
                Node* n = nm1 -> next;
                Node* np1 = n -> next;
                int temp = n -> data;
                nm1 -> next = np1;
                size--;
                delete n;
                return temp;
            }
        }
};



int main(){
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.display();
    list.addFirst(40);
    list.addFirst(50);
    list.display();
    list.addAt(100, 3);
    list.display();
    list.removeFirst();
    list.removeFirst();
    list.display();
    list.removeLast();
    list.addLast(200);
    list.display();
    list.removeAT(2);
    list.display();


    return 0;
}