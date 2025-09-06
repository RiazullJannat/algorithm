#include <bits/stdc++.h>
using namespace std;
long long int n, e;
void floyd_warshall(vector<vector<long long int>> &adj_matrix)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (adj_matrix[j][i] != LLONG_MAX && adj_matrix[i][k] != LLONG_MAX && adj_matrix[j][i] + adj_matrix[i][k] < adj_matrix[j][k])
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
}
int main()
{
    cin >> n >> e;
    vector<vector<long long int>> adj_matrix(n + 1, vector<long long int>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {
        adj_matrix[i][i] = 0;
    }
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if (adj_matrix[a][b] > c)
        {
            adj_matrix[a][b] = c;
        }
    }

    floyd_warshall(adj_matrix);

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (adj_matrix[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matrix[x][y] << endl;
    }
    return 0;
}