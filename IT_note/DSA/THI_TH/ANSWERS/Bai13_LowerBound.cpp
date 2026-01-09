#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upper_bound(vector<int>& v, int x) {
	int n = v.size(), l = 0, r = n - 1;
	int ans = -1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (v[mid] < x) {
			l = mid + 1;
		}
		else {
			ans = v[mid];
			r = mid - 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, i, x;
	vector<int> v;

	cin >> n >> q;

	i = 0;
	while (i < n) {
		cin >> x;
		v.push_back(x);

		++i;
	}

	sort(v.begin(), v.end());

	while (q--) {
		cin >> x;
		cout << upper_bound(v, x) << "\n";
	}

	return 0;
}