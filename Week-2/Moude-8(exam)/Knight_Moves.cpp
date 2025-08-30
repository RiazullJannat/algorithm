#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> knightMoves = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, 1}, {-2, -1}};
int row, col;
bool matrix[101][101];
int level[101][101];
bool valid(int r, int c)
{
    return r > -1 && r < row && c > -1 && c < col;
}
void bfs(int sr, int sc)
{
    matrix[sr][sc] = true;
    level[sr][sc] = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int parentRow = parent.first;
        int parentCol = parent.second;
        for (int i = 0; i < 8; i++)
        {
            int childRow = parentRow + knightMoves[i].first;
            int childCol = parentCol + knightMoves[i].second;
            if (valid(childRow, childCol) && !matrix[childRow][childCol])
            {
                matrix[childRow][childCol] = true;
                q.push({childRow, childCol});
                level[childRow][childCol] = level[parentRow][parentCol] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> row >> col;
        memset(matrix, false, sizeof(matrix));
        memset(level, -1, sizeof(level));
        int kr, kc, qr, qc;
        cin >> kr >> kc >> qr >> qc;
        bfs(kr, kc);
        cout << level[qr][qc] << endl;
    }
    return 0;
}