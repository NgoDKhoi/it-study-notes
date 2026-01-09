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
double avg(Hocsinh hs) {
    return (hs.Toan + hs.Ly + hs.Hoa + hs.Sinh + hs.Anh + hs.Van) / 6;
}

bool condition(Hocsinh a, Hocsinh b) {
    if (avg(a) != avg(b))
        return avg(a) > avg(b);

    if (a.Nam != b.Nam)
        return a.Nam > b.Nam;

    if (a.Thang != b.Thang)
        return a.Thang > b.Thang;

    return a.Ngay >= b.Ngay;
}

int partition(vector<Hocsinh>& ls, int low, int high) {
    Hocsinh hs = ls[high];
    int i = low - 1, j;

    j = low;
    while (j < high) {
        if (condition(ls[j], hs)) {
            ++i;
            swap(ls[i], ls[j]);
        }

        ++j;
    }

    swap(ls[i + 1], ls[high]);
    return i + 1;
}

void quick_sort(vector<Hocsinh>& ls, int low, int high) {
    if (low < high) {
        int pi = partition(ls, low, high);
        quick_sort(ls, low, pi - 1);
        quick_sort(ls, pi + 1, high);
    }
}

void Sort(vector<Hocsinh>& ls) {
    quick_sort(ls, 0, ls.size() - 1);
}