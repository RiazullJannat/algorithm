#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
vector<bool> visited(1005, false);
void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int top = q.front();
        cout << top << " ";
        q.pop();
        for (int val : adj_list[top])
        {
            if (!visited[val])
            {
                q.push(val);
                visited[val] = true;
            }
        }
    }
    cout << endl;
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
    bfs(0);
    return 0;
}