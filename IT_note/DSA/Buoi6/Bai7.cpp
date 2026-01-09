#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canTransform(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;

    string a_even, a_odd, b_even, b_odd;
    for (int i = 0; i < a.size(); ++i)
    {
        if (i % 2 == 0)
            a_even += a[i];
        else
            a_odd += a[i];
    }
    for (int i = 0; i < b.size(); ++i)
    {
        if (i % 2 == 0)
            b_even += b[i];
        else
            b_odd += b[i];
    }

    sort(a_even.begin(), a_even.end());
    sort(a_odd.begin(), a_odd.end());
    sort(b_even.begin(), b_even.end());
    sort(b_odd.begin(), b_odd.end());

    return (a_even == b_even) && (a_odd == b_odd);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (canTransform(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}