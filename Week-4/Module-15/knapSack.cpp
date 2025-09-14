#include <bits/stdc++.h>
using namespace std;
int cost[1005], weight[1005];
int knapsack(int n, int w)
{
    if (n < 0 || w <= 0)
        return 0;
    if (weight[n] <= w)
    {
        int opt1 = knapsack(n - 1, w - weight[n]) + cost[n];
        int opt2 = knapsack(n - 1, w);
        return max(opt1, opt2);
    }
    else
    {
        return knapsack(n - 1, w);
    }
}
int main()
{
    int n, max_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> max_weight;

    cout << knapsack(n - 1, max_weight);
    return 0;
}