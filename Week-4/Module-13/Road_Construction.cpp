#include <bits/stdc++.h>
using namespace std;
vector<int> par(100001, -1);
vector<int> group_size(100001, 1);
int cmp, mx;
int find(int s)
{
    if (par[s] == -1)
        return s;
    int leader = find(s);
    par[s] = leader;
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
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    cmp--;
}
int main()
{
    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = INT_MIN;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }
    return 0;
}