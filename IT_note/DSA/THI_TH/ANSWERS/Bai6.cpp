#include <iostream>

#define MAX 10000

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

int BSearch(Hocsinh [], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}

// Code
bool check(Hocsinh x, Hocsinh y) {
    if (x.Ten != y.Ten)
        return x.Ten < y.Ten;

    if (x.Hodem != y.Hodem)
        return x.Hodem < y.Hodem;

    if (x.Nam != y.Nam)
        return x.Nam > y.Nam;

    if (x.Thang != y.Thang)
        return x.Thang > y.Thang;

    return x.Ngay > y.Ngay;
}

int BSearch (Hocsinh ds[], int n, Hocsinh hs) {
    int left = 0, right = n - 1;
    int count = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Hocsinh x = ds[mid];

        if (x.Ten == hs.Ten && x.Hodem == hs.Hodem && x.Nam == hs.Nam && x.Thang == hs.Thang && x.Ngay == hs.Ngay) {
            return count;
        }
        else if (check(hs, x)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

        ++count;
    }

    return 0;
}