#include <bits/stdc++.h>
using namespace std;
int row, col;
char matrix[1001][1001];
int visited[1001][1001];
vector<pair<int, int>> routes = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int r, int c)
{
    return r > -1 && r < row && c > -1 && c < col;
}
int main() {
    
    return 0;
}