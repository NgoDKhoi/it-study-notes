#include <iostream>
#include <string>
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

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

// Code
void CreateList(List &l) {
    l.head= NULL;
    l.tail= NULL;
}

void AddTail(List &l, Hocsinh x) {
    Node *q = new Node();
    q->data= x;
    q->next= NULL;


    if (l.tail == NULL) {
        l.head= l.tail = q;
    }
    else {
        l.tail->next = q;
        l.tail= q;
    }
}

double avg(Hocsinh x) {
    return (x.Toan + x.Van + x.Ly + x.Hoa + x.Anh + x.Sinh) / 6.0;
}

int main() {
    List l;
    CreateList(l);

    int n;
    cin >> n;

    Hocsinh x;
    for (int i=0; i < n; i++) {
        InputElement(x);
        if (avg(x) > 9.0) AddTail(l, x);
    }
    Output(l);

    return 0;
}