#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList
{
private:
    // Declare a structure for the list.
    struct ListNode
    {
        T value;                // The value in this node.
        struct ListNode *next;  // To point to the next node.
    };

    // List head pointer.
    ListNode *head;

public:
    // Default constructor.
    LinkedList() { head = nullptr; }

    // Destructor.
    ~LinkedList();

    // Linked list operations.
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};

/***
 * Function appendNode: The function appends a node containing
 * the value passed into num, to the end of the list.
 */
template <class T>
void LinkedList<T>::appendNode(T num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // To point to a new node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, the newNode
    // the first node.
    if (head == nullptr)
        head = newNode;
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Search for the last node in the list.
        while(nodePtr->next != nullptr)
            nodePtr = nodePtr->next;
    }
}
#endif