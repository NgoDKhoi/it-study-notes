#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

// COde
Node* getTail(Node* head) {
    while (head != NULL && head->next != NULL)
        head = head->next;

    return head;
}

bool condition(Hocsinh& a, Hocsinh& b) {
    if (a.Ten != b.Ten) return a.Ten < b.Ten;
    if (a.Hodem != b.Hodem) return a.Hodem < b.Hodem;
    if (a.Nam != b.Nam) return a.Nam > b.Nam;
    if (a.Thang != b.Thang) return a.Thang > b.Thang;
    if (a.Ngay != b.Ngay) return a.Ngay > b.Ngay;
    return true;
}


Node* partition(Node* head, Node* tail, Node** newHead, Node** newTail) {
    Node* pivot = tail;
    Node* prev = NULL;
    Node* cur = head;
    Node* end = pivot;

    while (cur != pivot) {
        if (condition(cur->data, pivot->data)) {
            if (*newHead == NULL)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev)
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = NULL;
            end->next = cur;
            end = cur;
            cur = tmp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;
    *newTail = end;

    return pivot;
}

Node* quick_sort(Node* head, Node* tail) {
    if (head == NULL || head == tail) return head;

    Node* newHead = NULL, * newTail = NULL;

    Node* pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;

        tmp->next = NULL;

        newHead = quick_sort(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quick_sort(pivot->next, newTail);

    return newHead;
}

void Sort(List& l) {
    if (l.head == NULL || l.head == l.tail) return;
    l.head = quick_sort(l.head, getTail(l.head));
    l.tail = getTail(l.head);
}