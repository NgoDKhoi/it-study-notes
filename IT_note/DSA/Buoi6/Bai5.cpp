#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, long long>> q;
    vector<long long> all;
    q.reserve(10000000);
    all.reserve(10000000);

    int a;
    long long b;

    while (cin >> a && a)
    {
        cin >> b;
        q.emplace_back(a, b);
        all.push_back(b);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int n = all.size();
    vector<int> bit(n + 1, 0);
    vector<char> present(n + 1, 0);

    auto getID = [&](long long x)
    {
        return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    };

    auto update = [&](int i)
    {
        for (; i <= n; i += i & -i)
            bit[i]++;
    };

    auto query = [&](int i)
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    };

    for (auto &e : q)
    {
        a = e.first;
        b = e.second;
        int ID = getID(b);

        if (a == 1)
        {
            if (!present[ID])
            {
                present[ID] = 1;
                update(ID);
            }
        }
        else
        {
            if (!present[ID])
                cout << 0 << '\n';
            else
                cout << query(ID) << '\n';
        }
    }

    return 0;
}