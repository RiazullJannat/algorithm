#include <bits/stdc++.h>
using namespace std;
long long int n;
unordered_map<long long int, bool> dp;
bool makeIt(long long int s)
{
    if (s > n)
        return false;
    if (s == n)
        return true;
    if (dp.count(s))
        return dp[s];
    return dp[s] = makeIt(s + 3) || makeIt(s * 2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        dp.clear();
        if (makeIt(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}