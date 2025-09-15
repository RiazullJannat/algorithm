#include <bits/stdc++.h>
using namespace std;
int value[1001], weight[1001];
int dp[1001][1001];
int knapsack(int n, int w)
{
    if (n < 0 || w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n] <= w)
    {
        int opt1 = knapsack(n - 1, w - weight[n]) + value[n];
        int opt2 = knapsack(n - 1, w);
        dp[n][w] = max(opt1, opt2);
        return dp[n][w];
    }
    else
    {
        dp[n][w] = knapsack(n - 1, w);
        return dp[n][w];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= w; j++)
                dp[i][j] = -1;
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> value[i];
        cout << knapsack(n - 1, w) << endl;
    }
    return 0;
}