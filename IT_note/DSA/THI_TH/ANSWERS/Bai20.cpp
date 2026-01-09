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

void Output(vector<Hocsinh> ls, int n) {
    cout << n << endl;
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

int SelectionSort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    int n = SelectionSort(ls);
    Output(ls, n);
    return 0;
}

// Code
bool condition(Hocsinh a, Hocsinh b) {
    if (a.Ten != b.Ten)
        return a.Ten < b.Ten;

    return a.Hodem < b.Hodem;
}

int SelectionSort(vector<Hocsinh>& ls) {
    int i, ii, n = ls.size();
    int count = 0;

    i = 0;
    while (i < n) {
        int min = i;
        ii = i + 1;
        while (ii < n) {
            if (condition(ls[ii], ls[min])) {
                min = ii;
            }

            ++ii;
        }

        if (i != min) {
            ++count;
            swap(ls[i], ls[min]);
        }

        ++i;
    }

    return count;
}