#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}


int InsertionSort(Hocsinh [] , int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << InsertionSort(ls, n) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

int InsertionSort(Hocsinh ls[], int n) {
    // Code
    int i, ii;

    i = 1;
    int count = 0;
    while (i < n) {
        Hocsinh x = ls[i];
        bool t = false;
        
        ii = i - 1;
        while (ii > -1) {
            if (ls[ii].Hoten <= x.Hoten) break;

            t = true;
            ls[ii + 1] = ls[ii];
            ++count;

            --ii;
        }

        ls[ii + 1] = x;

        ++i;
    }

    return count;
}