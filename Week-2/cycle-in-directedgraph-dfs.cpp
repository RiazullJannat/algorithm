#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(101, false);
vector<bool> visitedPath(101, false);
bool flag;
void dfs(int i, vector<int> adjList[])
{
    visited[i] = true;
    visitedPath[i] = true;
    for (int val : adjList[i])
    {
        if (visited[val] && visitedPath[val])
            flag = true;
        if (!visited[val])
        {
            dfs(val, adjList);
        }
    }
    visitedPath[i] = false;
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
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, adjList);
    }
    if (flag)
        cout << "Cycle detected.";
    else
        cout << "no cycle";
    return 0;
    return 0;
}