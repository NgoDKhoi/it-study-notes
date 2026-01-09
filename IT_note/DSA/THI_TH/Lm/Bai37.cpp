#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

// 
int main() {
    List l;
    CreateList(l);

    int n,x;
    cin >> n;

    int i= 0;
    while (i<n) {
        cin >> x;
        AddHead(l, x);
        i++;
    }

    Node *p = l.head;
    while (p != NULL) {
        int data= p->data;
        if (data % 2 == 0) {
            cout << data << " ";
        }
        p= p->next;
    }
    return 0;
}