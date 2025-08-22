#include <bits/stdc++.h>
using namespace std;
int n, e;
char matrix[1001][1001];
int visited[1001][1001] = {false};
vector<int> nc;
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int r, int c)
{
    return (r > -1 && r < n && c > -1 && c < e);
}
int dfs(int row, int col)
{
    visited[row][col] = true;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int cRow, cCol;
        cRow = row + routes[i].first;
        cCol = col + routes[i].second;
        if (valid(cRow, cCol) && !visited[cRow][cCol] && matrix[cRow][cCol] == '.')
        {
            count += dfs(cRow, cCol);
        }
    }
    return count;
}
int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < e; j++)
        {
            if (!visited[i][j] && matrix[i][j] == '.')
            {
                nc.push_back(dfs(i, j));
            }
        }
    if (nc.size() == 0)
        cout << 0 << endl;
    else
    {
        sort(nc.begin(), nc.end());
        for (int val : nc)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}