#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

int find(vector<pair<int, int>>& v, int x, int y) {
	int n = v.size(), left = 0, right = n - 1;
	int ans = -1;

	while (left <= right) {
		int mid = (left + right) / 2;
		pair<int, int> p = v[mid];

		if (p.first == y) {
			ans = p.second;

			if (x == 1) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else if (y < p.first) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int n, q, i, x, y;
	vector<pair<int, int>> v;

	cin >> n >> q;
	i = 0;
	while (i < n) {
		cin >> x;
		v.push_back({ x, i + 1 });

		++i;
	}

	sort(v.begin(), v.end(), cmp);

	string s;
	while (q--) {
		cin >> s >> x >> y;
		cout << find(v, x, y) << "\n";
	}

	return 0;
}