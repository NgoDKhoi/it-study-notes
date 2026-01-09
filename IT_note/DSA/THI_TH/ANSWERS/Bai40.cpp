#include <iostream>

using namespace std;


// Code
struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead, * pTail;
	int N;
};

void CreateList(List& l) {
	l.pHead = l.pTail = NULL;
	l.N = 0;
}

Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL)
		exit(1);

	p->data = x;
	p->pNext = NULL;

	return p;
}

void AddTail(List& ds, int x) {
	Node* p = CreateNode(x);

	if (ds.pHead == NULL) {
		ds.pHead = p;
		ds.pTail = ds.pHead;
	}
	else {
		ds.pTail->pNext = p;
		ds.pTail = p;
	}

	++ds.N;
}

int main() {
	List ds;
	CreateList(ds);

	int n, i, x;
	
	cin >> n;
	i = 0;
	while (i < n) {
		cin >> x;
		if (x % 2 == 0) {
			AddTail(ds, x);
		}

		++i;
	}

	i = 0;
	Node* p = ds.pHead;
	while (p != NULL) {
		if (i == (ds.N - 1) / 2) {
			cout << p->data;
			break;
		}

		p = p->pNext;
		++i;
	}

	return 0;
}
