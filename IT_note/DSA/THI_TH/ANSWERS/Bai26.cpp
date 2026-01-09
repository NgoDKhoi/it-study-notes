#include <iostream>
#include <vector>

using namespace std;

void insert(int k, int& col, vector<bool>& exists, vector<int>& ht) {
	int h, i, M = ht.size();

	h = k % M;
	i = 1;
	while (exists[h] && ht[h] != k) {
		++col;
		h = (k % M + i) % M;
		++i;

		if (i > M)
			return;
	}

	if (exists[h] && ht[h] == k)
		return;

	ht[h] = k;
	exists[h] = true;
}

int main() {
	int M, n, i, x, col;

	cin >> M >> n;

	vector<bool> exists(M, false);
	vector<int> ht(M);

	i = 0;
	col = 0;
	while (i < n) {
		cin >> x;
		insert(x, col, exists, ht);

		++i;
	}

	cout << col << "\n";

	return 0;
}