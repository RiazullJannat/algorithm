#include <bits/stdc++.h>
using namespace std;
long long int tetranacci(long long int n)
{
    vector<long long int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (long long int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }
    return dp[n];
}
int main()
{
    long long int n;
    cin >> n;
    cout << tetranacci(n);
    return 0;
}