#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n;
    vector<vector<int>> A (n, vector<int>(3));
    for (int i=0; i<n; i++) {
        for (int j=0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cin >> m;
    vector<vector<int>> B (m, vector<int>(3));
    for (int i=0; i<m; i++) {
        for (int j=0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (B[i][0]==A[j][0] && B[i][1]==A[j][1] && B[i][2]==A[j][2]) {

            }
        }

    }





    
    return 0;
}