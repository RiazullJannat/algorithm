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
vector<long long int> dis(1001, LLONG_MAX);
int n, e;
bool bellman_ford(int src)
{
    dis[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto ed : edgeList)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
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
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
    return cycle;
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

    int src, t;

    cin >> src >> t;
    bool cycle = bellman_ford(src);

    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        for (int i = 0; i < t; i++)
        {
            int d;
            cin >> d;
            if (dis[d] == LLONG_MAX)
                cout << "Not Possible\n";
            else
                cout << dis[d] << endl;
        }
    }
    return 0;
}