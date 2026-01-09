#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct toa_do {
	double x, y, z;
};

bool check(toa_do d1, toa_do d2) {
	if (d1.x != d2.x)
		return d1.x < d2.x;

	if (d1.y != d2.y)
		return d1.y < d2.y;

	return d1.z < d2.z;
}

bool binary_search(vector<toa_do>& v, toa_do d, int& ans) {
	int N = v.size(), low = 0, high = N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (v[mid].x == d.x && v[mid].y == d.y && v[mid].z == d.z) {
			return true;
		}
		else if (check(d, v[mid])) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

		++ans;
	}

	return false;
}

int main() {
	int n, m, i;

	cin >> n;

	vector<toa_do> v;

	i = 0;
	while (i < n) {
		toa_do d;
		cin >> d.x >> d.y >> d.z;
		v.push_back(d);

		++i;
	}

	//sort(v.begin(), v.end());

	cin >> m;

	while (m--) {
		toa_do d;
		int ans = 1;
		cin >> d.x >> d.y >> d.z;
		if (binary_search(v, d, ans)) {
			cout << ans << "\n";
		}
		else {
			cout << "KHONG" << "\n";
		}
	}

	return 0;
}