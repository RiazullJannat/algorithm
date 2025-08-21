#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1005];
vector<bool> visited(1005, false);
int sum = 0;
void dfs(int src)
{
    visited[src] = true;
    for (int val : adjList[src])
        if (!visited[val])
            dfs(val);
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            sum++;
        }
    }
    cout << sum;
    return 0;
}