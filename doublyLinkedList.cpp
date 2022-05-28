#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtHead(Node *&head, int data)
{
    if (head || head->next)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, int data)
{
    if (tail || tail->next)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, int pos, int data)
{
    if (head || head->next)
    {
        if (pos == 1)
        {
            insertAtHead(head, data);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 2; i++)
            temp = temp->next;

        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

int main()
{
    Node *node1 = new Node(12);
    Node *head = node1;
    Node *tail = node1;

    printList(head);
    cout << getLength(head) << endl;

    insertAtHead(head, 30);
    printList(head);

    insertAtTail(tail, 23);
    printList(head);

    insertAtTail(tail, 17);
    printList(head);

    insertAtPosition(head, 1, 19);
    printList(head);

    insertAtPosition(head, 6, 25);
    printList(head);

    insertAtPosition(head, 4, 13);
    printList(head);

    return 0;
}