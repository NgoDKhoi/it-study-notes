#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void Sum(List a, List b, List &c) {
    stack<int> st1;
    stack<int> st2;

    Node *p = a.head;
    while (p != NULL) {
        st1.push(p->num);
        p= p->next;
    }

    p = b.head;
    while (p != NULL) {
        st2.push(p->num);
        p= p->next;
    }

    int x = 0;
    while (!st1.empty() && !st2.empty()) {
        int sum = st1.top() + st2.top() + x;
        st1.pop();
        st2.pop();

        AddHead(c, sum % 10);
        x = sum / 10;
    }

    while (!st1.empty()) {
        int sum = st1.top() + x;
        st1.pop();
        AddHead(c, sum % 10);
        x = sum / 10;
    }

    while (!st2.empty()) {
        int sum = st2.top() + x;
        st2.pop();
        AddHead(c, sum % 10);
        x = sum / 10;
    }

    if (x > 0) {
        AddHead(c, x);
    }
}