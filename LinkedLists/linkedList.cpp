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
// Linked list class
class linkedlist{
private:
    // Linked list private elements
    Node *head, *tail;
public:
    // Linked list constructor
    linkedlist(){
        head = NULL;
        tail = NULL;
    }
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
        Our linked list:
            1 -> 2 -> 3 -> 4 -> NULL
    */
    // Class instance
    linkedlist linked_list;
    // Adding nodes
    linked_list.addNodeToTail(1);
    linked_list.addNodeToTail(2);
    linked_list.addNodeToTail(3);
    linked_list.addNodeToTail(4);
    // Outputing linked list
    linked_list.output();
    return 0;
}
