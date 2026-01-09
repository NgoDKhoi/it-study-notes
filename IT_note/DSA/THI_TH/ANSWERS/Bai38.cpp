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


//  Code
void CreateList(List& l) {
    l.head = l.tail = NULL;
}

double avg(Hocsinh hs) {
    return (hs.Toan + hs.Ly + hs.Hoa + hs.Sinh + hs.Anh + hs.Van) / 6;
}

Node* CreateNode(Hocsinh hs) {
    Node* p = new Node;
    if (p == NULL)
        exit(1);

    p->data = hs;
    p->next = NULL;
    
    return p;
}

void AddTail(List& l, Hocsinh hs) {
    Node* p = CreateNode(hs);
    
    if (l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

int main() {
    List l;
    CreateList(l);

    int n, i;
    Hocsinh hs;

    cin >> n;
    i = 0;
    while (i < n) {
        InputElement(hs);
        if (avg(hs) >= 9) {
            AddTail(l, hs);
        }

        ++i;
    }

    Output(l);

    return 0;
}