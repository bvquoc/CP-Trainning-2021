#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+7;

int n, m, k;
int A[N];

void sub2()
{
    int i = 1, j = 0, num = 0, ans = 0, li, lj;
    while(j<=n)
    {
        if(j-i+1-num>k)
        {
            num-=A[i];
            i++;
        }
        else
        {
            j++;
            num+=A[j];
        }
        if(ans<j-i+1 && j-i+1-num<=k && j<=n)
        {
            ans = j-i+1;
            li = i;
            lj = j;
        }
    }
    if(ans) cout<<li<<" "<<lj;
    else cout<<-1;
    exit(0);
}

int dsu[N], cnt[N], d[N], pa[N];

int root(int u)
{
    if(dsu[u]<0) return u;
    return dsu[u] = root(dsu[u]);
}

void ghep(int u, int v)
{
    u = root(u);
    v = root(v);
    if(u==v) return;
    if(dsu[u]>dsu[v]) swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x; A[i] = x-'0';
    }
    if(m==0) sub2();

    for(int i=1; i<=n; i++)
    {
        dsu[i] = -1;
    }

    for(int i=1; i<=m; i++)
    {
        int u, v; cin>>u>>v;
        ghep(u, v);
    }
    for(int i=1; i<=n; i++) pa[i] = root(i);
    for(int i=1; i<=n; i++)
    {
        cnt[pa[i]] += A[i];
    }

    int i = 1, j = 0, num = 0, ans = 0, li, lj;
    while(j<=n)
    {
        if(j-i+1-num>k)
        {
            d[pa[i]]--;
            if(!d[pa[i]]) num-=cnt[pa[i]];
            i++;
        }
        else
        {
            j++;
            d[pa[j]]++;
            if(d[pa[j]] == 1) num+=cnt[pa[j]];
        }
        if(ans<j-i+1 && j-i+1-num<=k && j<=n)
        {
            ans = j-i+1;
            li = i;
            lj = j;
        }
    }
    if(ans) cout<<li<<" "<<lj;
    else cout<<-1;
    return 0;
}
