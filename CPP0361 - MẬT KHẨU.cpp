#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<string> mk(m);
    map<string, int> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> mk[i];
        mp[mk[i]]++;
    }
    long long total = 0;
    for (int i = 0; i < m; i++)
    {
        set<string> xaucon;
        for (int j = 0; j < mk[i].size(); j++)
        {
            for (int k = 1; k <= mk[i].size() - j; k++)
            {
                xaucon.insert(mk[i].substr(j, k));
            }
        }
        for (auto it : xaucon)
        {
            if (mp.count(it))
            {
                total += mp[it];
            }
        }
        total -= 1;
    }
    cout << total;
}
