#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define f first
#define s second
#define nmax 100005
using namespace std;
int n, m, k;
string s;
vector<int> dske[nmax];
void sub1()
{
    int res = 0;
    int tg = 0, l, r, lt, rt;
    For(i, 1, n+1)
    {
        if(s[i] == '1')
            tg ++;
        if(s[i-1] != '1' && s[i] == '1')
            lt = i;
        if(s[i] == '0' && s[i - 1] != '0')
        {
            rt = i - 1;
            if(tg > res)
            {
                l = lt;
                r = rt;
                res = tg;
            }
            tg = 0;
        }
    }
    if(tg > res)
    {
        l = lt;
        r = rt;
        res = tg;
    }
    cout<<l<<' '<<r;
    return;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin >> n >> m >> k;
    cin >> s;
    s = '0'+s + '0';
    For(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        dske[u].pb(v);
        dske[v].pb(u);
    }
    if(m == 0 && k == 0)
        sub1();
}
