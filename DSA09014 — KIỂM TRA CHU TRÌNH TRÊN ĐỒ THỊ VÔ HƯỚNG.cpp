#include <bits/stdc++.h>
using namespace std;
bool used[1005];
vector<int> adj[1005];
bool DFS(int u, int par)
{
    used[u] = true;
    for (auto it : adj[u])
    {
        if (!used[it])
        {
            if (DFS(it, u))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < 1005; i++)
        {
            adj[i].clear();
        }
        int n, m, check = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
                if (DFS(i, 0))
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
