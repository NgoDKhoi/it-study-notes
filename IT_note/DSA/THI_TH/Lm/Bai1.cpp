#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints (Point A, Point B) {
    if (A.x <= B.x) {
        if (A.x == B.x) {
            if (A.y >= B.y) return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

void Merge(int l, int m, int r, vector<Point> &v) {
    int n1= m - l + 1;
    int n2= r - m;

    vector<Point> L(n1);
    vector<Point> R(n2);

    for (int i=0; i<n1; i++) {
        L[i]= v[l + i];
    }
    for (int i=0; i<n2; i++) {
        R[i]= v[m + 1 + i];
    }

    int i= 0;
    int j= 0;
    int k= l;
    
    while (i < n1 && j < n2) {
        if(comparePoints(L[i], R[j])) {
            v[k]= L[i];
            i++;
        }
        else {
            v[k]= R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k]= L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k]= R[j];
        j++;
        k++;
    }
}

void MergeSort(int l, int r, vector<Point> &v) {
    if (l >= r) return;

    int m= (l+r)/2;

    MergeSort(l, m, v);
    MergeSort(m+1, r, v);
    Merge(l, m, r, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Nhap vao
    int n;
    cin >> n;

    vector<Point> dsDiem(n);
    for (int i=0; i<n; i++) {
        cin >> dsDiem[i].x >> dsDiem[i].y;
    }

    // Sort
    MergeSort(0, n-1, dsDiem);

    // In ra
    for (int i=0; i<n; i++) {
        cout << dsDiem[i].x << " " << dsDiem[i].y << "\n";
    }

    return 0;
}