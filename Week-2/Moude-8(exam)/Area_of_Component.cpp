#include <bits/stdc++.h>
using namespace std;
int row, col;
char matrix[1001][1001];
bool visited[1001][1001];
void dfs(int sr,int sc)
{
    vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
}
int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (!visited[i][j])
                dfs(i, j);
        }
    return 0;
}