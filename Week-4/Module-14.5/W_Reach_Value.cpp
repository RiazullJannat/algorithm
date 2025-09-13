#include <bits/stdc++.h>
using namespace std;
long long int n;
bool reachValue(long long int start)
{
    if (start > n)
        return false;
    if (start == n)
        return true;
    bool r = reachValue(start * 10);
    bool r2 = reachValue(start * 20);
    return r || r2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (reachValue(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}