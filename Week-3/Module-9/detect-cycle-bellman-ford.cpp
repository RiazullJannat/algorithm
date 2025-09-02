#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
vector<Edge> edgeList;
int dis[1001];
int n, e;
void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edgeList)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (a != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }
    bool cycle = false;
    for (auto ed : edgeList)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (a != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "cycle detected...\n";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    bellman_ford();
    return 0;
}