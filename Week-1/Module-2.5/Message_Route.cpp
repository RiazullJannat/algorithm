#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(1005, false);
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    return 0;
}