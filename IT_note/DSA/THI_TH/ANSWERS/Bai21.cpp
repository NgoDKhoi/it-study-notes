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


int SelectionSort(Hocsinh [] , int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << SelectionSort(ls, n) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

int SelectionSort(Hocsinh ls[], int n) {
    // Code
    int i, ii, count = 0;

    i = 0;
    while (i < n) {
        int min = i;
        ii = i + 1;
        while (ii < n) {
            if (ls[ii].Hoten < ls[min].Hoten)
                min = ii;

            ++ii;
        }

        if (i != min) {
            count += 2;
            swap(ls[i], ls[min]);
        }

        ++i;
    }

    return count;
}