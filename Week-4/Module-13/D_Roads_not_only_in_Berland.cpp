#include <bits/stdc++.h>
using namespace std;
vector<int> par(1001, -1);
vector<int> group_size(1001, 1);
int find(int s)
{
    if (par[s] == -1)
        return s;
    int leader = find(par[s]);
    par[s] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2)
        return;
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    int n;
    cin >> n;
    int e = n - 1;
    vector<pair<int, int>> rmv;
    vector<pair<int, int>> connect;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            rmv.push_back({a, b});
        else
            dsu_union(a, b);
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(1) != find(i))
        {
            connect.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << connect[i].first << " " << connect[i].second << endl;
    }
    return 0;
}