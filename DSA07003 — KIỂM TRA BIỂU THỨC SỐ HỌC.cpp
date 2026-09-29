#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int total = 0;
        string s;
        getline(cin, s);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                bool check = false;
                while (!st.empty() && st.top() != '(')
                {
                    st.pop();
                    check = true;
                }
                if (!st.empty() && st.top() == '(')
                    st.pop();
                if (check != true)
                {
                    total = 1;
                    break;
                }
            }
        }
        if (total == 0)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}
