/*
#include <bits/stdc++.h>

using namespace std;

#define M 100005
#define N 100005
#define fi first
#define se second

int m, n, t[N], maxval = 0, l[N], r[N];
pair < int, int > a[M], c[M];
typedef pair < int, int > ii;
pair < int, ii > b[M];
bool check[M], ktra[M];

void read()
{
    cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> l[i] >> r[i];
        maxval = max(maxval, r[i]);
    }

    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> t[i];
}

int res = 0;
bool stop = false;

void xuly(int z)
{
    int p = t[z], q = 100000;
    if(q > maxval)
    {
        stop = true;
        return;
    }
    for(int i = p; i <= q; i ++)
        if(!check[i])
        {
            stop = true;
            return;
        }
    for(int i = 1; i <= m; i ++)
    {
        if(r[i] >= p || l[i] <= q)
        {
            if(l[i] <= p && q <= r[i])
            {
                if(ktra[i])
                {
                    ktra[i] = false;
                    res ++;
                }
                break;
            }
            else
            {
                if(l[i] <= p)
                {
                    b[i].fi= r[i] - p + 1;
                    b[i].se.fi = p;
                    b[i].se.se = i;
                }
                else
                {
                    if(r[i] <= q)
                    {
                        b[i].fi = r[i] - l[i] + 1;
                        b[i].se.fi = l[i];
                        b[i].se.se = i;
                    }
                    else
                    {
                        b[i].fi = q - l[i] + 1;
                        b[i].se.fi = l[i];
                        b[i].se.se = i;
                    }
                }
            }
        }
    }
    sort(b + 1, b + m + 1);
    for(int i = m; i >= 1; i --)
    {
        int x = b[i].se.fi;
        if(a[x].fi == 0)
        {
            a[x].fi = b[i].fi;
            a[x].se = b[i].se.se;
        }
    }
    for(int i = p; i <= q; i ++)
        cout << a[i].fi << " " << a[i].se << '\n';
    int i = p, j = p;
    while(i < q)
    {
        if(j != p)
            while(a[j].fi == 0)
                j --;
        if(ktra[a[j].se])
        {
            res ++;
            ktra[a[j].se] = false;
        }
        i = j + a[j].fi;
        j = i;
    }
}

void solve()
{
//    sort(a + 1, a + m + 1);
//    sort(t + 1, t + n + 1);
    fill(check + 1, check + 100000 + 1, false);
    fill(ktra + 1, ktra + 100000 + 1, true);
    for(int i = 1; i <= m; i ++)
        for(int j = l[i]; j <= r[i]; j ++)
            check[j] = true;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = t[i]; j <= 100000; j ++)
        {
            a[j].fi = 0;
            a[j].se = 0;
        }
        xuly(i);
        if(stop)
        {
            cout << -1;
            return;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COOLMAC.INP", "r", stdin);
//    freopen("COOLMAC.OUT", "w", stdout);
    read();
    solve();
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define fi first
#define se second
int n, p, q, l[N], r[N], maxval = 0, m, t[N];
bool check[N];
typedef pair < int, int > ii;
pair < int, int > a[N];
pair < int, ii > b[N];

void read()
{
    cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        cin >> l[i] >> r[i];
        maxval = max(maxval, r[i]);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> t[i];
}

bool stop = false, ktra[N];
int ans = 0;

void solve(int x)
{
    p = t[x];
    q = 100000;
    for(int i = p; i <= q; i ++)
    {
        a[i].fi = 0;
        a[i].se = 0;
    }
    if(q > maxval)
    {
        stop = true;
        return;
    }

    for(int i = p; i <= q; i ++)
        if(!check[i])
        {
            stop = true;
            return;
        }
    for(int i = 1; i <= m; i ++)
    {
        if(r[i] >= p || l[i] <= q)
        {
            if(l[i] <= p && q <= r[i])
            {
                if(ktra[i])
                {
                    ktra[i] = false;
                    ans ++;
                }
                return;
            }
            else
            {
                if(l[i] <= p)
                {
                    b[i].fi= r[i] - p + 1;
                    b[i].se.fi = p;
                    b[i].se.se = i;
                }
                else
                {
                    if(r[i] <= q)
                    {
                        b[i].fi = r[i] - l[i] + 1;
                        b[i].se.fi = l[i];
                        b[i].se.se = i;
                    }
                    else
                    {
                        b[i].fi = q - l[i] + 1;
                        b[i].se.fi = l[i];
                        b[i].se.se = i;
                    }
                }
            }
        }
    }
    sort(b + 1, b + m + 1);
    for(int i = m; i >= 1; i --)
    {
        int x = b[i].se.fi;
        if(a[x].fi == 0)
        {
            a[x].fi = b[i].fi;
            a[x].se = b[i].se.se;
        }
    }
    int i = p, j = p;
    while(i < q)
    {
        if(j != p)
            while(a[j].fi == 0)
                j --;
        if(ktra[a[j].se])
        {
            ktra[a[j].se] = false;
            ans ++;
        }
        i = j + a[j].fi;
        j = i;
    }
}

void xuly()
{
    fill(check + 1, check + 100000 + 1, false);
    fill(ktra + 1, ktra + m + 1, true);
    for(int i = 1; i <= m; i ++)
    {
        for(int j = l[i]; j <= r[i]; j ++)
        {
            check[j] = true;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        solve(i);
        if(stop)
        {
            cout << -1;
            return;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    read();
    xuly();
    return 0;
}

