#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int m, n, maxx = 0;
        cin >> m >> n;
        vector<vector<int>> matran(m, vector<int>(n));
        vector<vector<int>> dp(m, vector<int>(n));
        for (auto &i : matran)
            for (auto &j : i)
                cin >> j;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != 0 && j != 0)
                {
                    if (matran[i][j] == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    }
                }
                else
                {
                    dp[i][j] = matran[i][j];
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxx = max(maxx, dp[i][j]);
            }
        }
        cout << maxx << endl;
    }
}
