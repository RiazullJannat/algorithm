#include <bits/stdc++.h>
using namespace std;
string n;
int i;
void rec()
{
    if (i == n.size())
        return;
    cout << n[i];
    if (i != n.size() - 1)
        cout << " ";
    i++;
    rec();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        i = 0;
        rec();
        cout << endl;
    }

    return 0;
}