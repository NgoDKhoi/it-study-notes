#include <iostream>
#include <vector>

using namespace std;

int Search(int key, const vector<int> &Table) {
    
}

int main() {
    double M, LOAD, N ;
    cin >> M >> LOAD >> N;

    while(N/M > LOAD) N--;
    vector<int> Table(M, -1);
    for (int i=0; i<N; i++) {
        cin >> Table[i];
    }

    int N1, key;
    cin >> N1;
    vector<int> v(N1, -1);
    for (int i=0; i<N1; i++) {
        cin >> key;
        v[i]= Search(key,Table);
    }

    for (int i=0; i<N1; i++) {
        if (v[i] < 0) cout << "KHONG";
        else cout << v[i];
    }

    return 0;
}