#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int UpperBound(int x, vector<int> &v) {
    int ans= -1;
    int b= 0;
    int e= v.size() - 1;

    while (b <= e) {
        int m= (b+e)/2;

        if (v[m] <= x) {
            b= m + 1;
        }
        else {
            ans= v[m];
            e= m - 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int x;
    for(int i=0; i<Q; i++) {
        cin >> x;
        cout << UpperBound(x, v) << "\n";
    }

    return 0;
}