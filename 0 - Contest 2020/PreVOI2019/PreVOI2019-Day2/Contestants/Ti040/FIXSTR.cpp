#include <bits/stdc++.h>

using namespace std;
#define taskname "FIXSTR"

string s;
int n, m, N;
string pre[1005];

int main()
{
    if (fopen (taskname".inp", "r"))
    {
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> s;
    pre[0] = s;
    s = ' ' + s;
    cin >> m;
    {
        char ch;
        int I, J;
        while (m --> 0)
        {
            cin >> ch;
            while (!isalpha(ch))
                cin >> ch;
            cin >> I;
            if (ch == 'C')
            {
                if (s[I] == ')')
                    s[I] = '(';
                else
                    s[I] = ')';
            }
            else if (ch == 'U')
                s = pre[I - 1];
            else
            {
                cin >> J;
                int res = 0, tmp = 0;
                for (int i = I; i <= J; i++)
                    if (s[i] == '(')
                        tmp++;
                    else
                    {
                        tmp--;
                        if (tmp < 0)
                        {
                            tmp = 0;
                            res++;
                        }
                    }
                cout << res + tmp << '\n';
            }
            pre[++N] = s;
        }
    }
}
