#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, M;

    if (!(cin >> n >> M)) return 0;

    vector<bool> occupied(M, false);

    int collisions = 0;
    int key;

    for (int i = 0; i < n; i++) {
        cin >> key;
        
        int index = key % M;

        if (occupied[index]) {
            collisions++;
        } else {
            occupied[index] = true;
        }
    }

    double rate = (double)collisions / n;

    if (rate > 0.33) {
        cout << "BAD" << endl;
    } else {
        cout << "GOOD" << endl;
    }

    return 0;
}