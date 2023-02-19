#include <iostream>
using std::cout;

// define single list struct
class Node {
public:
    int data;
    Node* next;
    Node(int v = 0)
        : data(v)
        , next(nullptr)
    {
    }
};

// insert the node after pos
// return n
Node* insert(Node* pos, Node* n)
{
    Node* temp = pos->next;
    pos->next = n;
    n->next = temp;
    return n;
}

// find the node whose data is equal to v
// return the node or nullptr if not found
Node* find(Node* head, int v)
{
    while (head != nullptr) {
        if (head->data = v)
            return head;
        head = head->next;
    }
    return nullptr;
}

// print all ndoe's data from pos to the end
void through(Node* pos)
{
    while (pos != nullptr) {
        cout << pos->data << std::endl;
        pos = pos->next;
    }
}

int main(void)
{
    // create root node
    Node* head = new Node(1);

    Node* temp = head;
    // append 5 nodes
    for (int i = 0; i < 5; i++) {
        temp = (temp->next = new Node(i));
    }

    // through(head);

    return 0;
}