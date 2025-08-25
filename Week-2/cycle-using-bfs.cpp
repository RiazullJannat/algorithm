#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(101, false);
vector<int> parent(101, -1);
bool flag;
void bfs(int s, vector<int> adjList[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int val : adjList[top])
        {
            if (visited[val] && parent[top] != val)
                flag = true;
            if (!visited[val])
            {
                visited[val] = true;
                q.push(val);
                parent[val] = top;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adjList[101];
    flag = false;
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
            bfs(i, adjList);
    }
    if (flag)
        cout << "Cycle detected.";
    else
        cout << "no cycle";
    return 0;
}