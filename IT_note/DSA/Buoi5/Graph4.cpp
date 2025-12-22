#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void TimDuongDi(const vector<vector<int>> &graph, vector<int> &DiQua, int x)
{
    DiQua[x] = 1;
    for (int v : graph[x])
    {
        if (DiQua[v] == 0) TimDuongDi(graph, DiQua, v);
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m);
    vector<int> DiQua(m, 0);
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    TimDuongDi(graph, DiQua, 0);

    bool flag = false;
    for (int i = 1; i < m; i++) {
        if (DiQua[i]) {
            cout << i << " ";
            flag = true;
        }
    }
    if (!flag) cout << "KHONG";
}