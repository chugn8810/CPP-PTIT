#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    long long res = 0;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long luu[n + 1], vitri = 1;
    memset(luu, 0, sizeof(luu));
    for (int i = 0; i < n; i++)
    {
        luu[a[i]] = luu[a[i] - 1] + 1;
    }
    for (int i = 0; i <= n; i++)
    {
        res = max(luu[i], res);
    }
    cout << n - res << endl;
}
