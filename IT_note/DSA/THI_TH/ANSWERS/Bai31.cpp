#include <iostream>
#include <vector>

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

void Output(vector<Hocsinh> ls) {
    for (int i = 0; i < ls.size(); i++) {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ls.push_back(hs);
    }
}

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

// Code
void merge(vector<Hocsinh>& ls, int begin, int mid, int end) {
    int n = ls.size();
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int i, ii, iii;
    Hocsinh* l = new Hocsinh[n1], * r = new Hocsinh[n2];

    i = 0;
    while (i < n1) {
        l[i] = ls[begin + i];
        ++i;
    }

    i = 0;
    while (i < n2) {
        r[i] = ls[mid + 1 + i];
        ++i;
    }

    i = 0; ii = 0; iii = begin;
    while (i < n1 && ii < n2) {
        if (l[i].Ten <= r[ii].Ten) {
            ls[iii] = l[i];
            ++i;
        }
        else {
            ls[iii] = r[ii];
            ++ii;
        }

        ++iii;
    }

    while (i < n1) {
        ls[iii] = l[i];
        ++i;
        ++iii;
    }

    while (ii < n2) {
        ls[iii] = r[ii];
        ++ii;
        ++iii;
    }

    delete[] l;
    delete[] r;
}

void merge_sort(vector<Hocsinh>& ls, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    merge_sort(ls, begin, mid);
    merge_sort(ls, mid + 1, end);
    merge(ls, begin, mid, end);
}

void Sort(vector<Hocsinh>& ls) {
    merge_sort(ls, 0, ls.size() - 1);
}