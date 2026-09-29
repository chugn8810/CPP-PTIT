#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    vector<vector<int>> a(t + 1, vector<int>(t + 1));
    for (int i = 1; i <= t; i++)
    {
        string s, tmp;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> tmp)
        {
            int so = stoi(tmp);
            a[i][so] = 1;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (a[i][j] == 1 && i < j)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}
