#include <bits/stdc++.h>
using namespace std;
char matrix[1001][1001];
bool visited[1001][1001];
int r, c;
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int row, int col)
{
    return row > -1 && row < r && col > -1 && col < c;
}
void dfs(int sr, int sc)
{
    visited[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int cr = sr + routes[i].first;
        int cc = sc + routes[i].second;
        if (valid(cr, cc) && !visited[cr][cc] && matrix[cr][cc] == '.')
            dfs(cr, cc);
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    memset(visited, false, sizeof(visited));
    dfs(sr, sc);
    if (visited[dr][dc])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}