#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p = 1;
        stack<int> st;
        string s;
        cin >> s;
        st.push(p++);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                while (st.size() > 0)
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(p++);
            }
            else
            {
                st.push(p++);
            }
        }
        while (st.size() > 0)
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
