#include <bits/stdc++.h>
using namespace std;
int n, e;
char adjList[105][105];
bool visited[105][105] = {false};
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int level[105][105] = {-1};
bool valid(int r, int c)
{
    return (r > -1 && r < n && c > -1 && c < e);
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    level[r][c] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        int pr = top.first;
        int pc = top.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cr = pr + routes[i].first;
            int cc = pc + routes[i].second;
            if (valid(cr, cc) && !visited[cr][cc])
            {
                visited[cr][cc] = true;
                q.push({cr, cc});
                level[cr][cc] = level[pr][pc] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < e; j++)
            cin >> adjList[i][j];
    int r, c, dr, dc;
    cin >> r >> c >> dr >> dc;
    bfs(r, c);
    cout << level[dr][dc];
    return 0;
}