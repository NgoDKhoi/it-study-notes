#include <iostream>
#include <vector>
#include <map>

using namespace std;

void insert(vector<vector<int>>& ht, int k, int M) {
	int h = k % M;
	ht[h].push_back(k);
}

int find(vector<vector<int>>& ht, int k, int M) {
	int count, h;

	count = 1;
	h = k % M;
	for (int x : ht[h]) {
		if (x == k)
			return count;

		++count;
	}

	return -1;
}

int main() {
	int M, N, i, x, count;
	double LOAD;

	cin >> M >> LOAD >> N;

	vector<vector<int>> ht(M);
	map<int, int> exists;

	i = 0;
	count = 0;
	while (i < N) {
		cin >> x;

		if (!exists[x] && (double)(count + 1) / M < LOAD) {
			insert(ht, x, M);
			++exists[x];
			++count;
		}

		++i;
	}

	cin >> N;
	while (N--) {
		cin >> x;
		if (!exists[x])
			cout << "KHONG\n";
		else {
			cout << find(ht, x, M) << "\n";
		}
	}

	return 0;
}