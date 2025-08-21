#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
vector<bool> visited(105, false);
vector<int> nc;
int sum = 0;
void dfs(int s)
{
    visited[s] = true;
    sum++;
    for (int val : adj_list[s])
    {
        if (!visited[val])
        {
            dfs(val);
        }
    }
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
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            nc.push_back(sum);
            sum = 0;
        }
    }
    sort(nc.begin(), nc.end());
    for (int val : nc)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}