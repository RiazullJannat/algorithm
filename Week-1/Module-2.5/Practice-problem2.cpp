#include <bits/stdc++.h>
using namespace std;
void print_at_level(int l, vector<int> adj_list[])
{
    vector<bool> visited(1005, false);
    vector<int> level(1005, -1);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    visited[0] = true;
    priority_queue<int> pq;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (int val : adj_list[top])
        {
            if (!visited[val])
            {
                visited[val] = true;
                level[val] = level[top] + 1;
                q.push(val);
                if (level[val] == l)
                    pq.push(val);
            }
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int l;
    cin >> l;
    print_at_level(l, adj_list);
    return 0;
}