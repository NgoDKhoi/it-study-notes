#include <iostream>
#include <vector>

using namespace std;

int main () {
    int nprob= 0;
    int m,n;
    cin >> m >> n;

    vector<int> table(m, -1);

    for (int i=0; i<n; i++) {
        int key;
        cin >> key;
        
        int index= key % m;
        int j= 1;
        while (table[index] != -1) {
            index= (key%m + j) % m;
            j++;
            nprob++;
        }
        table[index] = key;
    }

    cout << nprob;

    return 0;
}