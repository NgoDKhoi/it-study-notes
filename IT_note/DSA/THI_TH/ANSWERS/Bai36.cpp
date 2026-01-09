#include <iostream>

using namespace std;

// Code
struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead, * pTail;
};

void CreateList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* CreateNode(int k) {
	Node* p = new Node;
	if (p == NULL)
		exit(1);

	p->data = k;
	p->pNext = NULL;

	return p;
}

void AddHead(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

int main() {
	List l;
	CreateList(l);

	int n, x, i;
	cin >> n;

	i = 0;
	while (i < n) {
		cin >> x;
		Node* p = CreateNode(x);
		AddHead(l, p);

		++i;
	}

	Node* p = l.pHead;
int cnt = 0;

while (p != NULL) {
    if (p->data >= 90) {
        ++cnt;
        if (cnt <= 10)
            cout << p->data << " ";
    }
    p = p->pNext;
}

cout << "END\n";

	return 0;
}