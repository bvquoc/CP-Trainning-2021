#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const int mod = (int)1e9+7;
int n , a[N] , b[N] , c[N] , d[N];
int f[N];
void add(int &x , const int &y)
{
    x+=y;
    if(x >= mod) x-=mod;
}
void upd(int x)
{
    for(int i=x ; i>=1 ; i-=(i&-i))
    {
        f[i]++;
    }
}
int get(int x)
{
    int res = 0;
    for(int i=x ; i<=n ; i+=(i&-i))
    {
        res+=f[i];
    }
    return res;
}
void subtask1()
{
    int res = 0;
    for(int i=1 ; i<=n ; ++i)
    {
        int tmp = get(a[i]);
        add(res , tmp);
        upd(a[i]);
    }
    cout << res;
}
void subtask2()
{
    int res = 1;
    for(int i=1 ; i<=n ; ++i)
    {
        res = (1LL*res*i)%mod;
    }
    int tmp = (1LL*n*(n-1))/2;
    res = (1LL*res*tmp)/2;
    cout << res;
}
int getSubtask()
{
    bool ok = 1;
    for(int i=1 ; i<=n ; ++i)
    {
        if(a[i] != b[i]) ok = 0;
    }
    if(ok) return 1;
    return 2;
}
void solve()
{
    cin >> n;
    for(int i=1 ; i<=n ; ++i) cin >> a[i];
    for(int i=1 ; i<=n ; ++i) cin >> b[i];
    int st = getSubtask();
    if(st == 1) subtask1();
    else subtask2();
}
int main()
{
    freopen("PERMEOW.INP" , "r" , stdin);
    freopen("PERMEOW.OUT" , "w" , stdout);
    solve();
    return 0;
}
