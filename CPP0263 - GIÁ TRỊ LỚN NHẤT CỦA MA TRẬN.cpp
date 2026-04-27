#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<int>> matran(405, vector<int>(405));
vector<vector<int>> prefixchinh(405, vector<int>(405, 0));
vector<vector<int>> prefixphu(405, vector<int>(405, 0));
int main()
{
    int n;
    long long sum = -999999999999999999;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matran[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefixchinh[i][j] = matran[i][j] + prefixchinh[i - 1][j - 1];
            prefixphu[i][j] = matran[i][j] + prefixphu[i - 1][j + 1];
        }
    }
    for (int k = n; k >= 2; k--)
    {
        long long chinh = 0, phu = 0;
        for (int i = 1; i <= n - k + 1; i++)
        {
            for (int j = 1; j <= n - k + 1; j++)
            {
                int tmp = k - 1;
                int lc = i + tmp, rc = j + tmp, lp = i + tmp, rp = j;
                chinh = prefixchinh[lc][rc] - prefixchinh[lc - tmp - 1][rc - tmp - 1];
                phu = prefixphu[lp][rp] - prefixphu[lp - tmp - 1][rp + tmp + 1];
                sum = max(sum, chinh - phu);
            }
        }
    }
    cout << sum;
}
