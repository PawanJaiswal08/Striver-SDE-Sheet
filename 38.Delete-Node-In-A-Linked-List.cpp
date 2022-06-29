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

void deleteNode(Node* node) {
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main(){
    Node* node1 = new Node(1);
    
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);

    Node* node = head1->next;

    print(head1);

    deleteNode(node);

    print(head1);

    return 0;
}