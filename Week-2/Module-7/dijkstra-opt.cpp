#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[105];
int dis[105];
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int parentNode = p.second;
        int parentDis = p.first;
        for (auto child : adjList[parentNode])
        {
            int childNode = child.second;
            int childDis = child.first;
            if (parentDis + childDis < dis[childNode])
            {
                dis[childNode] = parentDis + childDis;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    fill(dis, dis + 105, INT_MAX);
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({c, b});
        adjList[b].push_back({c, a});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}