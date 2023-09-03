// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
// Node structure
typedef struct Node{
    int data;
    Node *next;
} Node;
// Singly linked list class
class LinkedList{
private:
    // Singly linked list private elements
    Node *head, *tail;
public:
    // Singly linked list constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    // Get head method implementation ( Time complexity: O(1) )
    Node* getHead(){ return head; }
    // Set head method implementation ( Time complexity: O(1) )
    void setHead(int n){ head->data = n; }
    // Get tail method implementation ( Time complexity: O(1) )
    Node* getTail(){ return tail; }
    // Set tail method implementation ( Time complexity: O(1) )
    void setTail(int n){ tail->data = n; }
    // Is empty method implementation
    bool empty(){ return head == NULL; }
    // Push ( Time complexity: O(1) )
    void push(int n){
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
    // Output method implementation ( Time complexity: O(n) where n is the number of nodes)
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
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    /*
        Our singly linked list:
            1 -> 2 -> 3 -> 4 -> NULL  
    */
    // Class instance
    LinkedList linked_list;
    // Adding nodes
    linked_list.push(1);
    linked_list.push(2);
    linked_list.push(3);
    linked_list.push(4);
    // Outputing singly linked list
    linked_list.output();
    // Changing head value
    linked_list.setHead(0);
    // Outputing singly linked list again to see the changes
    linked_list.output();
    // Resetting the head value
    linked_list.setHead(1);
    // Outputing singly linked list again to see the changes
    linked_list.output();
    return 0;
}
