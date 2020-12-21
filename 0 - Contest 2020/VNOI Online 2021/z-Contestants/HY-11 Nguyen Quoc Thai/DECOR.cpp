#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
#define MAXN 500005

using namespace std;
int n, m, k;
pii p[MAXN];
string s;
void read()
{
    cin >> n >> m >> k;
    cin >> s;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        p[i] = {a,b};
    }
}
int ans, l, r;
void sub1()
{
    s = " " + s;
    pii sum[MAXN];
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == '0') sum[i] = {0,0};
        else
        {
            sum[i].F = sum[i-1].F + 1;
            if(sum[i-1].S == 0) sum[i].S = i;
            else sum[i].S = sum[i-1].S;
        }
    }
    l = 0, r = 0, ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(ans < sum[i].F)
        {
            ans = sum[i].F;
            l = sum[i].S;
            r = i;
        }
    }
}
pii sum1[MAXN], sum0[MAXN];
void sub2()
{
    ans = 0;
    s = " " + s;
    for(int i = n; i >= 1; --i)
    {
        if(s[i] == '0') sum1[i] = {0,0};
        else
        {
            sum1[i].F = sum1[i+1].F + 1;
            if(sum1[i+1].S == 0) sum1[i].S = i;
            else sum1[i].S = sum1[i+1].S;
        }
    }
    for(int i = n; i >= 1; --i)
    {
        if(s[i] == '1') sum0[i] = {0,0};
        else
        {
            sum0[i].F = sum0[i+1].F + 1;
            if(sum0[i+1].S == 0) sum0[i].S = i;
            else sum0[i].S = sum0[i+1].S;
        }
    }
    for(int i = 1; i <= n; )
    {
        int K = k;
        int x = i;
        int res = 0;
        while(K && x <= n)
        {
            res += sum1[x].F;
            int X = sum1[x].S + 1;
            //cerr << "X = " << X << '\n';
            res += sum0[X].F;
            K -= sum0[X].F;
            x = sum0[X].S+1;
            //cerr << x << '\n';
        }
        if(ans < res)
        {
            ans = res;
            l = i;
            r = x-1;
        }
        i = x;
    }
}
void out()
{
    if(ans == 0) cout << -1;
    else cout << l << " " << r;
}
int main()
{
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    read();
    if(m == 0 && k == 0)sub1();
    else if(m == 0) sub2();
    out();
    return 0;
}
