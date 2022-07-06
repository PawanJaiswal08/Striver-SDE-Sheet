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

Node* addTwoNumbers(Node *head1, Node *head2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    // int sum = 0;
    int carry = 0;

    while(head1 != NULL && head2 != NULL){
        
        int sum = head1->data + head2->data + carry;

        if(sum >= 10){
            carry = 1;
            sum = sum - 10;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }else{
            carry = 0;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    while(head1 != NULL){
        int sum = head1->data + carry;
        if(sum >= 10){
            carry = 1;
            sum = sum - 10;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head1 = head1->next;
        }else{
            carry = 0;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head1 = head1->next;
        }
    }

    while(head2 != NULL){
        int sum = head2->data + carry;
        if(sum >= 10){
            carry = 1;
            sum = sum - 10;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head2 = head2->next;
        }else{
            carry = 0;
            Node* nextNode = new Node(sum);
            temp->next = nextNode;
            temp = temp->next;
            head2 = head2->next;
        }
    }

    if(carry != 0){
        Node* nextNode = new Node(carry);
        temp->next = nextNode;
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
    Node* node1 = new Node(7);
    
    Node* head1 = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 5);
    insertAtTail(tail1, 9);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 6);

    print(head1);

    Node* node2 = new Node(8);

    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail2, 4);

    print(head2);

    head1 = addTwoNumbers(head1, head2);

    print(head1);


    return 0;
}