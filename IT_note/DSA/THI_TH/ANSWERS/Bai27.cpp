#include <iostream>
#include <cmath>

using namespace std;

// Code 
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

double distance(toa_do d) {
	return (double)sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
}

int main() {
	List ls;
	CreateList(ls);

	int n, i;
	double b, e;
	toa_do d;
	cin >> n;

	i = 0;
	while (i < n) {
		cin >> d.x >> d.y >> d.z;
		Node* p = CreateNode(d);
		AddTail(ls, p);

		++i;
	}

	cin >> b >> e;

	Node* p = ls.pHead;
	bool t = true;
	while (p != NULL) {
		double dis = distance(p->data);
		if (b <= dis && dis <= e) {
			t = false;
			cout << p->data.x << " " << p->data.y << " " << p->data.z << "\n";
		}

		p = p->pNext;
	}

	if (t)
		cout << "KHONG" << "\n";

	return 0;
}