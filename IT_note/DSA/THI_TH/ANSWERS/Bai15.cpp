#include <iostream>
#include <vector>

using namespace std;

int partition(vector<string>& v, int low, int high) {
	string s = v[high];
	int i = low - 1, j;

	j = low;
	while (j < high) {
		if (v[j] > s) {
			++i;
			swap(v[i], v[j]);
		}

		++j;
	}

	swap(v[i + 1], v[high]);
	return i + 1;
}

void sap_xep(vector<string>& v, int low, int high) {
	if (low < high) {
		int pi = partition(v, low, high);
		sap_xep(v, low, pi - 1);
		sap_xep(v, pi + 1, high);
	}
}

int count(vector<string>& v) {
	int i = 0, n = v.size(), ans = 0;
	while (i < n) {
		if (!i || v[i] != v[i - 1]) {
			++ans;
		}

		++i;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, i;
	string s;
	vector<string> v;
	vector<pair<string, int>> res;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> s;
		v.push_back(s);

		++i;
	}

	sap_xep(v, 0, n - 1);

	cout << count(v) << "\n";

	return 0;
}