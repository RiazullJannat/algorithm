#include <bits/stdc++.h>
using namespace std;
void floyd_warshall(vector<vector<long long int>> &adj_matrix, int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (adj_matrix[j][i] != LLONG_MAX && adj_matrix[i][k] != LLONG_MAX && adj_matrix[j][i] + adj_matrix[i][k] < adj_matrix[j][k])
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
}
int main()
{
    long long int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long int>> adj_matrix(n + 1, vector<long long int>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++)
    {
        adj_matrix[i][i] = 0;
    }

    while (m--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if (adj_matrix[a][b] > c)
        {
            adj_matrix[a][b] = c;
            adj_matrix[b][a] = c;
        }
    }

    floyd_warshall(adj_matrix, n);

    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj_matrix[s][d] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matrix[s][d] << endl;
    }
    return 0;
}