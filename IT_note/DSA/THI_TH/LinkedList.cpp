#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

void creatEmptyList(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

void addHead(List &L, int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = newNode;
        L.tail = L.head;
    }
    else
    {
        newNode->next = L.head;
        L.head = newNode;
    }
}

void printList(List L)
{
    Node *p;
    if (L.head == NULL)
    {
        cout << "Empty list";
    }
    else
    {
        p = L.head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

void Remove_k_th(List &L, int k)
{
    if (L.head == NULL) return;

    Node *p = L.head;
    if (k == 0)
    {
        L.head = p->next;
        delete p;
        return;         
    }
    

    for (int i=0 ; i < k-1; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) return;
        
    Node* temp = p->next;
    p->next= temp->next;
    delete temp;
}

int main()
{
    List L;

    creatEmptyList(L);
    addHead(L, 0);
    addHead(L, 1);
    addHead(L, 6);
    addHead(L, 2);
    printList(L);

    Remove_k_th(L, 1);

    cout << "\n";

    printList(L);

    return 0;
}