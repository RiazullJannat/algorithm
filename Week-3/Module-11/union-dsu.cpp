#include <bits/stdc++.h>
using namespace std;
int par[101];
int group_size[101];

int find(int src)
{
    if (par[src] == -1)
        return src;
    int leader = find(par[src]);
    par[src] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
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
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    dsu_union(1, 2);
    dsu_union(3, 4);
    dsu_union(2, 3);

    for (int i = 1; i < 5; i++)
    {
        cout << i << " -> " << par[i] << endl;
    }
    return 0;
}