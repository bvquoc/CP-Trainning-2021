#include <bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i = x; i <= y; ++i)
#define ft(i, x, y) for (int i = y; i >= x; --i)
#define pii pair <int, int>
#define getbit(x, k) ((x) & (1 << (k)))
#define flip(x, k) ((x) ^ (1 << (k)))
#define ll long long
using namespace std;
int n, m, k, lft[500010], rght[500010];
int st = 1, cnt = 0, len = 0, L, R, dem = 0, res;
pii _swap[500010];
string lit;
vector <int> edge[500010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("decor.inp", "r", stdin);
    freopen ("decor.out", "w", stdout);
    cin >> n >> m >> k >> lit;
    lit = " " + lit;
    fr (i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        _swap[i] = {u, v};
    }
}
void sub1 ()
{
    st = 1, cnt = 0, len = 0;
    fr (i, 1, n)
    {
        if (lit[i] == '1')
        {
            if (lit[i - 1] != '1') st = i;
            cnt++;
            if (len < cnt)
            {
                len = cnt;
                L = st;
                R = i;
            }
        }
        else cnt = 0;
    }
    if (len == 0) cout << -1;
    else cout << L << " " << R;
    exit(0);
}
void sub2 ()
{
    st = 1, cnt = 0, len = 0, res = 0;
    L = 1, R = min(k, n);
    fr (i, 1, n)
    {
        if (lit[i] == '1')
        {
            if (lit[i - 1] != '1')
            {
                dem++;
                st = i;
            }
            cnt++;
            lft[dem] = st;
            rght[dem] = i;
        }
        else cnt = 0;
    }
    if (dem == 0 and k == 0)
    {
        cout << -1;
        exit(0);
    }
    lft[dem + 1] = 1e9;
    fr (i, 1, dem)
    {
        int K = k;
        st = i;
        int l = 0, r = 0;
        while (K > 0 and st <= dem)
        {
            if (K >= lft[st + 1] - rght[st] - 1)
            {
                l = lft[st];
                r = rght[st + 1];
                K -= (lft[st + 1] - rght[st] - 1);
//                cerr << l << " " << r << " " << K << "\n";
                if (r - l + 1 > res)
                {
                    res = r - l + 1;
                    L = l;
                    R = r;
                }
                st++;
            }
            else
            {
                int _l = l, _r = r;
                l = l - min(_l - 1, K);
                K -= (_l - l);
                r = r + min(n - _r, K);
                K -= (r - _r);
                if (r - l + 1 > res)
                {
                    res = r - l + 1;
                    L = l;
                    R = r;
                }
                break;
            }
        }
    }
    cout << L << " " << R;
    exit(0);
}
int main ()
{
    inp();
    if (m == 0 and k == 0) sub1();
    sub2();
    return 0;
}

