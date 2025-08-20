#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list(1005);
vector<bool> visited(1005, false);
void dfs(int src)
{
    cout << src << " ";
    visited[src] = true;
    for (int val : adj_list[src])
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    dfs(0);

    return 0;
}