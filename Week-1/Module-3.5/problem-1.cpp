#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1005];
vector<bool> visited(1005, false);
int sum = 0;
void dfs(int src)
{
    if (!visited[src])
    {
        visited[src] = true;
        sum++;
        for (int val : adjList[src])
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
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int s;
    cin >> s;
    dfs(s);
    cout << sum;
    return 0;
}