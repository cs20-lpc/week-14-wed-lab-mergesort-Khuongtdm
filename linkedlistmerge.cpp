#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b)
{
    
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void splitList(Node* source, Node*& front, Node*& back)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;


    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }


    front = source;
    back = slow->next;
    slow->next = nullptr;

}

void mergeSort(Node*& head)
{
    // Base case: length 0 or 1
    if (head == nullptr || head->next == nullptr)
        return;

    Node* a;
    Node* b;

    splitList(head, a, b);


    mergeSort(a);
    mergeSort(b);


    head = sortedMerge(a, b);
}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
