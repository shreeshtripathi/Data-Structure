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
        Node* rdrLeft;
       
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

        void displayReverse(Node* node){
            if(node == NULL){
                return;
            }
            displayReverse(node -> next);
            cout << node -> data << "->";
        }

        void rpr(Node* node){
            if(node == tail) {
			    return;
		    }
		    rpr(node->next);
		    node->next->next = node;
        }

        void rdr(Node* right, int floor){
            if(right == NULL) {
                return;
            }
            rdr(right -> next, floor + 1);
            if(floor >= size / 2) {
                int temp = rdrLeft -> data;
                rdrLeft -> data = right -> data;
                right -> data = temp;
                
                rdrLeft = rdrLeft -> next;
                
            }
        }

        void rdrcpp(Node** left, Node* right, int floor){
            if(right == NULL){
                return;
            }
            rdrcpp(left, right -> next, floor + 1);
            if(floor >= size / 2){
                //rleft == real left
                Node* rleft = (*left);
                int temp = rleft -> data;
                rleft -> data = right -> data;
                right -> data = temp;

                (*left) = rleft -> next;
            }
        }

        bool isPalindrome(Node* right){
            if(right == NULL){
                return true;
            }
            bool rres = isPalindrome(right -> next);
            if(rres == false){
                return false;
            } else if(rdrLeft -> data != right -> data){
                return false;
            } else{
                rdrLeft = rdrLeft -> next;
                return true;
            }

        }

        void fold(Node** left, Node* right, int floor) {
            if(right == NULL) {
                return;
            }
            fold(left, right -> next, floor + 1);
            if(floor > size / 2) {
                right -> next = (*left) -> next;
                (*left) -> next = right;
                (*left) = right -> next;
            } else if(floor == size/2) {
                tail = right;
                right -> next = NULL;
            }
        }

        void unfold(Node* temp1) {
            if(temp1 -> next == NULL) {
                head = tail = temp1;
                return;
            } else if(temp1 -> next -> next == NULL) {
                head = temp1;
                tail = temp1 -> next;
                return;
            }	
            
            Node* temp2 = temp1 -> next;
            unfold(temp1 -> next -> next);
            temp1 -> next = head;
            head = temp1;
            tail -> next = temp2;
            tail = temp2;
            tail -> next = NULL;
        }

        Node* midNode(Node* first, Node* last){
            Node* slow = first;
            Node* fast = first;
            while(fast -> next != last && fast != last){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        LinkedList* mergeSort(Node* first, Node* last){
            if(first == last){
                LinkedList* l4 = new LinkedList();
                l4->addLast(first->data);
                return l4;
            }
            Node* mid = midNode(first, last);
            LinkedList* ls1 = mergeSort(first, mid);
            LinkedList* ls2 = mergeSort(mid->next, last);
            LinkedList* list = new LinkedList();
            list->mergeTwoSortedList(*ls1, *ls2);
            return list;

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

        void rdi() {
            int li = 0;
            int ri = size - 1;
            while(li <= ri){
                Node* left = getNodeAt(li);
                Node* right = getNodeAt(ri);
                int temp = left -> data;
                left -> data = right -> data;
                right -> data = temp;
                li++;
                ri--;
            }
        }
        void rpi(){
            Node* prev = NULL;
            Node* cur = head;
            Node* next = cur->next;
            while(cur != NULL){
                cur->next = prev;
                prev = cur;
                cur = next;
                if(next != NULL){
                    next = next -> next;
                }
            }
            Node* temp = head;
            head = tail;
            tail = temp;
        }

        void displayReverse(){
            displayReverse(head);
            cout << endl;
        }

        void rpr(){
            rpr(head);
            Node* temp = head;
            head = tail;
            tail = temp;
            tail -> next = NULL;
        }

        void rdr(){
            rdrLeft = head;
            rdr(head, 0);
        }

        void rdrcpp(){
            Node* left = head;
            Node* right = head;
            rdrcpp(&left, right, 0);
        }

        bool isPalindrome(){
            rdrLeft = head;
            if(isPalindrome(head)){
                return true;
            }else{
                return false;
            }
        }

        void fold() {
            Node* left = head;
            Node* right = head;
            fold(&left, right, 0);
        }
        
        void unfold() {
            
            unfold(head);
        }

        // void remDuplicates(){
        //     Node* temp = head;
        //     while(temp -> next != NULL){
        //         if(temp->next->data == temp->data){
        //             Node* temp2 = temp->next;
        //             temp->next = temp2->next;
        //             delete temp2;
        //             size--;
        //         }
        //         else {
        //             temp = temp->next;
        //         }
        //     }
        //     tail = temp;
        //     tail->next = NULL;
        //}

        void clear(LinkedList* l){
            l->head = NULL;
            l->tail = NULL;
            l->size = 0;
        }

        void removeDuplicates(){
            LinkedList nl;
            //Use this pinter
            while(this->size > 0){
                int temp = this->removeFirst();
                if(nl.size == 0 || nl.tail -> data != temp){
                    nl.addLast(temp);
                }
            }
            // change in original head and tail
            this->head = nl.head;
            this->tail = nl.tail;
            this->size = nl.size;

            // a function which prevent from destructor so that list is prevent
            clear(&nl);
        }

        void OddEven(){
            LinkedList l1;
            LinkedList l2;
            // l1 is for Odd and l2 is for Even;
            while(this->size > 0){
                int temp = this->removeFirst();
                if(temp % 2 == 0){
                    l2.addLast(temp);
                } else {
                    l1.addLast(temp);
                }
            }
            if(l1.size == 0){
                this->head = l2.head;
                this->tail = l2.tail;
                this->size = l2.size;
            } else if(l2.size == 0){
                this->head = l1.head;
                this->tail = l1.tail;
                this->size = l1.size;
            } else {
                l1.tail->next = l2.head;
                this->head = l1.head;
                this->tail = l2.tail;
                this->size = l1.size + l2.size;
            }
            clear(&l1);
            clear(&l2); 
        }

        void kreverse(int n){
            LinkedList accu; // accumulator
            while(this->size > 0){
                LinkedList temp;
                for(int i = 0; i< n && this->size > 0; i++){
                        int data = this->removeFirst();
                        temp.addFirst(data);
                }
                if(accu.size == 0){
                    // accu.head = temp.head;
                    // accu.tail = temp.tail;
                    // accu.size = temp.size;
                    accu = temp;
                } else {
                    accu.tail->next = temp.head;
                    accu.tail = temp.tail;
                    accu.size = accu.size + temp.size;
                }
                clear(&temp);
            }
            this->head = accu.head;
            this->tail = accu.tail;
            this->size = accu.size;
            clear(&accu);
        }

        int midElement(){
            Node* mid = midNode(this->head, this->tail);
            return mid->data;
        }
        
        int kthFromLast(int k){
            Node* slow = head;
            Node* fast = head;
            while(k != 0){
                fast = fast -> next;
                k--;
            }
            while(fast != NULL){
                slow = slow -> next;
                fast = fast ->next;
            }
            return slow -> data;
        }

        void mergeTwoSortedList(LinkedList& l1, LinkedList& l2){
            Node* temp1 = l1.head;
            Node* temp2 = l2.head;
            while(temp1 != NULL && temp2 != NULL){
                if(temp1->data < temp2->data){
                    this->addLast(temp1->data);
                    temp1 = temp1->next;
                } else{
                    this->addLast(temp2->data);
                    temp2 = temp2->next;
                }
            }
            if(temp1 == NULL){
                while(temp2 != NULL){
                    this->addLast(temp2->data);
                    temp2 = temp2->next;
                }
            }
            if(temp2 == NULL){
                while(temp1 != NULL){
                    this->addLast(temp1->data);
                    temp1 = temp1->next;
                }
            }
        }

        LinkedList*  mergeSort(){
            LinkedList* res = mergeSort(this->head, this->tail);
            return res;
        }
};



int main(){
    LinkedList l;
    l.addLast(10);
    l.addLast(40);
    l.addLast(50);
    l.display();
    l.addFirst(20);
    l.addFirst(30);
    l.display();
    l.addAt(100, 3);
    // l.display();
    // l.removeFirst();
    // l.removeFirst();
    // l.display();
    // l.removeLast();
    // l.display();
    // l.addLast(200);
    // l.display();
    // l.removeAt(2);
    l.display(); // 50 40 10 100 20 30

    l.rdi();
    l.display();
    l.rpi();
    l.display();
    // l.displayReverse();
    l.rdr();
    l.display();
    l.addLast(2);
    l.addLast(3);
    // l.addLast(4);

    // cout << "FOLD" << endl;
    // l.display();
    // l.fold();
    // l.display();
    // l.addLast(1000);
    // l.display();
    l.display();
    l.fold();
    l.display();

    l.unfold();
    l.addFirst(-4);
    l.addLast(-10);
    l.display();
    // l.addLast(2000);
    // l.display();

    LinkedList l2;
    l2.addLast(1);
    l2.addLast(10);
    l2.addLast(100);
    l2.addLast(2);
    l2.addLast(20);
    l2.addLast(200);
    l2.addLast(3);
    l2.addLast(4);
    l2.addLast(40);
    l2.addLast(400);
    l2.addLast(500);

    l2.display();
    l2.kreverse(3);
    l2.display();
    
    cout << l2.midElement() << endl;
    cout << l2.kthFromLast(5) << endl;

    LinkedList ll1, ll2;

    ll1.addLast(10);
    ll1.addLast(20);
    ll1.addLast(30);
    ll1.addLast(40);
    ll1.addLast(50);

    ll2.addLast(5);
    ll2.addLast(7);
    ll2.addLast(11);
    ll2.addLast(18);
    ll2.addLast(28);
    ll2.addLast(35);

    LinkedList ll3;
    ll3.mergeTwoSortedList(ll1, ll2);
    // ll1.display();
    // ll2.display();
    ll3.display();

    ll3.fold();
    ll3.display();

    LinkedList* ll4 = ll3.mergeSort();
    ll4->display();
    ll3.display();

    delete ll4;
    return 0;
}