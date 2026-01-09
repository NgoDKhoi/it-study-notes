#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}

// Code
int partition(vector<int>& v, int low, int high) {
    int x = v[high];
    int i = low - 1, j;

    j = low;
    while (j < high) {
        if (v[j] < x) {
            ++i;
            swap(v[i], v[j]);
        }

        ++j;
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

void sap_xep(vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        sap_xep(v, low, pi - 1);
        sap_xep(v, pi + 1, high);
    }
}

void Sort(vector<int>& v) {
    vector<int> chan, le;
    
    for (int x : v) {
        if (x % 2 == 0)
            chan.push_back(x);
        else
            le.push_back(x);
    }

    sap_xep(chan, 0, chan.size() - 1);
    sap_xep(le, 0, le.size() - 1);

    v = chan;
    v.insert(v.end(), le.begin(), le.end());
}
