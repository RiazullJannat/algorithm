#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int arr[n][e];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                arr[i][j] = 1;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        // arr[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}