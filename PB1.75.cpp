/*
PB1.75 Remove Duplicates from Sorted Linked List

You are given a sorted linked list (same Node as PB1.72). Write a function that deletes all duplicates
in the list so that each element ends up only appearing once.

Example: 280->280->281->370->370 becomes 280->281->370.

Complexity: O(n) time and O(1) auxiliary space.
Implementation: You may use anything from the STL. Line limit: 15 lines of code.

*/

#include <vector>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val{0}, next{nullptr} {}
    Node(int x) : val{x}, next{nullptr} {}
    Node(int x, Node *next_in) : val{x}, next{next_in} {}
};

Node* remove_duplicates(Node *head) {
    Node* current = head;
    while (current != nullptr) {
        if (current->val == current->next->val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current -> next;
        }
    }
    return head;
}