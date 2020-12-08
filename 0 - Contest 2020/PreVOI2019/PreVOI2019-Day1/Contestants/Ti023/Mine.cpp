#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5, MOD = 1e6+3;
int n, m;
int a[2*N];
int time_in[20], time_out[20];
int dp_trau[2005][2005];

int main()
{
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < 2*n; i++)
        cin >> a[i];

    if (n <= 10)
    {
        int ans = 0;
        for (int mask = 0; mask < (1<<2*n); mask++)
        {
            stack<int> s;
            bool ngu = 0;
            int cnt = 0;
            for (int bit = 0; bit < 2*n; bit++)
            {
                if ((mask>>bit)&1)
                {
                    if (cnt == n)
                    {
                        ngu = 1;
                        break;
                    }
                    cnt++;
                    time_in[cnt] = a[bit];
                    s.push(cnt);
                }
                else
                {
                    if (s.empty())
                    {
                        ngu = 1;
                        break;
                    }
                    time_out[s.top()] = a[bit];
                    if (time_out[s.top()] - time_in[s.top()] > m)
                    {
                        ngu = 1;
                        break;
                    }
                    s.pop();
                }
            }
            if (s.size()) ngu = 1;
            if (ngu) continue;
            ans++;
        }
        return cout << ans, 0;
    }

    if (m == 1e6)
    {
        if (n <= 2000)
        {
            dp_trau[1][1] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 && j == 1) continue;
                    dp_trau[i][j] = (dp_trau[i-1][j] + dp_trau[i][j-1]) % MOD;
                }
            }
            return cout << dp_trau[n][n], 0;
        }
        return 0;
    }
}
/*
10 10
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
/*
3 6
1 2 3 7 9 10
*/
