#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insert(vector<bool>& ht, vector<int>& col, int k, int M) {
	int h = k % M, i;

	if (ht[h]) {
		++col[h];

		i = 1;
		while (i < M) {
			int pos = (h + i) % M;

			if (ht[pos]) {
				++col[pos];
			}
			else {
				ht[pos] = true;
				return;
			}

			++i;
		}
	}
	else {
		ht[h] = true;
	}
}

int main() {
	int n, M, i, x;

	cin >> n >> M;

	vector<bool> ht(M, false);
	vector<int> col(M, 0);

	i = 0;
	while (i < n) {
		cin >> x;
		insert(ht, col, x, M);

		++i;
	}

	int max = 0;
	for (int k : col) {
		if (k > max)
			max = k;
	}

	i = 0;
	while (i < M) {
		if (col[i] == max)
			cout << i << " ";

		++i;
	}

	return 0;
}