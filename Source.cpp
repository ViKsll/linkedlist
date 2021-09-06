#include <iostream>
#include <string>
using namespace std;


struct Node
{
    int data;
    Node* next;
};

void push_front(Node** head_ref, int data) { //insert a node at front before head
    Node* new_head = new Node(); //allocate node
    new_head->data = data; // put in the data
    new_head->next = (*head_ref); //make next of new node as head
    (*head_ref) = new_head; // move the head to point to the new node
}

void insert_after(Node* prev_node, int data) { //insert a new node after the given prev_node
    if (prev_node->next == nullptr) {
        cout << "the given previous node cannot be NULL" << endl;
        return;
    }
    Node* new_node = new Node(); //allocate node
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(Node** head_ref, int data) { //append a new node at the end
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = data;
    new_node->next = nullptr; //this new code is going to be the last node, so make next of it as NULL
    if (*head_ref == nullptr) {
        *head_ref = new_node; 
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    return;
}


void print_list(Node* node) {


    while (node != NULL) {
        cout << node->data << endl;
        node = node->next;

    }
};
int main() {
    Node* head = nullptr;
    
    append(&head, 6);// insert 6, so Linked List becomes 6->NULL

    push_front(&head, 7);// insert 7 at the beginning, so Linked List becomes 7->6->NULL

    push_front(&head, 1);// insert 1 at the beggining, so Linked List becomes 1->7->6->NULL

    append(&head, 4);// insert 4 at the end, so Linked List becomes 1->7->6->4->NULL

    insert_after(head->next, 8);// insert 8, after 7. so Linked List becomes 1->7->8->6->4->NULL

    cout << "Created Linked list is: " << endl;
    print_list(head);
    
}