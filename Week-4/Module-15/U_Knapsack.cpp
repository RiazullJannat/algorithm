#include <bits/stdc++.h>
using namespace std;
int cost[1005], width[1005];
int dp[1005][1005];
int knapsack(int n, int maxWidth)
{
    if (n < 0 || maxWidth <= 0)
        return 0;
    if (dp[n][maxWidth] != -1)
        return dp[n][maxWidth];
    if (width[n] <= maxWidth)
    {
        int opt1 = knapsack(n - 1, maxWidth - width[n]) + cost[n];
        int opt2 = knapsack(n - 1, maxWidth);
        dp[n][maxWidth] = max(opt1, opt2);
        return dp[n][maxWidth];
    }
    else
    {
        dp[n][maxWidth] = knapsack(n - 1, maxWidth);
        return dp[n][maxWidth];
    }
}
int main()
{
    int n, maxSize;
    cin >> n >> maxSize;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= maxSize; j++)
            dp[i][j] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> width[i] >> cost[i];
    }
    cout << knapsack(n - 1, maxSize) << endl;
    return 0;
}