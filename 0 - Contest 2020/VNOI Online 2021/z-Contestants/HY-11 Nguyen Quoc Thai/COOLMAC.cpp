#include <bits/stdc++.h>
#define MAXN 100005
#define pii pair < int, int >
#define F first
#define S second

using namespace std;
int n, m;
pii p[MAXN], w[MAXN];
int a[MAXN];
void read()
{
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        int l, r;
        cin >> l >> r;
        p[i] = {l,r};
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i)
    {
        int l = a[i], r = a[i+1];
        if(l > r) swap(l,r);
        w[i] = {l,r};
    }
    w[n] = {a[n], 100000};
    sort(w+1, w+n+1);
    sort(p+1, p+m+1);
}
const int oo = 1e9+7;
int ans;
void check(int x)
{
    vector < pii > v;
    for(int i = 1; i <= m; ++i)
    {
        if((x >> i) & 1)
        {
            v.push_back(p[i]);
        }
    }
    sort(v.begin(), v.end());
    int Ln = oo, Rn = 0;
    for(int i = 1; i < n; ++i)
    {
        int l1 = w[i].F, r1 = w[i].S, l2 = w[i+1].F, r2 = w[i+1].S;
        Ln = min(Ln, l1);
        Rn = max(Rn, r1);
    }
    int l1 = w[n].F, r1 = w[n].S;
    Ln = min(Ln, l1);
    Rn = max(Rn, r1);
    int Lm = oo, Rm = 0;
    //cerr << v.size() << '\n';
    int N = v.size() - 1;
    if(N < 0) return;
    for(int i = 0; i < N; ++i)
    {
        int l1 = v[i].F, r1 = v[i].S, l2 = v[i+1].F, r2 = v[i+1].S;
        if(r1 >= l2-1)
        {
            Lm = min(l1, Lm);
            Rm = max(Rm, r1);
        }
        else
        {
            //cerr << r1 << " " << l2 << '\n';
            return;
        }
    }
    l1 = v[N].F, r1 = v[N].S;
    Lm= min(l1, Lm);
    Rm = max(Rm, r1);
    if(Ln < Lm && Rm < Rn)
    {

        return;
    }
    //cerr << Ln << " " << Rn << '\n';
    //cerr << Lm << " " << Rm << '\n';
    if(Lm <= Ln && Rn <= Rm)
    ans = min(ans, (int)v.size());
}
void sub1()
{
    ans = oo;
    for(int i = 1; i < (1 << (m+1)); ++i)
    {
        check(i);
    }
}
void out()
{
    if(ans == oo) ans = -1;
    cout << ans;
}
int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    read();
    sub1();
    out();
    return 0;
}
