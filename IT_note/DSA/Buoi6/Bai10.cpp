#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long n;
    map<long long, int, greater<long long>> m;

    while (true)
    {
        cin >> n;
        if (!n)
            break;

        m[n]++;
    }

    for (auto &it : m)
    {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}