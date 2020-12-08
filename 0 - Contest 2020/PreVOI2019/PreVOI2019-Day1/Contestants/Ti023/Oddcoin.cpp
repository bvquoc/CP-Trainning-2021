#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+6, INF = 1e9+9;
vector<int> coin;
int dp[N];
int q, x[55], t[55];
int max_x, max_t;

int main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    cin >> q;
    for (int i = 1; i <= 10000; i *= 10)
    {
        coin.push_back(i);
        coin.push_back(3*i);
        coin.push_back(5*i);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x[i] >> t[i];
        max_x = max(max_x,x[i]);
        max_t = max(max_t,t[i]);
    }

    if (max_x <= 1e5 && max_t <= 1e5)
    {
        for (int i = 0; i < q; i++)
        {
            coin.push_back(x[i]);
            for (int j = 1; j <= max_t; j++)
            {
                dp[j] = INF;
                for (int k = 0; k < coin.size(); k++)
                {
                    if (j < coin[k]) continue;
                    dp[j] = min(dp[j],dp[j-coin[k]]+1);
                }
            }
            cout << dp[t[i]] << '\n';
            coin.pop_back();
        }
        return 0;
    }

    if (max_x <= 5e7 && max_t <= 5e7)
    {
        for (int i = 0; i < q; i++)
        {
            if (x[i] >= 1e5 || x[i] > t[i])
            {
                int ans = 0;
                coin.push_back(x[i]);
                for (int j = coin.size()-1; j >= 0; j--)
                {
                    if (t[i] >= coin[j])
                    {
                        int num = t[i]/coin[j];
                        ans += num;
                        t[i] -= num*coin[j];
                    }
                }
                coin.pop_back();
                cout << ans << '\n';
            }
            else
            {
                int ans = INF, cnt = -1;
                for (int j = t[i]; j >= 0; j -= x[i])
                {
                    cnt++;
                    int tmp = j, sum = 0;
                    for (int k = coin.size()-1; k >= 0; k--)
                    {
                        if (tmp >= coin[k])
                        {
                            int num = tmp/coin[k];
                            sum += num;
                            tmp -= num*coin[k];
                        }
                    }
                    ans = min(ans,sum + cnt);
                }
                cout << ans << '\n';
            }
        }
    }
}
/*
1
100 59
*/
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/
