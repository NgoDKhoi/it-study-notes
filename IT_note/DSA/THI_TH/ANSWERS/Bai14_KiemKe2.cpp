#include <iostream>
#include <vector>

using namespace std;

bool condition(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second)
		return a.second > b.second;

	if (a.first.size() != b.first.size())
		return a.first.size() < b.first.size();

	return a.first < b.first;
}

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

int partition(vector<pair<string, int>>& res, int low, int high) {
	pair<string, int> p = res[high];
	int i = low - 1, j;

	j = low;
	while (j < high) {
		if (condition(res[j], p)) {
			++i;
			swap(res[i], res[j]);
		}

		++j;
	}

	swap(res[i + 1], res[high]);
	return i + 1;
}

void sap_xep(vector<string>& v, int low, int high) {
	if (low < high) {
		int pi = partition(v, low, high);
		sap_xep(v, low, pi - 1);
		sap_xep(v, pi + 1, high);
	}
}

void sap_xep(vector<pair<string, int>>& res, int low, int high) {
	if (low < high) {
		int pi = partition(res, low, high);
		sap_xep(res, low, pi - 1);
		sap_xep(res, pi + 1, high);
	}
}

void count(vector<string>& v, vector<pair<string, int>>& res) {
	int i = 0, n = v.size();
	while (i < n) {
		if (!i || v[i] != v[i - 1]) {
			res.push_back({ v[i], 1 });
		}
		else {
			++res[res.size() - 1].second;
		}

		++i;
	}
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

	count(v, res);

	sap_xep(res, 0, res.size() - 1);

	for (auto it : res) {
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}