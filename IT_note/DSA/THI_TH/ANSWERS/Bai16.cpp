#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n;

	vector<bool> exist(n + 1, false);

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x <= n)
			exist[x] = true;
	}

	for (int i = 0; i <= n; i++) {
		if (!exist[i]) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}