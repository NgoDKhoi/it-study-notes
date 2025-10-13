#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    
    // Nhap
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    // Tinh toan
   for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool need_swap = false;
            if (x[j] > x[j + 1]) need_swap = true;
            if (x[j] == x[j + 1] && y[j] < y[j + 1]) need_swap = true;

            if (need_swap) {
                swap(x[j], x[j + 1]);
                swap(y[j], y[j + 1]);
            }
        }
    }
    
    // Xuat
    for (int i = 0; i < n; i++) {
        cout << x[i] << " " << y[i] << endl;
    }

    return 0;
}