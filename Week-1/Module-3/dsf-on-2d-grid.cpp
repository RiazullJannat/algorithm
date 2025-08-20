#include <bits/stdc++.h>
using namespace std;
int row, col;
char grid[105][105];
int visited[105][105];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}
void dfs(int row, int col)
{
    cout << row << " " << col << endl;
    visited[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int cRow, cCol;
        cRow = row + d[i].first;
        cCol = col + d[i].second;
        if (valid(cRow, cCol) && !visited[cRow][cCol])
            dfs(cRow, cCol);
    }
}
int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << grid[i][j];
        cout << endl;
    }
    int sRow, sCol;
    cin >> sRow >> sCol;
    dfs(sRow, sCol);
    return 0;
}