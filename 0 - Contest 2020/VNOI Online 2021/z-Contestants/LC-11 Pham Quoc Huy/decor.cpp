#include <bits/stdc++.h>

using namespace std;
int n, m, k, l, r;
string s;
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    cin >> n >> m >> k >> s;
    if (m == 0)
    {
        if (k == 0)
        {
            int ans = 0, cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                    cnt++;
                else
                {
                    if (ans < cnt)
                    {
                        ans = cnt;
                        r = i;
                        l = r - ans + 1;
                    }
                    cnt = 0;
                }
                if (i == n - 1)
                    if (ans < cnt)
                    {
                        ans = cnt;
                        r = i;
                        l = r - ans + 1;
                    }
            }
            cout << l << " " << r;
            return 0;
        }
        int ans = 0, cnt = 0, bef = -1, cntk = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (cntk == k)
                {
                    if (ans < cnt)
                    {
                        ans = cnt;
                        r = i;
                        l = r - ans + 1;
                    }
                    cntk = 0;
                    cnt = 0;
                    if (bef != -1)
                    {
                        i = bef;
                        bef = -1;
                    }
                    continue;
                }
                if (cnt == 0)
                    bef = i;
                cntk++;
                cnt++;
            }
            else
                cnt++;
            if (i == n - 1)
                if (ans < cnt)
                {
                    ans = cnt;
                    r = i + 1;
                    l = r - ans + 1;
                }
        }
        cout << l << " " << r;
        return 0;
    }
    return 0;
}
