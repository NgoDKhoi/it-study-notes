#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void search(vector<long long> &v, long long x, int &greater, int &less)
{
    int begin, end, i;

    begin = 0;
    end = v.size() - 1;

    if (x < v[begin])
    {
        greater = v.size();
        return;
    }

    if (x > v[end])
    {
        less = v.size();
        return;
    }

    while (begin <= end)
    {
        i = (begin + end) / 2;

        if (v[i] == x)
        {
            less = i;
            greater = v.size() - 1 - i;
            return;
        }

        if (v[i] < x)
        {
            less = i + 1;
            begin = i + 1;
        }
        else
        {
            greater = v.size() - i;
            end = i - 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, i;
    long long x;
    cin >> n;
    vector<long long> v;

    i = 0;
    while (i < n)
    {
        cin >> x;
        v.push_back(x);
        ++i;
    }

    sort(v.begin(), v.end());

    cin >> m;
    i = 0;
    while (i < m)
    {
        int greater = 0, less = 0;

        cin >> x;
        search(v, x, greater, less);

        cout << less << " " << greater << "\n";
        ++i;
    }

    return 0;
}
