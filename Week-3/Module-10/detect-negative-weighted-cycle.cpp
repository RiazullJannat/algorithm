#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = INT_MAX;
        }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (adj_matrix[j][i] != INT_MAX && adj_matrix[i][k] != INT_MAX && adj_matrix[j][i] + adj_matrix[i][k] < adj_matrix[j][k])
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
            }
        }
    }
    bool cycle = false;
    for (int i = 0; i < n; i++)
        if (adj_matrix[i][i] < 0)
            cycle = true;
    if (cycle)
        cout << "cycle detected";
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_matrix[i][j] == INT_MAX)
                    cout << "O" << " ";
                else
                    cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}