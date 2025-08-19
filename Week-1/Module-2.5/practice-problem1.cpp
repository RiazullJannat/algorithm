#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
vector<int> level(1005, -1);
void bfs(int s)
{
    vector<bool> visited(1005, false);
    level.assign(1005, -1);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int val : adj_list[top])
        {
            if (!visited[val])
            {
                q.push(val);
                level[val] = level[top] + 1;
                visited[val] = true;
            }
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

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        bfs(s);
        cout << level[d] << endl;
    }
    return 0;
}