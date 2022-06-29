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

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }

    return false;
}

int main(){
    Node* node1 = new Node(1);
    
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 6);
    insertAtTail(tail1, 7);
    insertAtTail(tail1, 8);
    insertAtTail(tail1, 9);
    insertAtTail(tail1, 10);

    tail1->next = head1->next->next->next;

    // print(head1);

    cout << detectCycle(head1);

    // print(head1);

    return 0;
}