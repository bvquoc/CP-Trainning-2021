#include <bits/stdc++.h>
#define task "DECOR"
#define endl '\n'
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x, i) ((x) & MASK(i))
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) &~ MASK(i))
#define int long long
#define ii pair<int,int>

using namespace std;

const int oo=1e9 + 7;

int n,m,k,a[1000000],MAX,sum = 0,l,r,pa[1000000],res,ans1,ans2,val[1000000],c[600000];

int root(int u)
{
    if (u == pa[u])
        return u;
    return pa[u] = root(pa[u]);
}

void DSU(int x,int y)
{
    int u = root(x);
    int v = root(y);
    if (u == v)
        return;
    if (val[u] > val[v])
        swap(u,v);
    val[v] += val[u];
    pa[u] = v;
    return;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>k;
    for (int i = 1;i<=n;i++)
    {
        char x;
        cin>>x;
        a[i] = x - '0';
        if (x == '1')
            val[i] = 1;
        pa[i] = i;
    }
    if (m == 0 && k == 0)
    {
        for (int i = 1;i <= n;i++)
        {
            if (a[i] == 1)
                sum++;
            else sum = 0;
            if (sum > MAX)
            {
                MAX = sum;
                r = i;
                l = r - sum + 1;
            }
        }
        cout<<l<<" "<<r;
        return 0;
    }
    for (int i = 1;i <= m;i++)
    {
        int x,y;
        cin>>x>>y;
        DSU(x,y);
    }
    for (int i = 1;i<=n;i++)
    {
        int num = 0,re = k;
        memset(c,0,sizeof c);
        for (int j = i;j<=n;j++)
        {
            c[root(j)] ++;
            if (c[root(j)] <= val[root(j)])
                num++;
            else
            {
                if (re <= 0)
                    break;
                else {re--; num++;}
            }
            if (num > res)
            {
                res = num;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout<<ans1<<" "<<ans2;
}
