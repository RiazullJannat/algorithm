#include <bits/stdc++.h>
using namespace std;
int row, col, sr, sc, dr, dc;
char matrix[1001][1001];
int visited[1001][1001];
int level[1001][1001];
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int r, int c)
{
    return r > -1 && r < row && c > -1 && c < col;
}
void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    level[sr][sc] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int pr = parent.first;
        int pc = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cr = pr + routes[i].first;
            int cc = pc + routes[i].second;
            if (valid(cr, cc) && !visited[cr][cc] && matrix[cr][cc] != '#')
            {
                visited[cr][cc] = true;
                level[cr][cc] = level[pr][pc] + 1;
                q.push({cr, cc});
            }
        }
    }
}
int main()
{
    cin >> row >> col;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
            else if (matrix[i][j] == 'B')
            {
                dr = i;
                dc = j;
            }
        }
    }
    bfs(sr, sc);
    if (level[dr][dc] == -1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}