#include <bits/stdc++.h>
using namespace std;
int row, col;
char matrix[1001][1001];
bool vis[1001][10001];
pair<int, int> par[1001][1001];
int level[1001][1001];
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int r, int c)
{
    return r > -1 && r < row && c > -1 && c < col;
}
void bfs(int sr, int sc)
{
    vis[sr][sc] = true;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    level[sr][sc] = 0;
    while (!q.empty())
    {
        auto parent = q.front();
        int parentRow = parent.first;
        int parentCol = parent.second;
        q.pop();
        for (auto route : routes)
        {
            int childRow = parentRow + route.first;
            int childCol = parentCol + route.second;
            if (valid(childRow, childCol) && !vis[childRow][childCol] && matrix[childRow][childCol] != '#')
            {
                par[childRow][childCol] = {parentRow, parentCol};
                vis[childRow][childCol] = true;
                level[childRow][childCol] = level[parentRow][parentCol] + 1;
                q.push({childRow, childCol});
            }
        }
    }
}
int main()
{
    cin >> row >> col;
    int sr, sc, dr, dc;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'R')
            {
                sr = i;
                sc = j;
            }
            else if (matrix[i][j] == 'D')
            {
                dr = i;
                dc = j;
            }
        }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(sr, sc);
    if (level[dr][dc] != -1)
    {
        pair<int, int> node = {par[dr][dc]};
        while (node != make_pair(sr, sc))
        {
            matrix[node.first][node.second] = 'X';
            node = {par[node.first][node.second]};
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j];
        cout << endl;
    }

    return 0;
}