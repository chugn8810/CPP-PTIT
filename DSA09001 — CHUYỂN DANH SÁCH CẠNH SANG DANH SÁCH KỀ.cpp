#include <bits/stdc++.h>
using namespace std;
int color[1005];
vector<int> adj[1005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
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
            cout << i << ": ";
            for (auto it : adj[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
}
