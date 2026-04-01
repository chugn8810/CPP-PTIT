#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<long long> gt(21, 1);
void giaithua()
{
    for (long long i = 2; i <= 20; i++)
    {
        gt[i] = i * gt[i - 1];
    }
}
int main()
{
    giaithua();
    int m;
    cin >> m;
    while (m--)
    {
        int a, b, c, d;
        long long res = 0;
        cin >> a >> b >> c >> d;
        for (int i = b; i <= a; i++)
        {
            for (int j = c; j <= a - i; j++)
            {
                int k = a - i - j;
                if (k < d)
                    continue;
                long long ketqua = gt[a] / (gt[i] * gt[j] * gt[k]);
                res += ketqua;
            }
        }
        cout << res << endl;
    }
}
