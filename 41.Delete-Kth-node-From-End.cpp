#include<bits/stdc++.h>
using namespace std;

class LinkedListNode {
    public:
        int data;
        LinkedListNode* next;

    public:
        LinkedListNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

void print(LinkedListNode* &head){
    LinkedListNode* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(LinkedListNode* &tail, int data){
    LinkedListNode* temp = new LinkedListNode(data);
    tail->next = temp;
    tail = tail->next;
}

LinkedListNode* removeKthNode(LinkedListNode* head, int k){
    
    if(head == NULL || k ==0)return head;

    LinkedListNode* dummy = new LinkedListNode(-1);
    dummy->next = head;
    LinkedListNode* slow = dummy;
    LinkedListNode* fast = dummy;
    
    // gap of 'K' b/w slow and fast
    while(k--){
        fast = fast->next;
    }

    while(fast != NULL && fast->next != NULL){
       fast = fast->next;
       slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}

int main(){
    LinkedListNode* node1 = new LinkedListNode(1);
    
    LinkedListNode* head = node1;
    LinkedListNode* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    print(head);

    head = removeKthNode(head, 6);

    print(head);

    return 0;
}