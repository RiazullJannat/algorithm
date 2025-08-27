#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[105];
int dis[105];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    dis[src] = 0;
    q.push({src, 0});
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int par = top.first;
        int parDis = top.second;
        cout << "p->" << par << " -dis-> " << parDis << endl;
        for (auto child : adjList[par])
        {
            int childNode = child.first;
            int childDis = child.second;
            cout << "c->" << childNode << " <-of-> " << childDis << endl;
            if (parDis + childDis < dis[childNode])
            {
                dis[childNode] = parDis + childDis;
                q.push({childNode, dis[childNode]});
            }
            cout << "dis->" << dis[childNode] << endl;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }
    fill(dis, dis + 105, INT_MAX);

    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}