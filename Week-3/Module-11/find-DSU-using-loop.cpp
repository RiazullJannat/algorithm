#include <bits/stdc++.h>
using namespace std;
int par[101];

int find(int src)
{
    while (par[src] != -1)
    {
        src = par[src];
    }
    return src;
}
int main()
{
    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;
    cout << find(4) << endl;
    return 0;
}