#include <iostream>
#include <vector>

using namespace std;

struct Point{
    double x, y, z;
};

bool lessThanPoints(Point A, Point B) {
    if (A.x <= B.x) {
        if (A.x == B.x) {
            if (A.y <= B.y) {
                if (A.y == B.y) {
                    if (A.z <= B.z) return 1;
                    return 0;
                }
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

bool equalPoints(Point A, Point B) {
    if (A.x == B.x && A.y == B.y && A.z == B.z) {
        return 1;
    }
    return 0;
}


int BinarySearch(Point x, vector<Point> &v) {
    int head= 0;
    int tail= v.size()-1;
    int count= 0;

    while (head <= tail) {
        count++;
        int m= (head + tail) / 2;

        if (equalPoints(x, v[m])) {
            return count;
        }

        if (lessThanPoints(x, v[m])) {
            tail= m -1;
        }
        else {
            head= m + 1;
            
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> A(n);
    for (int i=0; i<n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    
    int m;
    cin >> m;
    Point x;
    for (int i=0; i<m; i++) {
        cin >> x.x >> x.y >> x.z;
        int flag= BinarySearch(x, A);
        if(flag) {
            cout << flag;
        }
        else {
            cout << "KHONG";
        }
        cout << "\n";
    }
    return 0;
}
