#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

void display(Node* node){
    for(Node* temp = node; temp != NULL; temp = temp->next){
        cout << temp->data << " ";
    }
    cout << endl;
}

void removeLoop(Node* slow, Node* fast){
    Node* prev = fast;
    while(fast != slow){
        slow = slow ->next;
        prev = fast;
        fast = fast ->next;
    }
    cout << slow -> data << endl;
    prev -> next = NULL;
}

bool darLoop(Node* node){
    Node* slow = node;
    Node* fast = node;
    while(fast != NULL && fast->next != NULL){
        slow = slow ->next;
        fast = fast -> next -> next;
        if(slow == fast){
            removeLoop(node, fast);
            return true;
        }
    }
    return false;
}

int intersection(Node* node1, Node* node2){
    Node* temp = node1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp ->next = node2;
    darLoop(node1);
}

int main(){
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);
    Node n6(60);
    Node n7(70);
    Node n8(80);
    Node n9(90);
    Node n10(100);

    Node m1(1);
    Node m2(2);
    Node m3(3);
    Node m4(4);
    Node m5(5);
    Node m6(6);
    Node m7(7);

    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &m5;
    m5.next = &m6;
    m6.next = &m7;
    m7.next = &n7;


    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    n9.next = &n10;
    n10.next = NULL;

    // cout << darLoop(&n1) << endl;

    display(&n1);
    display(&m1);
    cout << intersection(&n1, &m1) << endl;
    display(&n1);
    display(&m1);
}