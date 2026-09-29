#include <bits/stdc++.h>
using namespace std;
int color[1005];
vector<int> adj[1005];
bool DFS(int u)
{
    color[u] = 1;
    for (auto it : adj[u])
    {
        if (color[it] == 1)
            return true;
        if (color[it] == 0)
            if (DFS(it))
                return true;
    }
    color[u] = 2;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        for (int i = 0; i < 1005; i++)
        {
            adj[i].clear();
            color[i] = 0;
        }
        int n, m, check = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
                if (DFS(i))
                {
                    cout << "YES\n";
                    check = 1;
                    break;
                }
        }
        if (check != 1)
            cout << "NO\n";
    }
}
