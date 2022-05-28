#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    Node *temp = head;

    // if position is 0 or 1
    if (pos == 0 || pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    // if position is greater than linked list size
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printRecursiveForward(Node *p)
{
    if (p == NULL)
        return;
    cout << p->data << " ";
    printRecursiveForward(p->next);
}

void printRecursiveBackward(Node *p)
{
    if (p == NULL)
        return;
    printRecursiveBackward(p->next);
    cout << p->data << " ";
}

void deleteList(Node *head, int n)
{
    Node *temp1 = head;

    // if position to delete node is 1
    if (n == 1)
    {
        head = head->next;
        temp1->next = NULL;
        delete temp1;
        return;
    }
    else
    {
        // any other postion than 1
        for (int i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next = NULL;
        delete temp2;
    }
}

int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 16);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail, 5, 23);
    print(head);

    deleteList(head, 2);
    print(head);

    printRecursiveForward(head);
    cout << endl;
    printRecursiveBackward(head);

    // cout << "Head " << head << endl;
    // cout << "Tail " << tail << endl;
    return 0;
}