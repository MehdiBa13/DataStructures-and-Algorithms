// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(NULL)
using namespace std;
using ll = long long;
// Node structure
typedef struct Node{
    int data;
    Node *next;
} Node;
// Singly linked list class
class linkedlist{
private:
    // Singly linked list private elements
    Node *head, *tail;
public:
    // Singly linked list constructor
    linkedlist(){
        head = NULL;
        tail = NULL;
    }
    // Get head method implementation
    Node* getHead(){ return head; }
    // Set head method implementation
    void setHead(int n){ head->data = n; }
    // Get tail method implementation
    Node* getTail(){ return tail; }
    // Set tail method implementation
    void setTail(int n){ tail->data = n; }
    // Add node to tail method implementation
    void addNodeToTail(int n){
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        } else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    // Output method implementation
    void output(){
        Node *current = head;
        while(current != NULL){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << '\n';
    }
};
// Main function
int main(){
    fast_io;
    /*
        Our singly linked list:
            1 -> 2 -> 3 -> 4 -> NULL  
    */
    // Class instance
    linkedlist linked_list;
    // Adding nodes
    linked_list.addNodeToTail(1);
    linked_list.addNodeToTail(2);
    linked_list.addNodeToTail(3);
    linked_list.addNodeToTail(4);
    // Outputing singly linked list
    linked_list.output();
    // Changing head value
    linked_list.setHead(0);
    // Outputing singly linked list again to see the changes
    linked_list.output();
    return 0;
}
