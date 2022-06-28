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


LinkedListNode *findMiddle(LinkedListNode *head) {
    LinkedListNode* slow = head;
    LinkedListNode* fast = head;

    while((fast != NULL) && (fast->next != NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

int main(){
    LinkedListNode* node1 = new LinkedListNode(10);
    
    LinkedListNode* head = node1;
    LinkedListNode* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    print(head);

    LinkedListNode* middle = findMiddle(head);

    cout << middle->data << endl;

    return 0;
}