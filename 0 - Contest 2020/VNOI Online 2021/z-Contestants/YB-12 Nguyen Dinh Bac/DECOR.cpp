#include <bits/stdc++.h>
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

const int N = 1e6+7;

int n, m, k;
ii a[N], c[N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#define TASK "DECOR"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);

    cin >> n >> m >> k;
    cin >> s;
    for(int i = 1; i <= m; i++)
        cin >> a[i].X >> a[i].Y;

    if(m == 0 && k == 0)
    {
        int res = 0, cur = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
            {
                res = max(res, cur);
                cur = 0;
            }
            else
                cur++;
        res = max(res, cur);
        cout << res;
    }
    else if(m == 0)
    {
        int L = 0, R = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                L = i;
                R = i;
                for(int j = i + 1; j < s.size(); j++)
                {
                    if(s[j] == '0')
                    {
                        R = j - 1;
                        i = j;
                        break;
                    }
                    else if(j == s.size() - 1)
                    {
                        R = j;
                        i = j;
                        break;
                    }
                }
                c[++cnt] = {L + 1, R + 1};
            }
        }
    }

    return 0;
}
