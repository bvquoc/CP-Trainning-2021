#include<bits/stdc++.h>
using namespace std;

string s;
stack<string> st;
long n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = '@' + s;
    long res = 0;
    for (long i = 1; i <= n; i++)
    {
        if (s[i] == ')')
        {
            res++;
            string tmp = "";
            while (st.top() != "(")
            {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            long x = 1, now = 0;
            while (!st.empty() && st.top().size() == 1 && st.top()[0] >= '0' && st.top()[0] <= '9')
            {
                now += x * (int(st.top()[0]) - 48);
                x *= 10;
                st.pop();
            }
            string tmp2 = "";
            while (now--) tmp2 += tmp;
            st.push(tmp2);
            continue;
        }
        if (s[i] == ']' && s[i - 1] != '*')
        {
            res++;
            string tmp = "";
            while (st.top() != "[")
            {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            tmp.erase(0, 1);
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            tmp += tmp2;
            st.push(tmp);
            continue;
        }
        if (s[i] == ']')
        {
            res++;
            string tmp = "";
            while (st.top() != "[")
            {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            tmp.erase(tmp.size() - 1, 1);
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            tmp2.erase(0, 1);
            tmp += tmp2;
            st.push(tmp);
            continue;
        }
        string tmp = "";
        tmp.push_back(s[i]);
        st.push(tmp);
    }
    string tmp = "";
    while (!st.empty())
    {
        tmp = st.top() + tmp;
        st.pop();
    }
    cout << res << '\n' << tmp;
}
