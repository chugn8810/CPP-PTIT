#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
long long check(long long a, long long b)
{
    while (b != 0)
    {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long m, n;
        cin >> n >> m;
        long long s = (n * (n + 1)) / 2;
        if (s >= m && (s + m) % 2 == 0)
        {
            long long a, b;
            a = (s + m) / 2;
            b = (s - m) / 2;
            if (check(a, b) == 1)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            cout << "No\n";
            continue;
        }
    }
}
