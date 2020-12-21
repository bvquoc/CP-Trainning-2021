#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Forr(i, x, y) for(int i = x; i >= y; i--)
#define pb push_back
#define f first
#define s second
#define nmax 100005
using namespace std;
struct ed{
    int l, r;
};
struct cmp{
    bool operator()(ed u, ed v)
    {
        return u.r > v.r;
    }
};
int n, m, t[nmax], f[nmax], s[nmax];
vector<ed> a;
void solve()
{
    memset(s, 0, sizeof s);
    memset(f, 0, sizeof f);
    int k = 1;
    For(i, 0, m - 1)
    Forr(j, a[i].r, a[i].l)
    {
        if(s[j] == 0){
            s[j] = 1;
            if(s[j + 1] > 1)
            {
                int u = s[j+1] - 2;
                if(a[i].l > a[u].l || a[i].r < a[u].r)
                    k++;
            }
            if(j == a[i].r || j == a[i].l)
                s[j] = i + 2;
            }
    }
    For(i, t[1], 100000)
        if(s[i] == 0)
        {
            cout<<-1;
            exit(0);
        }
    cout<<k;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w", stdout);
    cin >> m;
    For(i, 1, m)
    {
        ed u;
        cin >> u.l >> u.r;
        a.pb(u);
    }
    cin >> n;
    For(i, 1, n)
        cin >> t[i];
    sort(t + 1, t + n + 1);
    sort(a.begin(), a.end(), cmp());
//    For(i, 0, m - 1)
//    cout<<a[i].l<<' '<<a[i].r<<endl;
//    For(i, 1, n)
//    cout<<t[i]<<' ';
    if(a[0].r < 100000)
    {
        cout<<-1;
        exit(0);
    }
    solve();
}
