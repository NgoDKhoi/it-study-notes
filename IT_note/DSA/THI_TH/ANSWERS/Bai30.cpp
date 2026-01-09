#include <iostream>
#include <cmath>

using namespace std;

struct toa_do {
	double x, y, z;
};

struct Node {
	toa_do data;
	Node* pNext;
};

struct List {
	Node* pHead, * pTail;
};

void CreateList(List& ls) {
	ls.pHead = NULL;
	ls.pTail = NULL;
}

Node* CreateNode(toa_do x) {
	Node* p = new Node;
	if (p == NULL)
		exit(1);

	p->data = x;
	p->pNext = NULL;

	return p;
}

void AddTail(List& ls, Node* p) {
	if (ls.pHead == NULL) {
		ls.pHead = p;
		ls.pTail = ls.pHead;
	}
	else {
		ls.pTail->pNext = p;
		ls.pTail = p;
	}
}

bool condition(toa_do a, toa_do b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

void run() {
	List ls;
	CreateList(ls);

	int n, i, m;
	toa_do d;
	cin >> n;

	i = 0;
	while (i < n) {
		cin >> d.x >> d.y >> d.z;
		Node* p = CreateNode(d);
		AddTail(ls, p);

		++i;
	}

	cin >> m;

	while (m--) {
		cin >> d.x >> d.y >> d.z;

		Node* p = ls.pHead;
		bool t = true;
		i = 0;
		while (p != NULL) {
			if (condition(p->data, d)) {
				t = false;
				cout << i << "\n";
			}

			p = p->pNext;
			++i;
		}

		if (t)
			cout << "KHONG" << "\n";
	}
}

int main() {

	int* a = new int[256];
	int* b = new int[256];
	delete[] a;
	run();
	delete[] b;
}