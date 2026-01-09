#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

int HF(int &k, int &a, int &b, int &i, int &M)
{
    return (((k % M + M) % M) + a * i + b * i * i) % M;
}

void insert(vector<int> &ht, int a, int b, int k, int &n)
{
    int i, h, M;

    i = 0;
    M = ht.size();
    h = HF(k, a, b, i, M);

    while (i < M && ht[h] != k && ht[h] != INT_MIN)
    {
        ++i;
        h = HF(k, a, b, i, M);
    }

    if (ht[h] == k || i == M)
        return;

    ht[h] = k;
    ++n;
}

int main()
{
    int m, a, b;

    while (true)
    {
        cin >> m;
        if (!m)
            break;
        cin >> a >> b;

        vector<int> ht(m, INT_MIN);
        string s;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        int key;
        int n = 0;
        while (ss >> key)
        {
            if (n == m)
                break;
            insert(ht, a, b, key, n);
        }

        int i = 0;
        while (i < m)
        {
            if (ht[i] == INT_MIN)
                cout << "None";
            else
                cout << ht[i];

            if (i != m - 1)
                cout << ", ";
            ++i;
        }

        cout << "\n";
    }

    return 0;
}