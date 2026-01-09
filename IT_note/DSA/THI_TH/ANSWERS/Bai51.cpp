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
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


// Code
int Compare(Hocsinh a, Hocsinh b) {
    if (a.Ten < b.Ten) return -1;
    if (a.Ten > b.Ten) return 1;

    if (a.Hodem < b.Hodem) return -1;
    if (a.Hodem > b.Hodem) return 1;

    return 0;
}

void InsertNode(TREE& t, Hocsinh hs) {
    if (t == NULL) {
        t = CreateTNode(hs);
        return;
    }

    int cmp = Compare(hs, t->data);

    if (cmp == 0) return;
    if (cmp < 0) {
        InsertNode(t->left, hs);
    }
    else {
        InsertNode(t->right, hs);
    }
}

void LNR(TREE t) {
    if (t == NULL) return;
    LNR(t->left);
    OutputElement(t->data);
    LNR(t->right);
}

int main() {
    int n, i;
    Hocsinh hs;
    TREE t;
    CreateTree(t);

    cin >> n;

    i = 0;
    while (i < n) {
        InputElement(hs);
        InsertNode(t, hs);

        ++i;
    }

    LNR(t);

    return 0;
}