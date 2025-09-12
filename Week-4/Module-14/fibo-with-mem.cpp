#include <bits/stdc++.h>
using namespace std;
vector<int> track(1005, -1);
int fib(int n)
{
    if (n < 2)
        return n;
    if (track[n] != -1)
        return track[n];
    track[n] = fib(n - 1) + fib(n - 2);
    return track[n];
}
int main()
{
    cout << fib(5);
    return 0;
}