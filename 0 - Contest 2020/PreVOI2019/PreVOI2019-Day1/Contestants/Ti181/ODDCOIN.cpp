#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 20
#define ll long long
#define pii pair<int, int>
#define TTT "ODDCOIN"
using namespace std;
int q;
int n, a[maxn], f[100005];
int xuli(int x, int t)
{
    int res = 2e9;
    if(t <= 1e5) res = f[t];
    a[++n] = x;
    fi(i, 1, n)
    {
        int tg = t % a[i];
        for(int j = tg; j <= min(100000, t); j += a[i])
        {
            res = min(res, f[j] + (t - j) / a[i]);
        }
    }
    n--;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    n = 15;
    a[1] = 1;
    a[2] = 3;
    a[3] = 5;
    fi(i, 4, n) a[i] = a[i - 3] * 10;
    f[0] = 0;
    fi(i, 0, 1e5)
    fi(j, 1, n)
    {
        int tg = i + a[j];
        if(tg <= 1e5)
        {
            if(f[tg] == 0) f[tg] = f[i] + 1;
            else f[tg] = min(f[tg], f[i] + 1);
        }
    }
    int x, t;
    cin >> q;
    while(q--)
    {
        cin >> x >> t;
        int res = xuli(x, t);
        int tg = t % x;
        fi(i, 1, 5)
        if(tg <= t)
        {
            res = min(res, xuli(x, tg) + (t - tg) / x);
            tg += x;
        }
        cout << res << '\n';
    }
}
