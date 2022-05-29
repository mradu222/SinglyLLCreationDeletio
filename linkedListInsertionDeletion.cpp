#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, Node* &tail,int d) {
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;

    }
    else{
        // new node create
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail, int d) {
     // new node create
    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;

    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        tail  = temp;
    }
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head,tail, d); 
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(head, tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head, Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next == NULL){
            tail = prev;
            prev -> next = curr -> next;
            curr -> next  = NULL;
            delete curr;
        }

    }
}

int main() {
    //Node* n1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,12);
    cout<<"the new linkedlIst after the insertion of new head is: ";
    insertAtHead(head,tail,16);
    print(head);
    cout<<"the new linkedlIst after the insertion of new node at tail is: ";
    insertAtTail(head,tail,15);
    print(head);
    cout<<"the new linkedlIst after the insertion of new node at any position is: ";
    insertAtPosition(tail,head,3,65);
    print(head);
    cout<<"linkedList after the deltion of a node is: ";
    deleteNode(2,head,tail);
    print(head);
    cout<<"Tail: "<<tail->data<<endl;
    deleteNode(3,head,tail);
    print(head);
    cout<<"Tail: "<<tail->data<<endl;
    return 0;
}