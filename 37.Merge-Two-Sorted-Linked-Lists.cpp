#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}


Node* sortTwoLists(Node* head1, Node* head2){

    Node* dummy = new Node(-1);

    Node* temp = dummy;

    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
    }

    while(head1 != NULL){
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }

    while(head2 != NULL){
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }

    // delete dummy 
    Node* prev = dummy;
    dummy = dummy->next;
    prev->next = NULL;
    delete prev;

    return dummy;
}

int main(){
    Node* node1 = new Node(1);
    
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);

    print(head1);

    Node* node2 = new Node(2);

    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail2, 3);
    insertAtTail(tail2, 5);

    print(head2);

    head1 = sortTwoLists(head1, head2);

    print(head1);

    return 0;
}