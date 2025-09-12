#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    vector<int> f(n);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
int main()
{
    cout << fib(5);
    return 0;
}