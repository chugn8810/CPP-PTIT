#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>
using namespace std;
const int to = 1e9;
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int maxx = 0, so = -1, check = 0;
        string s;
        vector<int> a, b;
        map<char, int> mp;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (pair<char, int> i : mp)
        {
            int tmp = (i.first - '0');
            if (i.second % 2 != 0)
                if (maxx < i.second)
                {
                    maxx = i.second;
                    so = tmp;
                }
                else if (maxx == i.second)
                {
                    so = max(so, tmp);
                }
        }
        for (auto &i : mp)
        {
            if (i.second % 2 != 0)
            {
                int tmp = (i.first - '0');
                if (i.second != maxx || (i.second == maxx && tmp != so))
                {
                    i.second = 0;
                }
            }
        }
        for (auto &i : mp)
        {
            if (i.second % 2 == 0)
            {
                int tmp = i.second / 2, tmp2 = i.first - '0';
                while (i.second != tmp)
                {
                    a.push_back(tmp2);
                    i.second--;
                }
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < a.size(); i++)
        {
            b.push_back(a[i]);
        }
        while (maxx--)
        {
            b.push_back(so);
        }
        for (int i = a.size() - 1; i >= 0; i--)
        {
            b.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] != 0)
            {
                check = 1;
                break;
            }
        }
        if (check == 1)
        {
            int l = 0, r = b.size() - 1;
            while (l <= r)
            {
                if (b[l] == 0 && b[r] == 0)
                {
                    l++, r--;
                    continue;
                }
                else
                {
                    break;
                }
            }
            for (int i = l; i <= r; i++)
            {
                cout << b[i];
            }
            cout << endl;
        }
        else
        {
            int solon = -1;
            for (int i = 0; i < s.size(); i++)
            {
                int tmp = s[i] - '0';
                solon = max(solon, tmp);
            }
            if (solon != -1 && solon != 0)
                cout << solon << endl;
        }
    }
}
