#include <bits/stdc++.h>
using namespace std;
bool pileOfWord(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;
    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1)
        freq1[c - 'a']++;
    for (char c : s2)
        freq2[c - 'a']++;
    return freq1 == freq2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        pileOfWord(s1, s2) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}