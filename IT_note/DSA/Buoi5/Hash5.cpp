#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Phương pháp Bucket/Separate Chaining

int main() {
    int n, M;
    
    cin >> n >> M;

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    vector<long long> hashTable(M, -1);
    vector<int> collisionCount(M, 0);

    for (int key : keys) {
        int h = key % M;

        for (int i = 0; i < M; i++) {
            int temp = (h + i) % M;

            if (hashTable[temp] == -1) {
                hashTable[temp] = key;
                break;
            } 
            else {
                collisionCount[temp]++;
            }
        }
    }

    int maxCollisions = -1; // Số lần đụng độ cao nhất
    for(int c : collisionCount) {
        if(c > maxCollisions) maxCollisions = c;
    }

    bool flag = true;
    for (int i = 0; i < M; i++) {
        if (collisionCount[i] == maxCollisions) {
            cout << i << " ";
        }
            
    }
    
    return 0;
}