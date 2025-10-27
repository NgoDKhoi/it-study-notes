#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x,y;
};

void SapXep (int l, int r, vector <Point> &v) {
    
}

int main() {
    int n;
    cin >> n;

    vector <Point> ds_Diem(n);
    for (int i=0; i<n; i++) {
        cin >> ds_Diem[i].x >> ds_Diem[i].y;
    }

    SapXep(0,n,ds_Diem);

    for (int i=0; i<n; i++) {
        cout << ds_Diem[i].x << " " << ds_Diem[i].y;
        cout << "\n";
    }

    return 0;
}
