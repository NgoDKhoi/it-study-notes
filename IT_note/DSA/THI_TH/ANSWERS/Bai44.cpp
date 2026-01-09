#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void insert(vector<vector<int>>& ht, int k, int i, int M) {
	int h = k % M;
	ht[h].push_back(k);
}

int main() {
	int n, M, i, x;

	cin >> n >> M;

	vector<vector<int>> ht(M);

	i = 0;
	while (i < n) {
		cin >> x;
		insert(ht, x, i, M);

		++i;
	}

	i = 0;
	int mn = -1;
	while (i < M) {
		int cur = ht[i].size() - 1;
		
		if (cur >= 1) {
			if (mn == -1 || cur < mn) {
				mn = cur;
			}
		}

		++i;
	}

	i = 0;
	while (i < M) {
		int cur = ht[i].size() - 1;

		if (cur == mn) {
			cout << i << " ";
		}

		++i;
	}

	return 0;
}