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

LinkedListNode* reverse(LinkedListNode* head){
    
    LinkedListNode* curr = head;
    LinkedListNode* prev = NULL;
    LinkedListNode* forward = NULL;
    
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(LinkedListNode* head){

    if(head == NULL){
        return true;
    }

    LinkedListNode* slow = head;
    LinkedListNode* fast = head->next;

    while((fast != NULL) && (fast->next != NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    LinkedListNode* newhead = slow->next;
    slow->next = NULL;

    newhead = reverse(newhead);

    LinkedListNode* temp = head;
    while(newhead != NULL && temp != NULL){
        
        if(temp->data != newhead->data){
            return false;
        }
        newhead = newhead->next;
        temp = temp->next;
    }
    return true;
}

int main(){
    LinkedListNode* node1 = new LinkedListNode(1);
    
    LinkedListNode* head = node1;
    LinkedListNode* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 6);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    print(head);

    cout << isPalindrome(head);

    return 0;
}