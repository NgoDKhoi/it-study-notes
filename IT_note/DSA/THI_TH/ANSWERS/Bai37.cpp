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


// Code
int main() {
    List l;
    CreateList(l);

    int n, x, i;
    
    cin >> n;
    i = 0;
    while (i < n) {
        cin >> x;
        if (x % 2 == 0) {
            AddHead(l, x);
        }
        
        ++i;
    }

    Node* p = l.head;
    while (p != NULL) {
        cout << p->data << " ";

        p = p->next;
    }

    return 0;
}