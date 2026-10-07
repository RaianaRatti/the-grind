/*
PB1.76 Reverse a Linked List

You are given a singly-linked list (same Node as PB1.72). Write a program that reverses this
singly-linked list. Return the new head node after you’re done.
Example: 1->2->3->4->nullptr becomes 4->3->2->1->nullptr.

Complexity: O(n) time and O(1) auxiliary space.

Implementation: You may NOT use anything from the STL. Line limit: 15 lines of code.
*/

struct Node {
    int val;
    Node *next;
    Node() : val{0}, next{nullptr} {}
    Node(int x) : val{x}, next{nullptr} {}
    Node(int x, Node *next_in) : val{x}, next{next_in} {}
};

Node* reverse_list(Node *head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;  // save next
        curr->next = prev;        // flip
        prev = curr;              // advance prev
        curr = next;              // advance curr
    }
    return prev;
}