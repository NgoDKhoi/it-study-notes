#include <iostream>
#include <vector>

using namespace std;

void Merge(int l, int m, int r, vector<int> &v) {
    int n1= m - l + 1;
    int n2= r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i=0; i<n1; i++) {
        L[i]= v[l + i];
    }
    for (int i=0; i<n2; i++) {
        R[i]= v[m + 1 + i];
    }

    int i=0;
    int j=0;
    int k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

void MergeSort(int l, int r, vector<int> &v) {
    if (l>=r) return;

    int m= (l+r)/2;

    MergeSort(l, m, v);
    MergeSort(m+1, r, v);
    Merge(l, m , r, v);
}

bool BinarySearch(int x, vector<int> &v) {
    int head= 0;
    int tail= v.size()-1;

    while (head <= tail) {
        int m= (head + tail) / 2;

        if (x == v[m]) {
            return 1;
        }

        if (x > v[m]) {
            head= m + 1;
        }
        else {
            tail= m -1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Nhap
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    // Lam
    MergeSort(0, n-1, v);
    
    int x;
    for (int i=0; i<q; i++) {
        cin >> x;
        if(BinarySearch(x, v)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}

/*
x= 11
size 12
m 10
h 11
t 11
*/
