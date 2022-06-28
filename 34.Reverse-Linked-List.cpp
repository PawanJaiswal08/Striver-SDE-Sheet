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

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
// }

LinkedListNode* reverseLinkedList(LinkedListNode* head){
    LinkedListNode* prev = NULL;
    LinkedListNode* curr = head;

    while(curr != NULL){
        LinkedListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

LinkedListNode* reverseLinkedListRec(LinkedListNode* &curr, LinkedListNode* prev){
    if(curr == NULL)
        return prev;
    

    LinkedListNode* forward = curr->next;
    curr->next = prev;

    return reverseLinkedListRec(forward, curr);
}

int main(){
    LinkedListNode* node1 = new LinkedListNode(10);
    
    LinkedListNode* head = node1;
    LinkedListNode* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    print(head);

    // head = reverseLinkedList(head);
    head = reverseLinkedListRec(head, NULL);

    print(head);

    return 0;
}