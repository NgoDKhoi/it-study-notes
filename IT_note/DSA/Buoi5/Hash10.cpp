#include <iostream>
#include <vector>
using namespace std;

int Search(int key, const vector<vector<int>> &Table, int M) {
    int h = key % M;
    int count = 0;

    for (int x : Table[h]) {
        count++;
        if (x == key)
            return count;
    }
    return -1;
}

int main() {
    int M, N;
    double LOAD;
    cin >> M >> LOAD >> N;

    vector<vector<int>> Table(M);
    int cur = 0;

    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;

        if ((cur + 1.0) / M > LOAD) continue;    

        int h = key % M;
        Table[h].push_back(key);
        cur++;
    }

    int N1;
    cin >> N1;

    while (N1--) {
        int fkey;
        cin >> fkey;
        int res = Search(fkey, Table, M);
        if (res == -1)
            cout << "KHONG\n";
        else
            cout << res << "\n";
    }

    return 0;
}
