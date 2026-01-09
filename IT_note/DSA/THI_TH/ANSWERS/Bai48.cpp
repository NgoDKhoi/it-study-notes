#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& ht, int k, int M) {
	int h = k % M;
	++ht[h];
}

int main() {
	int n, M, i, x;

	cin >> n >> M;

	vector<int> ht(M, 0);

	i = 0;
	while (i < n) {
		cin >> x;
		insert(ht, x, M);

		++i;
	}

	int count = 0;
	for (int k : ht) {
		if (k - 1 >= 1)
			count += k - 1;
	}

	if ((double)count / n > 0.33)
		cout << "BAD";
	else
		cout << "GOOD";

	return 0;
}