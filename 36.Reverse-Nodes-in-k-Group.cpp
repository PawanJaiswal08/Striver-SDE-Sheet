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

Node* reverse(Node* head, Node* tail){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    
    while(prev != tail){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


Node* getListAfterReverseOperation(Node *head, int n, int b[]){

    if(n == 0 || head == NULL || head->next == NULL)
        return head;

    int k = b[0];

    if(k == 0){
        return getListAfterReverseOperation(head, n-1, b+1);
    }

    Node* currTail = head;
    for(int i = 0; (i<k-1 && currTail->next != NULL); i++)
        currTail = currTail->next;

    Node* nextBlockHead = currTail->next;
    Node* newHead = reverse(head, currTail);

    head->next = getListAfterReverseOperation(nextBlockHead, n-1, b+1);
    
    return newHead;
}

int main(){
    Node* node1 = new Node(1);
    
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    insertAtTail(tail, 8);
    insertAtTail(tail, 10);
    insertAtTail(tail, 11);

    // cout<<head->data<<endl;
    
    print(head);

    int n = 3;
    int b[n] = {2, 3, 4};

    head = getListAfterReverseOperation(head, n, b);

    print(head);

    return 0;
}